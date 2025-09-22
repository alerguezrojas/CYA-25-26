// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 2: Cadenas y lenguajes
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo chain.cc: Fichero que contiene la implementación de la clase Chain
// Referencias:
// Historial de revisiones
//   20/09/2025 - Creacion del codigo version 1.0

#include "chain.h"
#include "language.h"

/**
 * @brief Default constructor for Chain class.
 */
Chain::Chain() {}

/**
 * @brief Constructor for Chain class that initializes the chain with a string.
 * @param chain The string to initialize the chain with.
 */
Chain::Chain(const std::string& chain) {
  if (chain == "&") { // Empty chain
    return;
  }
  for(long unsigned int i = 0; i < chain.size(); ++i) {
    chain_.push_back(Symbol(chain[i]));
  }
}

/**
 * @brief Adds a symbol to the front of the chain.
 * @param symbol The symbol to add.
 */
void Chain::AddToFront(const Symbol& symbol) {
  chain_.insert(chain_.begin(), symbol);
}
/**
 * @brief Adds a symbol to the back of the chain.
 * @param symbol The symbol to add.
 */
void Chain::AddToBack(const Symbol& symbol) {
  chain_.push_back(symbol);
}

/**
 * @brief Getter for the chain vector.
 * @return The vector of symbols representing the chain.
 */
std::vector<Symbol> Chain::GetChain() const {
  return chain_;
}

/**
 * @brief Getter for the alphabet associated with the chain.
 * @return The alphabet of the chain.
 */
Alphabet Chain::GetAlphabet() const {
  return alphabet_;
}

/**
 * @brief Setter for the alphabet associated with the chain.
 * @param alphabet The alphabet to set.
 */
void Chain::SetAlphabet(const Alphabet& alphabet) {
  alphabet_ = alphabet;
}

/**
 * @brief Returns the length of the chain.
 */
int Chain::Lenght() const {
  return chain_.size();
}

/**
 * @brief Returns the inverse of the chain.
 * @return A new Chain object that is the inverse of the current chain.
 */
Chain Chain::Inverse() const {
  Chain inverse_chain;
  for(int i = chain_.size() - 1; i >= 0; --i) {
    inverse_chain.AddToBack(chain_[i]);
  }
  return inverse_chain;
}
/**
 * @brief Returns the set of prefixes of the chain as a Language object.
 * @return A Language object containing all prefixes of the chain.
 */
Language Chain::Prefixes() const {
  std::set<Chain> prefixes;
  Chain prefix;
  Chain empty_chain;

  prefixes.insert(empty_chain);  // Adding the empty chain as a prefix
  
  for(long unsigned int i = 0; i < chain_.size(); ++i) {
    prefix.AddToBack(chain_[i]);
    prefixes.insert(prefix);
  }

  return Language(prefixes);
}

/**
 * @brief Returns the set of suffixes of the chain as a Language object.
 * @return A Language object containing all suffixes of the chain.
 */
Language Chain::Suffixes() const {
  std::set<Chain> suffixes;
  Chain suffix;
  Chain empty_chain;

  suffixes.insert(empty_chain);  // Adding the empty chain as a suffix
  
  for(int i = chain_.size() - 1; i >= 0; i--) {
    suffix.AddToFront(chain_[i]);
    suffixes.insert(suffix);
  }

  return Language(suffixes);
}

/**
 * @brief Output stream operator for printing the chain.
 * @param os The output stream.
 * @param chain The chain to print.
 * @return The output stream with the chain appended.
 */
std::ostream& operator<<(std::ostream& os, const Chain& chain) {
  if (chain.chain_.empty()) {
    os << "&";
  } else {
    for (const auto& symbol : chain.chain_) {
    os << symbol;
    }
  }
  return os;  
}

/**
 * @brief Less-than operator for comparing two chains by their size.
 * @param chain1 The first chain to compare.
 * @param chain2 The second chain to compare.
 * @return True if the first chain is less than the second chain, false otherwise.
 */
bool operator<(const Chain& chain1, const Chain& chain2) { // Comparing by size
  return chain1.chain_.size() < chain2.chain_.size();
}

