// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 4: Expresiones regulares en C++
// Autor: Alejandro Rodríguez Rojas
// Correo: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo p04_code_analyzer.cc: Función main del programa cliente
// Referencias:
// Historial de revisiones
//   23/09/2025 - Creación del código versión 1.0

#include "functions.h"

int main(int argc, char* argv[]) {
  std::string input_file;
  std::string output_file;

  if (!CheckParameters(argc, argv)) {
    return 1;
  }

  input_file = argv[1];
  output_file = argv[2];

  if (!CheckFile(input_file)) {
    return 1;
  }

  MatchResult result;
  result.program_name_ = argv[0];

  ReadCode(input_file, result);

  WriteResults(output_file, result);

  PrintResults(result);

  return 0;
}

