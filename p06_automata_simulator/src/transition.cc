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

Transition::Transition(const State& origin_state, const Symbol& transition_symbol,
                       const State& destination_state) {
  origin_state_ = origin_state;
  transition_symbol_ = transition_symbol;
  destination_state_ = destination_state;
}

State Transition::GetOriginState() const {
  return origin_state_;
}

Symbol Transition::GetTransitionSymbol() const {
  return transition_symbol_;
}

State Transition::GetDestinationState() const {
  return destination_state_;
}

bool Transition::operator<(const Transition& other) const {
  if (origin_state_ < other.origin_state_) {
    return true;
  } else if (origin_state_ == other.origin_state_) {
    if (transition_symbol_ < other.transition_symbol_) {
      return true;
    } else if (transition_symbol_ == other.transition_symbol_) {
      return destination_state_ < other.destination_state_;
    }
  }
  return false;
}