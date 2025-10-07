// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 4: Expresiones regulares en C++
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 14/10/2025
// Archivo variable.cc: Fichero que contiene la implementación de la clase Variable
// Referencias:
// Historial de revisiones
//   04/10/25 - Creacion del codigo version 1.0

// Archivo variable.cc: Implementación de la clase Variable
#include "variable.h"
#include <regex>

/**
 * Método para buscar y almacenar variables en una línea dada.
 * Maneja variables de tipo int y double, con o sin inicialización.
 * Las variables detectadas se almacenan en el vector variables_.
 * @param line La línea de código a analizar.
 * @param line_number El número de línea actual en el archivo.
 * @return void
 */
void Variable::SearchVariable(const std::string& line, int line_number) {
  // Grupos:
  // (1) tipo -> int|double
  // (2) nombre
  // (3) valor tras '=' (si existe)
  // (4) valor en '{ }' (si existe)
  static const std::regex variable_expression(
    R"(^\s*(int|double)\s+([A-Za-z_]\w*)\s*(?:=\s*([-+]?\d+(?:\.\d+)?(?:[eE][-+]?\d+)?)|\s*\{\s*([-+]?\d+(?:\.\d+)?(?:[eE][-+]?\d+)?)\s*\})?\s*;\s*(?://.*|/\*.*\*/)?\s*$)"
  );

  std::smatch match;
  if (std::regex_search(line, match, variable_expression)) {
    Variable variable;
    variable.type_ = match[1].str();   // "int" o "double"
    variable.name_ = match[2].str();
    variable.line_ = line_number;

    const bool has_eq_value  = match[3].matched;
    const bool has_brace_val = match[4].matched;
    variable.initialized_    = has_eq_value || has_brace_val;
    if (has_eq_value)       variable.value_ = match[3].str();
    else if (has_brace_val) variable.value_ = match[4].str();

    (variable.type_ == "int" ? int_count_ : double_count_)++;
    variables_.push_back(variable);
  }
}

/**
 * Sobrecarga del operador de salida para imprimir todas las variables almacenadas.
 * Imprime cada variable con su tipo, nombre, línea y valor si está inicializada.
 * @param os El stream de salida.
 * @param variable El objeto Variable que contiene las variables a imprimir.
 * @return std::ostream& El stream de salida modificado.
 */
std::ostream& operator<<(std::ostream& os, const Variable& variable) {
  for (const auto& var : variable.variables_) {
    os << "[Line " << var.line_ << "] "
       << (var.type_ == "int" ? "INT: " : "DOUBLE: ")
       << var.name_;
    if (var.initialized_) {
      os << " = " << var.value_;
    }
    os << '\n';
  }
  return os;
}
