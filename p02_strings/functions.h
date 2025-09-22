// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 2: Cadenas y lenguajes
// Autor: Alejandro Rodríguez Rojas
// Correo: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo functions.h: Declaración de funciones auxiliares
// Referencias:
// Historial de revisiones
//   23/09/2025 - Creación del código versión 1.0

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <string>
#include "alphabet.h"
#include "chain.h"
#include "language.h"
#include "symbol.h"

/**
 * @brief Functions file that contains auxiliary functions for the main program.
 *        These functions handle file processing, input validation, and operations
 */

void PrintUsage();

void PrintHelp();

bool ValidateAlphabet(const std::string& alphabet_str, int line_number);

bool ValidateChainSymbols(const Chain& chain,
                          const Alphabet& alphabet,
                          const std::string& chain_str,
                          int line_number);

void ProcessValidLine(const Chain& chain,
                      const Alphabet& alphabet,
                      int opcode,
                      std::ofstream& fout);

void ProcessFile(const std::string& input_file,
                 const std::string& output_file,
                 int opcode);

bool ValidateArguments(int argc, char* argv[],
                       std::string& input_file,
                       std::string& output_file,
                       int& opcode);

#endif  // FUNCTIONS_H

