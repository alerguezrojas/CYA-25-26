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

/**
 * @brief Prints the usage information for the program when
 *       incorrect arguments are provided.
 */
void PrintUsage() {
  std::cout << "Modo de empleo: ./p02_strings [filein.txt] [fileout.txt] [opcode]\n"
            << "Pruebe './p02_strings --help' para más información.\n";
}

/**
 * @brief Prints the help information for the program when
 *        the user requests help with --help or -h.
 */
void PrintHelp() {
  std::cout << "Modo de empleo: ./p02_strings [filein.txt] [fileout.txt] [opcode]\n"
            << "Los Opcodes son:\n"
            << "1: Alfabeto asociado a la cadena\n"
            << "2: Longitud de la cadena\n"
            << "3: Inversa de la cadena\n"
            << "4: Prefijos de la cadena\n"
            << "5: Sufijos de la cadena\n";
}

/**
 * @brief Validates the alphabet string, ensuring it is not empty
 *        and does not contain the empty symbol '&'.
 * @param alphabet_str The alphabet string to validate.
 * @param line_number The line number in the input file for error reporting.
 * @return True if the alphabet is valid; otherwise, false and an error message is printed
 */
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

/***
 * @brief Validates that each symbol in the chain belongs to the alphabet.
 * @param chain The chain to validate.
 * @param alphabet The alphabet to check against.
 * @param chain_str The original chain string for error reporting.
 * @param line_number The line number in the input file for error reporting.
 * @return True if the chain is valid; otherwise, false and an error message is printed
 */
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

/**
 * @brief Processes a validated line and writes the result based on the opcode.
 * @param chain The validated chain.
 * @param alphabet The associated alphabet.
 * @param opcode The operation code indicating which operation to perform.
 * @param fout The output file stream to write the result to.
 */
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
    case 6:
      // modi: Intersection of two languages
      {
        Language lang1 = chain.Prefixes();
        Language lang2 = chain.Suffixes();
        Language intersection = lang1.Intersection(lang2);
        fout << intersection << "\n";
      }
      break;
    default:
      // This should never happen due to prior validation
      std::cerr << "Error interno: opcode inválido.\n";
      break;
  }
}

/**
 * @brief Processes the entire file: reading, validations, and writing results.
 * @param input_file The input file name.
 * @param output_file The output file name.
 * @param opcode The operation code indicating which operation to perform.
 */
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
} // The files close automatically when their destructors are called

/**
 * @brief Validates the command line arguments:
 *       checks the number of arguments and the opcode range.
 * 
  * @param argc The argument count.
  * @param argv The argument vector.
  * @param input_file Reference to store the input file name.
  * @param output_file Reference to store the output file name.
  * @param opcode Reference to store the operation code.
  * @return True if all arguments are valid; otherwise,
  *         false and error messages are printed.
 */
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

  if (opcode < 1 || opcode > 6) {
    std::cerr << "Error: el opcode debe ser un número entre 1 y 5.\n";
    return false;
  }

  return true;
}
