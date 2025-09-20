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

Chain::Chain() {}

Chain::Chain(const std::string& chain) {
  for(int i = 0; i < chain.size(); ++i) {
    chain_.push_back(Symbol(chain[i]));
  }
}

void Chain::AddToFront(const Symbol& symbol) {
  chain_.insert(chain_.begin(), symbol);
}

void Chain::AddToBack(const Symbol& symbol) {
  chain_.push_back(symbol);
}

std::vector<Symbol> Chain::GetChain() const {
  return chain_;
}

Alphabet Chain::GetAlphabet() const {
  return alphabet_;
}

void Chain::SetAlphabet(const Alphabet& alphabet) {
  alphabet_ = alphabet;
}

int Chain::Lenght() const {
  return chain_.size();
}

Chain Chain::Inverse() const {
  Chain inverse_chain;
  for(int i = chain_.size() - 1; i >= 0; --i) {
    inverse_chain.AddToBack(chain_[i]);
  }
  return inverse_chain;
}

Language Chain::Prefixes() const {
  std::set<Chain> prefixes;
  Chain prefix;
  Chain empty_chain;

  prefixes.insert(empty_chain);  // Adding the empty chain as a prefix
  
  for(int i = 0; i < chain_.size(); ++i) {
    prefix.AddToBack(chain_[i]);
    prefixes.insert(prefix);
  }

  return Language(prefixes);
}

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



std::ostream& operator<<(std::ostream& os, const Chain& chain) {
  if (chain.chain_.empty()) {
    os << "&";  // Representing the empty chain with &
  } else {
    for(const auto& symbol : chain.chain_) {
      os << symbol;
    }
  }
  return os;
}

bool operator<(const Chain& chain1, const Chain& chain2) { // Comparing by size
  return chain1.chain_.size() < chain2.chain_.size();
}

