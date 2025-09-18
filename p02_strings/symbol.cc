// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 2: Cadenas y lenguajes
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo symbol.cc: Fichero que contiene la implementación de la clase Symbol
// Referencias:
// Historial de revisiones
//   18/09/2025 - Creacion del codigo version 1.0

#include "symbol.h"

Symbol::Symbol() {}

Symbol::Symbol(char symbol) {
  symbol_ = symbol;
}

char Symbol::GetSymbol() const {
  return symbol_;
}

bool Symbol::operator<(const Symbol& other) const {
  return symbol_ < other.symbol_;
}

bool Symbol::operator==(const Symbol& other) const {
  return symbol_ == other.symbol_;
}

std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
  os << symbol.symbol_;
  return os;
}

