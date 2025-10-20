// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo automata.h: Fichero que contiene la definición de la clase Automata
// Referencias:
// Historial de revisiones
//   19/10/2025 - Creacion del codigo version 1.0

// automata.h
#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <set>
#include <string>
#include <iostream>
#include <stdexcept>

#include "alphabet.h"
#include "state.h"
#include "transition.h"
#include "symbol.h"
#include "chain.h"

/**
 * @brief Clase base abstracta para representar autómatas finitos.
 *        Contiene la estructura común a DFA y NFA.
 */
class Automata {
 public:
  Automata() = default;
  virtual ~Automata() = default;
  void SetAlphabet(const Alphabet& alphabet);
  void SetStates(const std::set<State>& states);
  void SetStartState(const State& start_state);
  void SetAcceptStates(const std::set<State>& accept_states);
  void SetTransitions(const std::set<Transition>& transitions);
  const Alphabet& GetAlphabet() const;
  const std::set<State>& GetStates() const;
  const State& GetStartState() const;
  const std::set<State>& GetAcceptStates() const;
  const std::set<Transition>& GetTransitions() const;
  int GetStatesNumber() const;
  bool AlphabetContainsSymbol(const Symbol& symbol) const;
  // Virtual method for simulation
  virtual bool ReadChains(const Chain& chain) const = 0;
  virtual void Print(std::ostream& os) const;

 protected:
  Alphabet alphabet_; ///< Alphabet of the automaton
  std::set<State> states_; ///< Set of states in the automaton
  State start_state_; ///< Start state of the automaton
  std::set<State> accept_states_; ///< Set of accept states
  std::set<Transition> transitions_; ///< Set of transitions
  int states_number_ = 0; ///< Number of states in the automaton
};

std::ostream& operator<<(std::ostream& os, const Automata& automata);

#endif  // AUTOMATA_H

