// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo language.cc: Fichero que contiene la implementación de la clase Language
// Referencias:
// Historial de revisiones
//   20/09/2025 - Creacion del codigo version 1.0
//   19/10/2025 - Añadido setter para el lenguaje version 1.1

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

/**
 * @brief Getter for the language set.
 * @return The set of chains representing the language.
 */
std::set<Chain> Language::GetLanguage() const {
  return language_;
}

/**
 * @brief Setter for the language set.
 * @param language The set of chains to set as the language.
 */
void Language::SetLanguage(const std::set<Chain>& language) {
  language_ = language;
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