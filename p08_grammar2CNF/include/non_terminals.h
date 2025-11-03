// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 04/11/2025
// Archivo chain.h: Fichero que contiene la definición de la clase NonTerminals
// Referencias:
// Historial de revisiones
//   03/11/2025 - Creacion del codigo version 1.0

#ifndef NON_TERMINALS_H
#define NON_TERMINALS_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "symbol.h"

/**
 * @class NonTerminals
 * @brief This class represents a collection of non-terminal symbols and their 
 *        associated productions in a context-free grammar.
 * 
 * The NonTerminals class provides methods to manage non-terminal symbols and their productions.
 */
class NonTerminals {
  public:
    NonTerminals() = default;
    NonTerminals(const std::vector<std::string>& non_terminals,
                 const std::multimap<std::string, std::vector<std::string>>& productions);
    ~NonTerminals() = default;
    std::multimap<std::string, std::vector<std::string>> GetProductions() const;
    void SetProductions(const std::multimap<std::string, std::vector<std::string>>& productions);
    void AddProduction(const std::string& left_symbol, const std::vector<std::string>& right_symbols);
    std::vector<std::string> GetNonTerminals() const;
    void SetNonTerminals(const std::vector<std::string>& non_terminals);
    void push_back(const std::string& non_terminal);
    int size() const;

  private:
    std::vector<std::string> non_terminals_; ///< Vector to store non-terminal symbols
    std::multimap<std::string, std::vector<std::string>> productions_; ///< Map to store productions for each non-terminal

};

#endif  // NON_TERMINALS_H
