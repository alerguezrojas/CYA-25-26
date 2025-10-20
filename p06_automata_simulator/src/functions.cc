// functions.cc
#include "functions.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <set>
#include <cctype>
#include <algorithm>

#include "alphabet.h"
#include "state.h"
#include "transition.h"

// static bool IsBlank(const std::string& s) {
//   for (char c : s)
//     if (!std::isspace(static_cast<unsigned char>(c))) return false;
//   return true;
// }

void PrintUsage(const std::string& prog) {
  std::cerr << "Modo de empleo: " << prog << " data/input.fa data/input.txt\n"
            << "Pruebe '" << prog << " --help' para más información.\n";
}

void PrintHelp(const std::string& prog) {
  std::cout
    << prog << " -- Simulador de autómatas finitos no deterministas (NFA)\n\n"
    << "Uso: " << prog << " data/input.fa data/input.txt\n\n"
    << "  input.fa  : especificación del autómata (alfabeto, estados, transiciones).\n"
    << "  input.txt : cadenas a simular (una por línea). Use '&' para cadena vacía.\n\n"
    << "Formato .fa (resumen):\n"
    << "  Línea 1: símbolos del alfabeto separados por espacios (no use '&').\n"
    << "  Línea 2: número total de estados (N).\n"
    << "  Línea 3: identificador del estado inicial.\n"
    << "  A continuación, N líneas; cada una con:\n"
    << "    <id> <es_aceptacion(0/1)> <n_trans>\n"
    << "    luego, <simbolo> <destino> repetido n_trans veces (use '&' para epsilon).\n";
}

std::optional<NFA> LoadNFAFromFile(const std::string& path, std::string& error_out) {
  std::ifstream fin(path);
  if (!fin) { error_out = "No se pudo abrir el fichero: " + path; return std::nullopt; }

  std::string line;

  // Línea 1: alfabeto
  if (!std::getline(fin, line)) { error_out = "Fichero .fa incompleto (alfabeto)."; return std::nullopt; }
  std::istringstream iss_alpha(line);
  std::string token;
  std::set<Symbol> alphabet_set;
  while (iss_alpha >> token) {
    if (token.size() != 1) { error_out = "Símbolo de alfabeto inválido: " + token; return std::nullopt; }
    if (token[0] == '&')   { error_out = "El símbolo '&' no puede formar parte del alfabeto."; return std::nullopt; }
    alphabet_set.insert(Symbol(token[0]));
  }
  Alphabet alphabet(alphabet_set);

  // Línea 2: número de estados
  if (!std::getline(fin, line)) { error_out = "Fichero .fa incompleto (número de estados)."; return std::nullopt; }
  size_t n_states;
  try { n_states = std::stoul(line); }
  catch (...) { error_out = "Número de estados inválido."; return std::nullopt; }

  // Línea 3: estado inicial
  if (!std::getline(fin, line)) { error_out = "Fichero .fa incompleto (estado inicial)."; return std::nullopt; }
  std::string start_id = line;

  struct PendingTransition { char symbol; std::string dest; };
  struct PendingState { std::string id; bool is_accept; std::vector<PendingTransition> transitions; };
  std::vector<PendingState> pending_states;

  // Leer N líneas de estados
  for (size_t i = 0; i < n_states; ++i) {
    if (!std::getline(fin, line)) { error_out = "Faltan líneas para definir todos los estados."; return std::nullopt; }
    // permitir líneas en blanco
    auto trim = [](std::string& s){ 
      auto b = s.find_first_not_of(" \t\r\n"); auto e = s.find_last_not_of(" \t\r\n");
      if (b == std::string::npos) { s.clear(); return; } s = s.substr(b, e - b + 1);
    };
    trim(line); if (line.empty()) { --i; continue; }

    std::istringstream iss(line);
    PendingState ps; int accept_flag = 0; size_t n_trans = 0;
    if (!(iss >> ps.id >> accept_flag >> n_trans)) { error_out = "Formato incorrecto en la línea del estado: " + line; return std::nullopt; }
    ps.is_accept = (accept_flag != 0);

    for (size_t j = 0; j < n_trans; ++j) {
      std::string sym, dest;
      if (!(iss >> sym >> dest)) { error_out = "Transición incompleta en la línea: " + line; return std::nullopt; }
      if (sym.size() != 1) { error_out = "Símbolo de transición inválido: " + sym; return std::nullopt; }
      char c = sym[0];
      if (c != '&' && !alphabet.Contains(Symbol(c))) { error_out = "Símbolo '" + std::string(1, c) + "' fuera del alfabeto."; return std::nullopt; }
      ps.transitions.push_back({c, dest});
    }
    pending_states.push_back(std::move(ps));
  }

  // Crear mapa id -> State (sin transiciones primero)
  std::map<std::string, State> id_to_state;
  for (const auto& ps : pending_states) {
    id_to_state.emplace(ps.id, State(ps.id, ps.id == start_id, ps.is_accept));
  }

  // Construir transiciones (por IDs) y asignarlas a cada State
  std::set<Transition> transitions;
  for (auto& ps : pending_states) {
    std::set<Transition> outgoing;
    for (const auto& tr : ps.transitions) {
      if (id_to_state.find(tr.dest) == id_to_state.end()) {
        error_out = "Transición hacia estado inexistente: " + tr.dest;
        return std::nullopt;
      }
      Transition t(ps.id, Symbol(tr.symbol), tr.dest);
      outgoing.insert(t);
      transitions.insert(t);
    }
    // actualizar el State con sus transiciones salientes
    id_to_state[ps.id] = State(ps.id, ps.id == start_id, ps.is_accept, outgoing);
  }

  // Reconstruir conjuntos de estados con los States ya actualizados
  std::set<State> all_states;
  std::set<State> accept_states;
  for (const auto& kv : id_to_state) {
    all_states.insert(kv.second);
    if (kv.second.IsAcceptState()) accept_states.insert(kv.second);
  }

  // Verificación del estado inicial
  auto it_start = id_to_state.find(start_id);
  if (it_start == id_to_state.end()) { error_out = "El estado inicial no se encuentra definido."; return std::nullopt; }
  State start_state = it_start->second;

  // Construir NFA
  NFA nfa(alphabet, all_states, start_state, accept_states, transitions);
  return nfa;
}


