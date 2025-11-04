// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 04/11/2025
// Archivo p8_Grammar2CNF.cc: Fichero principal del programa
// Referencias:
// Historial de revisiones
//   03/11/2025 - Creacion del codigo version 1.0

#include <iostream>
#include <string>
#include <vector>

#include "functions.h"
#include "grammar.h"

/**
 * @brief The main function of the program.
 *
 * This function is the entry point of the program. It takes command line arguments
 * and performs the following steps:
 * 1. Checks the parameters using the check_parameters function.
 * 2. Reads a grammar from a file specified by the first command line argument.
 * 3. Prints the original grammar.
 * 4. Converts the grammar to Chomsky Normal Form using the Convert2CNF function.
 * 5. Prints the grammar in Chomsky Normal Form.
 * 6. Writes the Chomsky Normal Form grammar to a file specified by the second command line argument.
 *
 * If the parameters are invalid, the program exits with a failure status.
 * If an error occurs during the execution, an error message is printed to the standard error stream.
 *
 * @param argc The number of command line arguments.
 * @param argv An  grammar.ccarray of strings containing the command line arguments.
 * @return 0 if the program executed successfully, a non-zero value otherwise.
 */
int main(int argc, char* argv[]) {
  try {
    if (check_parameters(argc, argv)) {
      Grammar grammar(argv[1]);
      std::cout << "Original Grammar: \n" << grammar << std::endl;
      Grammar cnf_grammar = grammar.Convert2CNF();
      std::cout << "\nGrammar in Chomsky Normal Form: \n" << cnf_grammar << std::endl;
      write_file(argv[2], cnf_grammar);
    } else {
      exit(EXIT_FAILURE);
    }
  } catch (std::string message) {
    std::cerr << "ERROR: " << message << std::endl;
  } catch (std::runtime_error message) {
    std::cerr << "ERROR: " << message.what() << std::endl;
  }

  return 0;
}