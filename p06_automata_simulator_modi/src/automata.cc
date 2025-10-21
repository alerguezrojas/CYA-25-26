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

/**
 * @brief Sets the alphabet of the automaton.
 * @param alphabet The alphabet to set.
 */
void Automata::SetAlphabet(const Alphabet& alphabet) {
  alphabet_ = alphabet;
}

/**
 * @brief Sets the states of the automaton.
 * @param states The set of states to set.
 */
void Automata::SetStates(const std::set<State>& states) {
  states_ = states;
  states_number_ = static_cast<int>(states.size());
}

/**
 * @brief Sets the start state of the automaton.
 * @param start_state The start state to set.
 */
void Automata::SetStartState(const State& start_state) {
  start_state_ = start_state;
}

/**
 * @brief Sets the accept states of the automaton.
 * @param accept_states The set of accept states to set.
 */
void Automata::SetAcceptStates(const std::set<State>& accept_states) {
  accept_states_ = accept_states;
}

/**
 * @brief Sets the transitions of the automaton.
 * @param transitions The set of transitions to set.
 */
void Automata::SetTransitions(const std::set<Transition>& transitions) {
  transitions_ = transitions;
}
/**
 * @brief Getter for the alphabet of the automaton.
 * @return The alphabet of the automaton.
 */
const Alphabet& Automata::GetAlphabet() const {
  return alphabet_;
}

/**
 * @brief Getter for the states of the automaton.
 * @return The set of states of the automaton.
 */
const std::set<State>& Automata::GetStates() const {
  return states_;
}

/**
 * @brief Getter for the start state of the automaton.
 * @return The start state of the automaton.
 */
const State& Automata::GetStartState() const {
  return start_state_;
}

/**
 * @brief Getter for the accept states of the automaton.
 * @return The set of accept states of the automaton.
 */
const std::set<State>& Automata::GetAcceptStates() const {
  return accept_states_;
}

/**
 * @brief Getter for the transitions of the automaton.
 * @return The set of transitions of the automaton.
 */
const std::set<Transition>& Automata::GetTransitions() const {
  return transitions_;
}

/**
 * @brief Getter for the number of states in the automaton.
 * @return The number of states.
 */
int Automata::GetStatesNumber() const {
  return states_number_;
}

/**
 * @brief Checks if the alphabet contains a specific symbol.
 * @param symbol The symbol to check for.
 * @return True if the symbol is in the alphabet, false otherwise.
 */
bool Automata::AlphabetContainsSymbol(const Symbol& symbol) const {
  return alphabet_.Contains(symbol);
}

/**
 * @brief Prints the automaton's details to the output stream.
 * @param os The output stream.
 */
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

/**
 * @brief Output stream operator for printing the automaton.
 * @param os The output stream.
 * @param automata The automaton to print.
 */
std::ostream& operator<<(std::ostream& os, const Automata& automata) {
  automata.Print(os);
  return os;
}