std::vector<std::pair<std::string, Chain>>
LoadChainsFromTxt(const std::string& path, std::string& error_out) {
  std::ifstream fin(path);
  if (!fin) {
    error_out = "No se pudo abrir el fichero: " + path;
    return {};
  }

  std::vector<std::pair<std::string, Chain>> result;
  std::string line;

  while (std::getline(fin, line)) {
    if (line.empty()) continue;

    // Eliminar espacios en blanco al inicio y final
    line.erase(0, line.find_first_not_of(" \t\r\n"));
    line.erase(line.find_last_not_of(" \t\r\n") + 1);

    if (line.empty()) continue;

    // Si la línea es solo "&", significa cadena vacía
    if (line == "&") {
      result.emplace_back("", Chain("&"));
      continue;
    }

    // Si hay un número inicial seguido de cadena (formato "1 cadena")
    std::istringstream iss(line);
    std::string first, second;
    iss >> first >> second;

    if (!second.empty() && std::all_of(first.begin(), first.end(), ::isdigit)) {
      // línea tipo "1 cadena"
      result.emplace_back(first, Chain(second));
    } else {
      // línea tipo "cadena"
      result.emplace_back("", Chain(first));
    }
  }

  return result;
}


void SimulateAndReport(const NFA& nfa,
                       const std::vector<std::pair<std::string, Chain>>& inputs) {
  for (const auto& [label, chain] : inputs) {
    bool accepted = nfa.ReadChains(chain);

    // Construir cadena legible
    std::string word;
    if (chain.GetChain().empty()) word = "&";
    else {
      for (const auto& sym : chain.GetChain()) word += sym.GetSymbol();
    }

    if (!label.empty())
      std::cout << label << " " << word << " --- " << (accepted ? "Accepted" : "Rejected") << "\n";
    else
      std::cout << word << " --- " << (accepted ? "Accepted" : "Rejected") << "\n";
  }
}
