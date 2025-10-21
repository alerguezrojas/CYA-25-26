// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo symbol.cc: Fichero que contiene la implementación de la clase Symbol
// Referencias:
// Historial de revisiones
//   18/09/2025 - Creacion del codigo version 1.0
//   19/10/2025 - Añadido operador de entrada version 1.1

#include "symbol.h"

/**
 * @brief Default constructor for Symbol class.
 */
Symbol::Symbol() {}

/**
 * @brief Constructor for Symbol class that initializes the symbol with a char.
 * @param symbol The character to initialize the symbol with.
 */
Symbol::Symbol(char symbol) {
  symbol_ = symbol;
}

/**
 * @brief Getter for the symbol character.
 * @return The character representing the symbol.
 */
char Symbol::GetSymbol() const {
  return symbol_;
}

/**
 * @brief Less-than operator for comparing two symbols.
 * @param other The other symbol to compare with.
 * @return True if this symbol is less than the other symbol, false otherwise.
 */
bool Symbol::operator<(const Symbol& other) const {
  return symbol_ < other.symbol_;
}

/**
 * @brief Equality operator for comparing two symbols.
 * @param other The other symbol to compare with.
 * @return True if both symbols are equal, false otherwise.
 */
bool Symbol::operator==(const Symbol& other) const {
  return symbol_ == other.symbol_;
}

/**
 * @brief Output stream operator for printing the symbol.
 * @param os The output stream.
 * @param symbol The symbol to print.
 * @return The output stream with the symbol appended.
 */
std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
  os << symbol.symbol_;
  return os;
}

/**
 * @brief Input stream operator for reading a symbol.
 * @param is The input stream.
 * @param symbol The symbol to read into.
 * @return The input stream.
 */
std::istream& operator>>(std::istream& is, Symbol& symbol) {
  is >> symbol.symbol_;
  return is;
}
