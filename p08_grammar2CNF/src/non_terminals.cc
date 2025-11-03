// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 04/11/2025
// Archivo chain.h: Fichero que contiene la implementación de la clase NonTerminals
// Referencias:
// Historial de revisiones
//   03/11/2025 - Creacion del codigo version 1.0

#include "non_terminals.h"

/**
 * @brief Constructor for NonTerminals class that initializes non-terminals and productions.
 * @param non_terminals The vector of non-terminal symbols.
 * @param productions The multimap of productions associated with the non-terminals.
 */
NonTerminals::NonTerminals(const std::vector<std::string>& non_terminals,
                           const std::multimap<std::string, std::vector<std::string>>& productions) {
  non_terminals_ = non_terminals;
  productions_ = productions;
}

/**
 * @brief Getter for the productions multimap.
 * @return The multimap of productions.
 */
std::multimap<std::string, std::vector<std::string>> NonTerminals::GetProductions() const {
  return productions_;
}

/**
 * @brief Setter for the productions multimap.
 * @param productions The multimap of productions to set.
 */
void NonTerminals::SetProductions(const std::multimap<std::string, std::vector<std::string>>& productions) {
  productions_ = productions;
}

/**
 * @brief Adds a production to the non-terminals.
 * @param left_symbol The left-hand side non-terminal symbol.
 * @param right_symbols The right-hand side vector of symbols.
 */
void NonTerminals::AddProduction(const std::string& left_symbol, const std::vector<std::string>& right_symbols) {
  productions_.insert(std::pair<std::string, std::vector<std::string>>(left_symbol, right_symbols));
}

/**
 * @brief Getter for the vector of non-terminal symbols.
 * @return The vector of non-terminal symbols.
 */
std::vector<std::string> NonTerminals::GetNonTerminals() const {
  return non_terminals_;
}

/**
 * @brief Setter for the vector of non-terminal symbols.
 * @param non_terminals The vector of non-terminal symbols to set.
 */
void NonTerminals::SetNonTerminals(const std::vector<std::string>& non_terminals) {
  non_terminals_ = non_terminals;
}

/**
 * @brief Adds a non-terminal symbol to the collection.
 * @param non_terminal The non-terminal symbol to add.
 */
void NonTerminals::push_back(const std::string& non_terminal) {
  non_terminals_.push_back(non_terminal);
}

/**
 * @brief Returns the number of non-terminal symbols in the collection.
 * @return The size of the non-terminals vector.
 */
int NonTerminals::size() const {
  return non_terminals_.size();
}