// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 2: Cadenas y lenguajes
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo language.cc: Fichero que contiene la implementación de la clase Language
// Referencias:
// Historial de revisiones
//   20/09/2025 - Creacion del codigo version 1.0

#include "language.h"

/**
 * @brief Default constructor for Language class.
 */
Language::Language() {}

/**
 * @brief Constructor for Language class that initializes the language with a set of chains.
 * @param language The set of chains to initialize the language with.
 */
Language::Language(const std::set<Chain>& language) {
  language_ = language;
}

// modi: Intersection of two languages
Language Language::Intersection(const Language& other) const {
  std::set<Chain> intersection;
  for (const auto& chain : language_) {
    if (other.language_.find(chain) != other.language_.end()) {
      intersection.insert(chain);
    }
  }
  return Language(intersection);
}

/**
 * @brief Getter for the language set.
 * @return The set of chains representing the language.
 */
std::set<Chain> Language::GetLanguage() const {
  return language_;
}

/**
 * @brief Output stream operator for printing the language.
 * @param os The output stream.
 * @param language The language to print.
 * @return The output stream with the language appended.
 */
std::ostream& operator<<(std::ostream& os, const Language& language) {
  os << "{";
  if (language.language_.empty()) {
    os << "}";
    return os;
  }
  bool first = true;
  for(const auto& chain : language.language_) {
    if (!first) {
      os << ", ";
    }
    os << chain;
    first = false;
  }
  os << "}";
  return os;
}