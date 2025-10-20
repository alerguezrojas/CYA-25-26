// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo transition.cc: Fichero que contiene la implementación de la clase Transición
// Referencias:
// Historial de revisiones
//   19/10/2025 - Creacion del codigo version 1.0

#include "transition.h"

/**
 * @brief Constructor for Transition class that initializes the transition with
 *        origin state ID, transition symbol, and destination state ID.
 * @param origin_id The ID of the origin state.
 * @param transition_symbol The symbol that triggers the transition.
 * @param destination_id The ID of the destination state.
 */
Transition::Transition(const std::string& origin_id, const Symbol& transition_symbol,
                       const std::string& destination_id)
    : origin_id_(origin_id),
      transition_symbol_(transition_symbol),
      destination_id_(destination_id) {}

/**
 * @brief Getter for the origin state ID.
 * @return The ID of the origin state.
 */
std::string Transition::GetOriginId() const { return origin_id_; }

/**
 * @brief Getter for the transition symbol.
 * @return The symbol that triggers the transition.
 */
Symbol Transition::GetTransitionSymbol() const { return transition_symbol_; }

/**
 * @brief Getter for the destination state ID.
 * @return The ID of the destination state.
 */
std::string Transition::GetDestinationId() const { return destination_id_; }

/**
 * @brief Less-than operator for comparing two transitions.
 * @param other The other transition to compare with.
 * @return True if this transition is less than the other transition, false otherwise.
 */
bool Transition::operator<(const Transition& other) const {
  if (origin_id_ != other.origin_id_) return origin_id_ < other.origin_id_;
  if (!(transition_symbol_ == other.transition_symbol_))
    return transition_symbol_ < other.transition_symbol_;
  return destination_id_ < other.destination_id_;
}
