// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 2: Cadenas y lenguajes
// Autor: Alejandro Rodríguez Rojas
// Correo: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo p02_strings.cc: Función main del programa cliente
// Referencias:
// Historial de revisiones
//   23/09/2025 - Creación del código versión 1.0

#include "functions.h"
#include <string>

int main(int argc, char* argv[]) {
  std::string input_file;
  std::string output_file;
  int opcode = 0;

  // 1. Validar argumentos de línea de comandos
  if (!ValidateArguments(argc, argv, input_file, output_file, opcode)) {
    return 1;  // Finaliza si hay error de argumentos o si se pidió ayuda
  }

  // 2. Procesar el fichero de entrada según el opcode
  ProcessFile(input_file, output_file, opcode);

  // 3. Fin correcto
  return 0;
}
