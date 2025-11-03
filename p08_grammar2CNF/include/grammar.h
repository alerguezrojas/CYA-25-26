// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 04/11/2025
// Archivo grammar.h: Fichero que contiene la definición de la clase Grammar
// Referencias:
// Historial de revisiones
//   03/11/2025 - Creacion del codigo version 1.0

#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "alphabet.h"
#include "symbol.h"
#include "non_terminals.h"

/**
 * @class Grammar
 * @brief Represents a context-free grammar.
 * 
 * This class provides functionalities to handle context-free grammars,
 * including checking for terminal and non-terminal symbols, converting
 * the grammar to Chomsky Normal Form (CNF), and checking for unitary
 * and empty productions.
 */
class Grammar {
  public:
    Grammar() = default;
    Grammar(const std::string& file_name);
    Alphabet GetTerminals() const { return terminals_; }
    Symbol GetStartSymbol() const { return start_symbol_; }
    NonTerminals GetNonTerminals() const { return non_terminals_; }
    void SetTerminals(const Alphabet& terminals) { terminals_ = terminals; }
    void SetStartSymbol(const Symbol& start_symbol) { start_symbol_ = start_symbol; }
    void SetNonTerminals(const NonTerminals& non_terminals) { non_terminals_ = non_terminals; }
    bool isTerminal(const Symbol& symbol) const;
    bool isNonTerminal(const Symbol& symbol) const;
    Grammar Convert2CNF() const;
    bool hasUnitaryProductions() const;
    bool hasEmptyProductions() const;
    friend std::ostream& operator<<(std::ostream& os, const Grammar& grammar);
    

  private:
    Alphabet terminals_; ///< Alphabet of terminal symbols
    Symbol start_symbol_; ///< Start symbol of the grammar
    NonTerminals non_terminals_; ///< Non-terminal symbols and their productions
};

#endif  // GRAMMAR_H