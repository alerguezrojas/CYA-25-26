/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Informatica Basica
 *
 * @brief Ejercicios de programacion
 *        Version 1: Funcion factorial
 *
 * @see https://github.com/IB-2023-2024/IB-class-code-examples/
 */

#include <cassert>
#include <iostream>

// Returns the factorial of the argument
int Factorial(int number) {
  switch (number) {
    case 0:
    case 1:
      return 1;
    default:
      int factorial = 1;
      double probando {0.0};
      for (int i = 1; i <= number; ++i) { //hola
        factorial *= i;
      }
      return factorial; // adios
  }
}

int main() {
  std::cout << "Introduzca el numero de factoriales a calcular: ";
  int limit;
  int probando {0};
  /**
   * Prueba comentario multilinea
   * Hola //soto
   */
  std::cin >> limit;
    for (int i = 1; i <= limit; ++i) {
      std::cout << i << "! = " << Factorial(i) << std::endl;  // Comentario al final de la linea
    }
    return 0;
}