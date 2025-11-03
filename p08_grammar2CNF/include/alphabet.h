// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 04/11/2025
// Archivo alphabet.h: Fichero que contiene la definición de la clase Alphabet
// Referencias:
// Historial de revisiones
//   18/09/2025 - Creacion del codigo version 1.0
//   03/11/2025 - Añadido método AddSymbol con string version y size() version 1.1

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
    void AddSymbol(const std::string& value);
    bool Contains(const Symbol& symbol) const;
    int size() const;
    friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);

  private:
    std::set<Symbol> alphabet_; ///< Set of symbols in the alphabet
    
};

#endif  // ALPHABET_H