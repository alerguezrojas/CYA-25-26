// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 2: Cadenas y lenguajes
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo functions.cc : Fichero que contiene las funciones auxiliares
// Referencias:
// Historial de revisiones
//   21/09/2025 - Creacion del codigo version 1.0

#include "functions.h"

void PrintUsage() {
  std::cout << "Modo de empleo: ./p02_strings [filein.txt] [fileout.txt] [opcode]" << std::endl;
  std::cout << "Pruebe ’./p02_strings --help’ para más información." << std::endl;
}

void PrintHelp() {
  std::cout << "Modo de empleo: ./p02_strings [filein.txt] [fileout.txt] [opcode]" << std::endl;
  std::cout << "Los Opcodes son:" << std::endl;
  std::cout << "1: Alfabeto asociado a la cadena" << std::endl;
  std::cout << "2: Longitud de la cadena" << std::endl;
  std::cout << "3: Inversa de la cadena" << std::endl;
  std::cout << "4: Prefijos de la cadena" << std::endl;
  std::cout << "5: Sufijos de la cadena" << std::endl;
}

void ProcessFile(const std::string& input_file, const std::string& output_file, int opcode) {
  std::ifstream fin(input_file);
  if (!fin) {
    std::cerr << "Error: no se pudo abrir el fichero de entrada '"
              << input_file << "'.\n";
    return;
  }
  std::ofstream fout(output_file);
  if (!fout) {
    std::cerr << "Error: no se pudo abrir el fichero de salida '"
              << output_file << "'.\n";
    return;
  }

  std::string line;

  while (std::getline(fin, line)) {
    if (line.empty()) continue;
    std::istringstream iss(line);
    std::string chain_str, alphabet_str;

    iss >> chain_str >> alphabet_str;
    if (chain_str.empty() || alphabet_str.empty()) continue;

    Alphabet A(alphabet_str);
    Chain C(chain_str);
    C.SetAlphabet(A);

    switch (opcode) {
      case 1:
        fout << A << "\n";
        break;
      case 2:
        fout << C.Lenght() << "\n";
        break;
      case 3:
        fout << C.Inverse() << "\n";
        break;
      case 4:
        fout << C.Prefixes() << "\n";
        break;
      case 5:
        fout << C.Suffixes() << "\n";
        break;
      default:
        std::cerr << "Error: opcode inválido. Use 1..5.\n";
        return;
    }
  }
}


