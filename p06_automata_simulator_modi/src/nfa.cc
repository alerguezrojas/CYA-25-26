// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo nfa.cc: Fichero que contiene la implementación de la clase NFA
// Referencias:
// Historial de revisiones
//   19/10/2025 - Creacion del codigo version 1.0

#include "nfa.h"

/**
 * @brief Constructor for NFA class that initializes all components.
 * @param alphabet The alphabet of the NFA.
 * @param states The set of states in the NFA.
 * @param start_state The start state of the NFA.
 * @param accept_states The set of accept states in the NFA.
 * @param transitions The set of transitions in the NFA.
 */
NFA::NFA(const Alphabet& alphabet, const std::set<State>& states,
         const State& start_state, const std::set<State>& accept_states,
         const std::set<Transition>& transitions) {
  // Initialize base Automata components
  SetAlphabet(alphabet);
  SetStates(states);
  SetStartState(start_state);
  SetAcceptStates(accept_states);
  SetTransitions(transitions);
}

/**
 * @brief Finds a state by its ID.
 * @param id The ID of the state to find.
 * @return Pointer to the State if found; nullptr otherwise.
 */
const State* NFA::FindState(const std::string& id) const {
  for (const auto& s : states_) {
    if (s.GetStateId() == id) return &s;
  }
  return nullptr;
}

/**
 * @brief Calculates the ε-closure of a set of states.
 * @param state_ids The set of state IDs to compute the ε-closure for.
 * @return The ε-closure as a set of state IDs.
 */
std::set<std::string> NFA::EpsilonClosure(const std::set<std::string>& state_ids) const {
  std::set<std::string> closure = state_ids;
  std::stack<std::string> st;
  for (const auto& id : state_ids) st.push(id);

  Symbol eps('&');
  while (!st.empty()) {
    std::string sid = st.top();
    st.pop();
    const State* s = FindState(sid);
    if (!s) continue;

    auto eps_trans = s->GetTransitions(eps);
    for (const auto& t : eps_trans) {
      const std::string& dest = t.GetDestinationId();
      if (!closure.count(dest)) {
        closure.insert(dest);
        st.push(dest);
      }
    }
  }
  return closure;
}

/**
 * @brief Moves from a set of states using a given symbol.
 * @param from The set of state IDs to move from.
 * @param a The symbol to move with.
 * @return The set of destination state IDs after the move.
 */
std::set<std::string> NFA::Move(const std::set<std::string>& from, const Symbol& a) const {
  std::set<std::string> result;
  for (const auto& sid : from) {
    const State* s = FindState(sid);
    if (!s) continue;
    auto trans = s->GetTransitions(a);
    for (const auto& t : trans) {
      result.insert(t.GetDestinationId());
    }
  }
  return result;
}

/**
 * @brief Simulates reading a chain on the NFA.
 * @param chain Input chain to evaluate.
 * @return true if the chain is accepted; false if rejected.
 */
bool NFA::ReadChains(const Chain& chain) const {
  // Initial state → ε-closure({q0})
  std::set<std::string> current = { start_state_.GetStateId() };
  current = EpsilonClosure(current);

  // Process each symbol in the chain
  for (const auto& sym : chain.GetChain()) {
    if (sym.GetSymbol() == '&') continue;  // '&' not consumed
    if (!alphabet_.Contains(sym)) {
      return false;  // symbol out of alphabet → immediate rejection
    }

    // Transitions: Move + ε-closure
    auto next = Move(current, sym);
    current = EpsilonClosure(next);

    if (current.empty()) break;
  }

  // Aceptation: if any of the current states is final
  for (const auto& sid : current) {
    for (const auto& acc : accept_states_) {
      if (sid == acc.GetStateId()) {
        return true;
      }
    }
  }
  return false;
}
