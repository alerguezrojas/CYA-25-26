// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 4: Expresiones regulares en C++
// Autor: Alejandro Rodríguez Rojas
// Correo: alu0101317038@ull.edu.es
// Fecha de entrega: 14/10/2025
// Archivo functions.cc: Implementación de funciones auxiliares (versión final)
// Referencias:
// Historial de revisiones
//   06/10/25 - Versión final ajustada al formato del enunciado

#include "functions.h"
#include <regex>
#include <filesystem>

void PrintUsage() {
  std::cout << "Modo de empleo: ./p04_code_analyzer [data/factorial.cc] [data/salida.txt]\n"
            << "Pruebe './p04_code_analyzer --help' para más información.\n";
}

void PrintHelp() {
  std::cout
      << "Modo de empleo: ./p04_code_analyzer [data/factorial.cc] [data/salida.txt]\n"
      << "Este programa analiza un código C++ utilizando expresiones regulares.\n"
      << "Detecta:\n"
      << " - Declaraciones de variables int y double.\n"
      << " - Bucles for y while.\n"
      << " - Existencia de la función main().\n"
      << " - Comentarios de una línea y de bloque (/* ... */), incluyendo la descripción inicial.\n";
}

bool CheckFile(const std::string& file_name) {
  std::ifstream file(file_name);
  if (!file) {
    std::cerr << "Error: no se pudo abrir el fichero '" << file_name << "'.\n";
    return false;
  }
  return true;
}

bool CheckParameters(int argc, char* argv[]) {
  if (argc == 1) {
    PrintUsage();
    return false;
  }
  if (argc == 2 &&
      (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h")) {
    PrintHelp();
    return false;
  }
  if (argc != 3) {
    PrintUsage();
    return false;
  }
  return true;
}

void ReadCode(const std::string& input_file, MatchResult& result) {
  std::ifstream fin(input_file);
  if (!fin) {
    std::cerr << "Error: no se pudo abrir el fichero de entrada '"
              << input_file << "'.\n";
    return;
  }

  std::string line;
  int line_number = 0;

  // Un solo Comment analiza todo tipo de comentarios (línea + bloque)
  while (std::getline(fin, line)) {
    ++line_number;
    if (line.empty()) continue;

    result.line_comment_.SearchComment(line, line_number);
    result.variable_.SearchVariable(line, line_number);
    result.loop_.SearchLoop(line, line_number);

    // Detección de función main
    if (!result.main_found_) {
      std::regex main_regex(R"(\bint\s+main\s*\()");
      if (std::regex_search(line, main_regex)) {
        result.main_found_ = true;
        result.line_number_ = line_number;
      }
    }
  }
}

void OutputResults(std::ostream& out, MatchResult& result) {
  // Obtener solo el nombre del fichero de entrada (sin ruta)
  std::string file_name = result.program_name_;
  size_t pos = file_name.find_last_of("/\\");
  if (pos != std::string::npos) file_name = file_name.substr(pos + 1);

  // === PROGRAM ===
  out << "PROGRAM: " << file_name << "\n\n";

  // === DESCRIPTION ===
  out << "DESCRIPTION:\n";
  std::string description = result.line_comment_.PrintDescription();
  if (description.empty()) {
    out << "No description found.\n\n";
  } else {
    out << description << "\n";
  }

  // === VARIABLES ===
  out << "VARIABLES:\n";
  out << result.variable_ << "\n";

  // === STATEMENTS ===
  out << "STATEMENTS:\n";
  out << result.loop_ << "\n";

  // === MAIN ===
  out << "MAIN:\n";
  out << (result.main_found_ ? "True" : "False") << "\n\n";

  // === COMMENTS ===
  out << "COMMENTS:\n";
  out << result.line_comment_;
}

void PrintResults(const MatchResult& result) {
  OutputResults(std::cout, const_cast<MatchResult&>(result));
}

void WriteResults(const std::string& output_file, const MatchResult& result) {
  std::ofstream fout(output_file);
  if (!fout) {
    std::cerr << "Error: no se pudo abrir el fichero de salida '"
              << output_file << "'.\n";
    return;
  }
  OutputResults(fout, const_cast<MatchResult&>(result));
}
