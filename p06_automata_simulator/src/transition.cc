// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo transition.cc: Fichero que contiene la implementación de la clase Transición
// Referencias:
// Historial de revisiones
//   19/10/2025 - Creacion del codigo version 1.0

#include "transition.h"

Transition::Transition(const std::string& origin_id,
                       const Symbol& transition_symbol,
                       const std::string& destination_id)
    : origin_id_(origin_id),
      transition_symbol_(transition_symbol),
      destination_id_(destination_id) {}

std::string Transition::GetOriginId() const { return origin_id_; }
Symbol Transition::GetTransitionSymbol() const { return transition_symbol_; }
std::string Transition::GetDestinationId() const { return destination_id_; }

bool Transition::operator<(const Transition& other) const {
  if (origin_id_ != other.origin_id_) return origin_id_ < other.origin_id_;
  if (!(transition_symbol_ == other.transition_symbol_))
    return transition_symbol_ < other.transition_symbol_;
  return destination_id_ < other.destination_id_;
}
