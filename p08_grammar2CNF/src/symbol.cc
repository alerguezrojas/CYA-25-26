// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 04/11/2025
// Archivo symbol.cc: Fichero que contiene la implementación de la clase Symbol
// Referencias:
// Historial de revisiones
//   18/09/2025 - Creacion del codigo version 1.0
//   19/10/2025 - Añadido operador de entrada version 1.1
//   03/11/2025 - Añadido operador de igualdad con string version 1.2

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
 * @brief Constructor for Symbol class that initializes the symbol with a string.
 * @param symbol The string to initialize the symbol with.
 */
Symbol::Symbol(const std::string& symbol) {
  if (!symbol.empty()) {
    symbol_ = symbol[0];
  } else {
    symbol_ = '\0'; // Default to null character if string is empty
  }
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
 * @brief Inequality operator for comparing two symbols.
 * @param other The other symbol to compare with.
 * @return True if both symbols are not equal, false otherwise.
 */
bool Symbol::operator!=(const Symbol& other) const {
  return !(*this == other);
}

/**
 * @brief Converts the symbol to a string representation.
 * @return The string representation of the symbol.
 */
std::string Symbol::ToString() const {
  return std::string(1, symbol_);
}

/**
 * @brief Equality operator for comparing a string with a symbol.
 * @param other The string to compare with.
 * @param symbol The symbol to compare with.
 * @return True if the string representation of the symbol is equal to the string, false otherwise
 */
bool operator==(const std::string& other, const Symbol& symbol) {
  return symbol == other[0];
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
