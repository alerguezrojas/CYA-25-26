// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 2: Cadenas y lenguajes
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo alphabet.cc: Fichero que contiene la implementación de la clase
//                      Alphabet
// Referencias:
// Historial de revisiones
//   20/09/2025 - Creacion del codigo version 1.0

#include "alphabet.h"

Alphabet::Alphabet() {}

Alphabet::Alphabet(const std::string& alphabet) {
  for(long unsigned int i = 0; i < alphabet.size(); ++i) {
    alphabet_.insert(Symbol(alphabet[i]));
  }
}

Alphabet::Alphabet(const std::set<Symbol>& alphabet) {
  alphabet_ = alphabet;
}

std::set<Symbol> Alphabet::GetAlphabet() const {
  return alphabet_;
}

void Alphabet::AddSymbol(const Symbol& symbol) {
  alphabet_.insert(symbol);
}

bool Alphabet::Contains(const Symbol& symbol) const {
  return alphabet_.find(symbol) != alphabet_.end();
}

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