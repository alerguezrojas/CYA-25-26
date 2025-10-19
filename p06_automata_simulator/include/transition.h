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

#include <string>
#include "symbol.h"

/**
 * @brief Clase que representa una transición (usa los IDs de estado para evitar copias).
 */
class Transition {
 public:
  Transition(const std::string& origin_id,
             const Symbol& transition_symbol,
             const std::string& destination_id);
  ~Transition() = default;

  std::string GetOriginId() const;
  Symbol GetTransitionSymbol() const;
  std::string GetDestinationId() const;

  bool operator<(const Transition& other) const;

 private:
  std::string origin_id_;
  Symbol transition_symbol_;
  std::string destination_id_;
};

#endif  // TRANSITION_H
