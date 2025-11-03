// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 04/11/2025
// Archivo alphabet.cc: Fichero que contiene la implementación de la clase Alphabet
// Referencias:
// Historial de revisiones
//   18/09/2025 - Creacion del codigo version 1.0
//   03/11/2025 - Añadido método AddSymbol con string version y size() version 1.1

#include "alphabet.h"

/**
 * @brief Default constructor for Alphabet class.
 */
Alphabet::Alphabet() {}

/**
 * @brief Constructor for Alphabet class that initializes the alphabet with a string.
 * @param alphabet The string to initialize the alphabet with.
 */
Alphabet::Alphabet(const std::string& alphabet) {
  for(long unsigned int i = 0; i < alphabet.size(); ++i) {
    alphabet_.insert(Symbol(alphabet[i]));
  }
}

/**
 * @brief Constructor for Alphabet class that initializes the alphabet with a set of symbols.
 * @param alphabet The set of symbols to initialize the alphabet with.
 */
Alphabet::Alphabet(const std::set<Symbol>& alphabet) {
  alphabet_ = alphabet;
}

/**
 * @brief Getter for the alphabet set.
 * @return The set of symbols representing the alphabet.
 */
std::set<Symbol> Alphabet::GetAlphabet() const {
  return alphabet_;
}

/**
 * @brief Adds a symbol to the alphabet.
 * @param symbol The symbol to add.
 */
void Alphabet::AddSymbol(const Symbol& symbol) {
  alphabet_.insert(symbol);
}

/**
 * @brief Adds a symbol to the alphabet from a string.
 * @param symbol The string representing the symbol to add.
 */
void Alphabet::AddSymbol(const std::string& value) {
  for (int i = 0; i < value.size(); i++) {
    alphabet_.insert(Symbol(value[i]));
  }

  std::cout << "Alphabet: " << *this << std::endl;
}

/**
 * @brief Checks if the alphabet contains a specific symbol.
 * @param symbol The symbol to check for.
 * @return True if the symbol is in the alphabet, false otherwise.
 */
bool Alphabet::Contains(const Symbol& symbol) const {
  return alphabet_.find(symbol) != alphabet_.end();
}

/**
 * @brief Returns the size of the alphabet.
 * @return The number of symbols in the alphabet.
 */
int Alphabet::size() const {
  return alphabet_.size();
}

/**
 * @brief Output stream operator for printing the alphabet.
 * @param os The output stream.
 * @param alphabet The alphabet to print.
 * @return The output stream with the alphabet appended.
 */
std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  os << "{";
  bool first = true;
  for(const auto& symbol : alphabet.alphabet_) {
    if (!first) {
      os << ", ";
    }
    os << symbol;
    first = false;
  }
  os << "}";
  return os;
}