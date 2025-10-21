// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correo: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo p06_automata_simulator.cc: Programa principal
// Referencias:
//  - Enunciado oficial de la práctica (PDF)
//  - Google C++ Style Guide
// Historial de revisiones
//   19/10/2025 - Versión inicial

#include <iostream>
#include <string>

#include "functions.h"

/**
 * @brief Main function for the automata simulator program.
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return Exit code.
 */
int main(int argc, char* argv[]) {
  const std::string prog = (argc > 0) ? std::string(argv[0]) : "p06_automata_simulator";

  // Help option
  if (argc == 2 && std::string(argv[1]) == "--help") {
    PrintHelp(prog);
    return 0;
  }

  // Check for trace option
  bool trace_mode = false;
  int arg_offset = 0;
  
  if (argc >= 2 && std::string(argv[1]) == "--trace") {
    trace_mode = true;
    arg_offset = 1;
  }

  // Check for correct number of arguments
  if (argc != 3 + arg_offset) {
    PrintUsage(prog);
    return 1;
  }

  const std::string fa_path  = argv[1 + arg_offset];
  const std::string txt_path = argv[2 + arg_offset];

  // Load NFA from file
  std::string error;
  auto maybe_nfa = LoadNFAFromFile(fa_path, error);
  if (!maybe_nfa.has_value()) {
    std::cerr << "Error al cargar el NFA: " << error << "\n";
    return 2;
  }
  NFA nfa = std::move(maybe_nfa.value());

  // Load chains from text file
  auto chains = LoadChainsFromTxt(txt_path, error);
  if (!error.empty()) {
    std::cerr << "Error al leer el fichero de cadenas: " << error << "\n";
    return 3;
  }

  // Simulate and report results
  SimulateAndReport(nfa, chains, trace_mode);
  return 0;
}
