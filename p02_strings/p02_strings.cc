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

int main() {
  Symbol symbol1('a');
  Symbol symbol2('b');
  Symbol symbol3 = 'c';
  char char_symbol = 'd';
  Symbol symbol4(char_symbol);

  std::cout << "Symbol 1: " << symbol1 << std::endl;
  std::cout << "Symbol 2: " << symbol2 << std::endl;
  std::cout << "Symbol 3: " << symbol3 << std::endl;
  std::cout << "Symbol 4: " << symbol4 << std::endl;


  if (symbol1 < symbol2) {
    std::cout << symbol1 << " is less than " << symbol2 << std::endl;
  } else {
    std::cout << symbol1 << " is not less than " << symbol2 << std::endl;
  }

  if (symbol1 == symbol2) {
    std::cout << symbol1 << " is equal to " << symbol2 << std::endl;
  } else {
    std::cout << symbol1 << " is not equal to " << symbol2 << std::endl;
  }

  return 0;
}
