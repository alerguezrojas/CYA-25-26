// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo automata.cc: Fichero que contiene la implementación de la clase Automata
// Referencias:
// Historial de revisiones
//   19/10/2025 - Creacion del codigo version 1.0

// automata.cc
#include "automata.h"

void Automata::SetAlphabet(const Alphabet& alphabet) {
  alphabet_ = alphabet;
}

void Automata::SetStates(const std::set<State>& states) {
  states_ = states;
  states_number_ = static_cast<int>(states.size());
}

void Automata::SetStartState(const State& start_state) {
  start_state_ = start_state;
}

void Automata::SetAcceptStates(const std::set<State>& accept_states) {
  accept_states_ = accept_states;
}

void Automata::SetTransitions(const std::set<Transition>& transitions) {
  transitions_ = transitions;
}

const Alphabet& Automata::GetAlphabet() const {
  return alphabet_;
}

const std::set<State>& Automata::GetStates() const {
  return states_;
}

const State& Automata::GetStartState() const {
  return start_state_;
}

const std::set<State>& Automata::GetAcceptStates() const {
  return accept_states_;
}

const std::set<Transition>& Automata::GetTransitions() const {
  return transitions_;
}

int Automata::GetStatesNumber() const {
  return states_number_;
}

bool Automata::AlphabetContainsSymbol(const Symbol& symbol) const {
  return alphabet_.Contains(symbol);
}

void Automata::Print(std::ostream& os) const {
  os << "Alphabet: " << alphabet_ << "\n";
  os << "Number of States: " << states_number_ << "\n";
  os << "Start State: " << start_state_.GetStateId() << "\n";

  os << "Accept States: {";
  bool first = true;
  for (const auto& st : accept_states_) {
    if (!first) os << ", ";
    os << st.GetStateId();
    first = false;
  }
  os << "}\n";

  os << "Transitions:\n";
  for (const auto& t : transitions_) {
    os << "  (" << t.GetOriginId() << ", "
       << t.GetTransitionSymbol().GetSymbol() << ") -> "
       << t.GetDestinationId() << "\n";
  }
}

std::ostream& operator<<(std::ostream& os, const Automata& automata) {
  automata.Print(os);
  return os;
}




