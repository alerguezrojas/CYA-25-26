// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo alphabet.h: Fichero que contiene la definición de la clase Alphabet
// Referencias:
// Historial de revisiones
//   18/09/2025 - Creacion del codigo version 1.0

#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <set>
#include <string>

#include "symbol.h"

/**
 * @brief Class representing an alphabet, which is a set of symbols.
 */
class Alphabet {
  public:
    Alphabet();
    Alphabet(const std::string& alphabet);
    Alphabet(const std::set<Symbol>& alphabet);
    ~Alphabet() = default;
    std::set<Symbol> GetAlphabet() const;
    void AddSymbol(const Symbol& symbol);
    bool Contains(const Symbol& symbol) const;
    friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);

  private:
    std::set<Symbol> alphabet_; ///< Set of symbols in the alphabet
    
};

#endif  // ALPHABET_H