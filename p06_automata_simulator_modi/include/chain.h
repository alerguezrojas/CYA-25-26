// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo chain.h: Fichero que contiene la definición de la clase Chain
// Referencias:
// Historial de revisiones
//   20/09/2025 - Creacion del codigo version 1.0

#ifndef CHAIN_H
#define CHAIN_H

#include <vector>

#include "symbol.h"
#include "alphabet.h"

class Language;  // Forward declaration to avoid circular dependency

/**
 * @brief Class representing a chain, which is a sequence of symbols.
 *        A chain has an associated alphabet.
 */
class Chain {
  public:
    Chain();
    Chain(const std::string& chain);
    ~Chain() = default;
    void AddToFront(const Symbol& symbol);
    void AddToBack(const Symbol& symbol);
    std::vector<Symbol> GetChain() const;
    Alphabet GetAlphabet() const;
    void SetAlphabet(const Alphabet& alphabet);
    int Lenght() const;
    Chain Inverse() const;
    Language Prefixes() const;
    Language Suffixes() const;
    Language Subchains() const; // ej chain: abc -> &, a, b, c, ab, bc, abc
    friend std::ostream& operator<<(std::ostream& os, const Chain& chain);
    friend bool operator<(const Chain& chain1, const Chain& chain2);
  private:
    std::vector<Symbol> chain_; ///< Sequence of symbols in the chain
    Alphabet alphabet_; ///< Associated alphabet
};

inline bool operator!=(const Symbol& lhs, const Symbol& rhs) {
  return !(lhs == rhs);
}

#endif  // CHAIN_H