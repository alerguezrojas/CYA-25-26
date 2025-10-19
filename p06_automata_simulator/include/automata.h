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

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <set>


#include "alphabet.h"
#include "state.h"
#include "transition.h"
#include "symbol.h"
#include "chain.h"

class Automata {
  public:
    Alphabet GetAlphabet() const;
    std::set<State> GetStates() const;
    State GetStartState() const;
    std::set<State> GetAcceptStates() const;
    std::set<Transition> GetTransitions() const;
    int GetStatesNumber() const;
    bool AlphabetContainsSymbol(const Symbol& symbol) const;
    virtual bool ReadChains(const Chain& chain) = 0;
    friend std::ostream& operator<<(std::ostream& os, const Automata& automata);


  private:
    Alphabet alphabet_;
    std::set<State> states_;
    State start_state_;
    std::set<State> accept_states_;
    std::set<Transition> transitions_;
    int states_number_;
};

#endif  // AUTOMATA_H
