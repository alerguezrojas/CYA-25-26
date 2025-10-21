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

/**
 * @brief Default constructor for State class.
 */
State::State() {
  state_id_ = "";
  start_state_ = false;
  accept_state_ = false;
  transitions_number_ = 0;
}

/**
 * @brief Constructor for State class that initializes the state with an ID, 
 *        start state flag, and accept state flag.
 * @param state_id The unique identifier for the state.
 * @param start_state Indicates if this is the start state.
 * @param accept_state Indicates if this is an accept state.
 */
State::State(const std::string& state_id, bool start_state, bool accept_state) {
  state_id_ = state_id;
  start_state_ = start_state;
  accept_state_ = accept_state;
  transitions_number_ = 0;
}

/**
 * @brief Constructor for State class that initializes the state with an ID, 
 *        start state flag, accept state flag, and transitions.
 * @param state_id The unique identifier for the state.
 * @param start_state Indicates if this is the start state.
 * @param accept_state Indicates if this is an accept state.
 * @param transitions The set of transitions from this state.
 */
State::State(const std::string& state_id, bool start_state, bool accept_state,
             std::set<Transition> transitions) {
  state_id_ = state_id;
  start_state_ = start_state;
  accept_state_ = accept_state;
  transitions_ = transitions;
  transitions_number_ = transitions.size();
}

/**
 * @brief Checks if the state is a start state.
 * @return True if it is a start state, false otherwise.
 */
bool State::IsStartState() const {
  return start_state_;
}

/**
 * @brief Checks if the state is an accept state.
 * @return True if it is an accept state, false otherwise.
 */
bool State::IsAcceptState() const {
  return accept_state_;
}

/**
 * @brief Getter for the state ID.
 * @return The unique identifier for the state.
 */
std::string State::GetStateId() const {
  return state_id_;
}

/**
 * @brief Gets the set of transitions for a given symbol.
 * @param symbol The symbol for which to get the transitions.
 * @return A set of transitions corresponding to the given symbol.
 */
std::set<Transition> State::GetTransitions(Symbol symbol) const {
  std::set<Transition> result;
  for (const auto& t : transitions_) {
    if (t.GetTransitionSymbol() == symbol) {
      result.insert(t);
    }
  }
  return result;
}

/**
 * @brief Less-than operator for comparing two states by their IDs.
 * @param other The other state to compare with.
 * @return True if this state is less than the other state, false otherwise.
 */
bool State::operator<(const State& other) const {
  return state_id_ < other.state_id_;
}

/**
 * @brief Equality operator for comparing two states by their IDs.
 * @param other The other state to compare with.
 * @return True if both states have the same ID, false otherwise.
 */
bool State::operator==(const State& other) const {
  return state_id_ == other.state_id_;
}