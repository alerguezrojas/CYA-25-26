// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo nfa.h: Fichero que contiene la definición de la clase NFA
// Referencias:
// Historial de revisiones
//   19/10/2025 - Creacion del codigo version 1.0

#ifndef NFA_H
#define NFA_H

#include <set>
#include <map>
#include <stack>
#include <string>
#include <iostream>

#include "automata.h"
#include "state.h"
#include "transition.h"
#include "symbol.h"
#include "chain.h"

/**
 * @brief Class that represents a Non-deterministic Finite Automaton (NFA),
 *        with support for ε-transitions (represented as '&').
 *        Inherits from Automata and implements the ReadChains() method,
 *        which simulates the behavior of the NFA for a given chain.
 */
class NFA : public Automata {
  public:
    NFA() = default;
    NFA(const Alphabet& alphabet, const std::set<State>& states,
        const State& start_state, const std::set<State>& accept_states,
        const std::set<Transition>& transitions);
    bool ReadChains(const Chain& chain) const override;

  private:
    std::set<std::string> EpsilonClosure(const std::set<std::string>& state_ids) const; ///< Calculates the ε-closure of a set of states.
    std::set<std::string> Move(const std::set<std::string>& from, const Symbol& a) const; ///< Moves from a set of states using a given symbol.
    const State* FindState(const std::string& id) const; ///< Finds a state by its ID.
};

#endif  // NFA_H
