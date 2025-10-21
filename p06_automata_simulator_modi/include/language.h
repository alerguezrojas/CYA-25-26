// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo language.h: Fichero que contiene la definición de la clase Language
// Referencias:
// Historial de revisiones
//   20/09/2025 - Creacion del codigo version 1.0
//   19/10/2025 - Añadido setter para el lenguaje version 1.1

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "chain.h"

/**
 * @brief Class representing a language, which is a set of chains.
 */
class Language {
  public:
    Language();
    Language(const std::set<Chain>& language);
    ~Language() = default;
    std::set<Chain> GetLanguage() const;
    void SetLanguage(const std::set<Chain>& language);
    friend std::ostream& operator<<(std::ostream& os, const Language& language);

  private:
    std::set<Chain> language_; ///< Set of chains in the language
};

#endif  // LANGUAGE_H