// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 2: Cadenas y lenguajes
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo p02_strings.cc: Fichero que contiene la función main del programa
// Referencias:
// Historial de revisiones
//   18/09/2025 - Creacion del codigo version 1.0

#include <iostream>
#include "symbol.h"
#include "alphabet.h"
#include "chain.h"
#include "language.h"
#include "functions.h"

int main(int argc, char* argv[]) {
  if (argc == 1) {
    PrintUsage();
    return 0;
  }
  if (argc == 2 && std::string(argv[1]) == "--help") {
    PrintHelp();
    return 0;
  }
  if (argc != 4) {
    PrintUsage();
    return 1;
  }

  const std::string input_file = argv[1];
  const std::string output_file = argv[2];
  const int opcode = std::stoi(argv[3]);

  if (opcode < 1 || opcode > 5) {
    std::cerr << "Error: el opcode debe ser un número entre 1 y 5.\n";
    return 1;
  }

  ProcessFile(input_file, output_file, opcode);
  return 0;
}