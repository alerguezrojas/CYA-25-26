// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo state.h: Fichero que contiene la definición de la clase Estado
// Referencias:
// Historial de revisiones
//   19/10/2025 - Creacion del codigo version 1.0

#ifndef STATE_H
#define STATE_H

#include <set>
#include <string>
#include "symbol.h"

class Transition;

class State {
 public:
  State();
  State(const std::string& state_id, bool start_state, bool accept_state);
  State(const std::string& state_id, bool start_state, bool accept_state,
        std::set<Transition> transitions);
  ~State() = default;
  bool IsStartState() const;
  bool IsAcceptState() const;
  std::string GetStateId() const;
  std::set<Transition> GetTransitions(Symbol symbol) const;
  bool operator<(const State& other) const;
  bool operator==(const State& other) const;

 private:
  std::string state_id_; ///< Unique identifier for the state
  bool start_state_; ///< Indicates if this is the start state
  bool accept_state_; ///< Indicates if this is an accept state
  int transitions_number_; ///< Number of transitions from this state
  std::set<Transition> transitions_; ///< Set of transitions from this state
};

#endif  // STATE_H