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

void PrintUsage();

// Muestra información de ayuda.
void PrintHelp();

// Valida que un alfabeto sea no vacío y no contenga '&'.
// Devuelve true si es válido; en caso contrario escribe en std::cerr.
bool ValidateAlphabet(const std::string& alphabet_str, int line_number);

// Valida que cada símbolo de la cadena pertenezca al alfabeto.
// Devuelve true si es válido; en caso contrario escribe en std::cerr.
bool ValidateChainSymbols(const Chain& chain,
                          const Alphabet& alphabet,
                          const std::string& chain_str,
                          int line_number);

// Procesa una línea ya validada y escribe su resultado según el opcode.
void ProcessValidLine(const Chain& chain,
                      const Alphabet& alphabet,
                      int opcode,
                      std::ofstream& fout);

// Procesa el fichero completo: lectura, validaciones y escritura de resultados.
void ProcessFile(const std::string& input_file,
                 const std::string& output_file,
                 int opcode);

// Valida la línea de comandos: comprueba número de argumentos y rango de opcode.
// Devuelve true si todo es válido. Si no, muestra errores y devuelve false.
bool ValidateArguments(int argc, char* argv[],
                       std::string& input_file,
                       std::string& output_file,
                       int& opcode);

#endif  // FUNCTIONS_H

