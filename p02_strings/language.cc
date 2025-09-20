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

Language::Language() {}

Language::Language(const std::set<Chain>& language) {
  language_ = language;
}

std::set<Chain> Language::GetLanguage() const {
  return language_;
}

std::ostream& operator<<(std::ostream& os, const Language& language) {
  os << "{ ";
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
  os << " }";
  return os;
}