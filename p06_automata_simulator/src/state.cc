// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo state.cc: Fichero que contiene la implementación de la clase Estado
// Referencias:
// Historial de revisiones
//   19/10/2025 - Creacion del codigo version 1.0

#include "state.h"
#include "transition.h"

State::State() {
  state_id_ = "";
  start_state_ = false;
  accept_state_ = false;
  transitions_number_ = 0;
}

State::State(const std::string& state_id, bool start_state, bool accept_state) {
  state_id_ = state_id;
  start_state_ = start_state;
  accept_state_ = accept_state;
  transitions_number_ = 0;
}

State::State(const std::string& state_id, bool start_state, bool accept_state,
             std::set<Transition> transitions) {
  state_id_ = state_id;
  start_state_ = start_state;
  accept_state_ = accept_state;
  transitions_ = transitions;
  transitions_number_ = transitions.size();
}

bool State::IsStartState() const {
  return start_state_;
}

bool State::IsAcceptState() const {
  return accept_state_;
}

std::string State::GetStateId() const {
  return state_id_;
}

std::set<Transition> State::GetTransitions(Symbol symbol) const {
  std::set<Transition> result;
  for (const auto& t : transitions_) {
    if (t.GetTransitionSymbol() == symbol) {
      result.insert(t);
    }
  }
  return result;
}

bool State::operator<(const State& other) const {
  return state_id_ < other.state_id_;
}

bool State::operator==(const State& other) const {
  return state_id_ == other.state_id_;
}