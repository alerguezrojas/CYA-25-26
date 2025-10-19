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
 * @brief Punto de entrada del simulador de NFAs.
 * 
 * Uso:
 *   ./p06_automata_simulator input.fa input.txt
 * 
 * Opciones:
 *   --help   Muestra ayuda y termina.
 */
int main(int argc, char* argv[]) {
  const std::string prog = (argc > 0) ? std::string(argv[0]) : "p06_automata_simulator";

  // Ayuda
  if (argc == 2 && std::string(argv[1]) == "--help") {
    PrintHelp(prog);
    return 0;
  }

  // Comprobación de argumentos
  if (argc != 3) {
    PrintUsage(prog);
    return 1;
  }

  const std::string fa_path  = argv[1];
  const std::string txt_path = argv[2];

  // Cargar NFA desde el .fa
  std::string error;
  auto maybe_nfa = LoadNFAFromFile(fa_path, error);
  if (!maybe_nfa.has_value()) {
    std::cerr << "Error al cargar el NFA: " << error << "\n";
    return 2;
  }
  NFA nfa = std::move(maybe_nfa.value());

  // Cargar cadenas de entrada
  auto chains = LoadChainsFromTxt(txt_path, error);
  if (!error.empty()) {
    std::cerr << "Error al leer el fichero de cadenas: " << error << "\n";
    return 3;
  }

  // Simular y mostrar resultados
  SimulateAndReport(nfa, chains);
  return 0;
}
