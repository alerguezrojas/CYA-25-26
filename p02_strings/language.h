// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 2: Cadenas y lenguajes
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo language.h: Fichero que contiene la definición de la clase Language
// Referencias:
// Historial de revisiones
//   20/09/2025 - Creacion del codigo version 1.0

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "chain.h"

class Language {
  public:
    Language();
    Language(const std::set<Chain>& language);
    ~Language() = default;
    std::set<Chain> GetLanguage() const;
    friend std::ostream& operator<<(std::ostream& os, const Language& language);

  private:
    std::set<Chain> language_;
};

#endif  // LANGUAGE_H