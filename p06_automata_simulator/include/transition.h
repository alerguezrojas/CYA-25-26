// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo transition.h: Fichero que contiene la definición de la clase Transición
// Referencias:
// Historial de revisiones
//   19/10/2025 - Creacion del codigo version 1.0

#ifndef TRANSITION_H
#define TRANSITION_H

#include "state.h"
#include "symbol.h"

class Transition {
  public:
    Transition(const State& origin_state, const Symbol& transition_symbol,
               const State& destination_state);
    ~Transition() = default;
    State GetOriginState() const;
    Symbol GetTransitionSymbol() const;
    State GetDestinationState() const;
    bool operator<(const Transition& other) const;

  private:
    State origin_state_;
    Symbol transition_symbol_;
    State destination_state_;

};

#endif  // TRANSITION_H