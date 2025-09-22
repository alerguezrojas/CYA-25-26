// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 2: Cadenas y lenguajes
// Autor: Alejandro Rodríguez Rojas
// Correo: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo functions.cc: Implementación de funciones auxiliares
// Referencias:
// Historial de revisiones
//   23/09/2025 - Creación del código versión 1.0

#include "functions.h"

#include <iostream>
#include <sstream>

// ------------------------- Utilidades de ayuda -------------------------

void PrintUsage() {
  std::cout << "Modo de empleo: ./p02_strings [filein.txt] [fileout.txt] [opcode]\n"
            << "Pruebe './p02_strings --help' para más información.\n";
}

void PrintHelp() {
  std::cout << "Modo de empleo: ./p02_strings [filein.txt] [fileout.txt] [opcode]\n"
            << "Los Opcodes son:\n"
            << "1: Alfabeto asociado a la cadena\n"
            << "2: Longitud de la cadena\n"
            << "3: Inversa de la cadena\n"
            << "4: Prefijos de la cadena\n"
            << "5: Sufijos de la cadena\n";
}

// ------------------------- Validaciones -------------------------

bool ValidateAlphabet(const std::string& alphabet_str, int line_number) {
  if (alphabet_str.empty()) {
    std::cerr << "Error (línea " << line_number
              << "): el alfabeto no puede ser vacío.\n";
    return false;
  }
  if (alphabet_str.find('&') != std::string::npos) {
    std::cerr << "Error (línea " << line_number
              << "): el símbolo '&' no puede pertenecer al alfabeto.\n";
    return false;
  }
  return true;
}

bool ValidateChainSymbols(const Chain& chain,
                          const Alphabet& alphabet,
                          const std::string& chain_str,
                          int line_number) {
  if (chain_str == "&") return true;  // la cadena vacía siempre es válida
  for (const auto& s : chain.GetChain()) {
    if (!alphabet.Contains(s)) {
      std::cerr << "Error (línea " << line_number
                << "): la cadena contiene el símbolo '"
                << s.GetSymbol() << "' que no está en su alfabeto.\n";
      return false;
    }
  }
  return true;
}

// ------------------------- Procesado -------------------------

void ProcessValidLine(const Chain& chain,
                      const Alphabet& alphabet,
                      int opcode,
                      std::ofstream& fout) {
  switch (opcode) {
    case 1:
      fout << alphabet << "\n";
      break;
    case 2:
      fout << chain.Lenght() << "\n";
      break;
    case 3:
      fout << chain.Inverse() << "\n";
      break;
    case 4:
      fout << chain.Prefixes() << "\n";
      break;
    case 5:
      fout << chain.Suffixes() << "\n";
      break;
    default:
      // Este caso debería estar validado antes de llegar aquí
      std::cerr << "Error interno: opcode inválido.\n";
      break;
  }
}

void ProcessFile(const std::string& input_file,
                 const std::string& output_file,
                 int opcode) {
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
  int line_number = 0;

  while (std::getline(fin, line)) {
    ++line_number;
    if (line.empty()) continue;

    std::istringstream iss(line);
    std::string chain_str, alphabet_str;
    iss >> chain_str >> alphabet_str;
    if (chain_str.empty() || alphabet_str.empty()) {
      std::cerr << "Error (línea " << line_number
                << "): formato inválido. Se esperaba <cadena> <alfabeto>.\n";
      continue;
    }

    if (!ValidateAlphabet(alphabet_str, line_number)) continue;

    Alphabet alphabet(alphabet_str);
    Chain chain(chain_str);
    chain.SetAlphabet(alphabet);

    if (!ValidateChainSymbols(chain, alphabet, chain_str, line_number)) continue;

    ProcessValidLine(chain, alphabet, opcode, fout);
  }
}

// ------------------------- Argumentos -------------------------

bool ValidateArguments(int argc, char* argv[],
                       std::string& input_file,
                       std::string& output_file,
                       int& opcode) {
  if (argc == 1) {
    PrintUsage();
    return false;
  }
  if (argc == 2 &&
      (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h")) {
    PrintHelp();
    return false;
  }
  if (argc != 4) {
    PrintUsage();
    return false;
  }

  input_file = argv[1];
  output_file = argv[2];

  try {
    opcode = std::stoi(argv[3]);
  } catch (const std::exception&) {
    std::cerr << "Error: el opcode debe ser un número entero.\n";
    return false;
  }

  if (opcode < 1 || opcode > 5) {
    std::cerr << "Error: el opcode debe ser un número entre 1 y 5.\n";
    return false;
  }

  return true;
}
