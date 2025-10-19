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

#include "automata.h"

Alphabet Automata::GetAlphabet() const {
  return alphabet_;
}

std::set<State> Automata::GetStates() const {
  return states_;
}

State Automata::GetStartState() const {
  return start_state_;
}

std::set<State> Automata::GetAcceptStates() const {
  return accept_states_;
}

std::set<Transition> Automata::GetTransitions() const {
  return transitions_;
}

int Automata::GetStatesNumber() const {
  return states_number_;
}

bool Automata::AlphabetContainsSymbol(const Symbol& symbol) const {
  return alphabet_.Contains(symbol);
}

std::ostream& operator<<(std::ostream& os, const Automata& automata) {
  os << "Alphabet: " << automata.alphabet_ << "\n";
  os << "Number of States: " << automata.states_number_ << "\n";
  os << "States:\n";
  for (const auto& state : automata.states_) {
    os << "  State ID: " << state.GetStateId();
    if (state.IsStartState()) {
      os << " (Start State)";
    }
    if (state.IsAcceptState()) {
      os << " (Accept State)";
    }
    os << "\n";
  }
  os << "Transitions:\n";
  for (const auto& transition : automata.transitions_) {
    os << "  From State: " << transition.GetOriginState().GetStateId()
       << " -- Symbol: " << transition.GetTransitionSymbol()
       << " --> To State: " << transition.GetDestinationState().GetStateId() << "\n";
  }
  return os;
}



