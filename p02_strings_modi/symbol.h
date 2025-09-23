// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 2: Cadenas y lenguajes
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo symbol.h: Fichero que contiene la definición de la clase Symbol
// Referencias:
// Historial de revisiones
//   18/09/2025 - Creacion del codigo version 1.0

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>

/**
 * @brief Class that represents a symbol.
 */

class Symbol {
  public:
    Symbol();
    Symbol(char symbol);
    char GetSymbol() const;
    bool operator<(const Symbol& other) const;
    bool operator==(const Symbol& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol);

  private:
    char symbol_;
};

#endif  // SYMBOL_H