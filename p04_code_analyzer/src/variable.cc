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

#include "variable.h"

void Variable::SearchVariable(const std::string& line, int line_number) {
  std::regex variable_expression(
    R"(^\s*(int|double)\s+([A-Za-z_]\w*)\s*(=\s*([-+]?\d+(?:\.\d+)?)|\{\s*([-+]?\d+(?:\.\d+)? )\s*\})?\s*;\s*$)"
  );
  std::smatch match;
  if (std::regex_search(line, match, variable_expression)) {
    Variable variable;
    variable.type_ = match.str(1);
    variable.name_ = match.str(2);
    variable.line_ = line_number;
    variable.initialized_ = !match.str(3).empty();
    if (variable.initialized_) {
      variable.value_ = !match.str(4).empty() ? match.str(4) : match.str(6); // Handle both '=' and '{}' initializations
    }
    (variable.type_ == "int" ? int_count_ : double_count_)++;
    variables_.push_back(variable);
  }
}

std::ostream& operator<<(std::ostream& os, const Variable& variable) {
  for (const auto& var : variable.variables_) {
    os << "[Line " << var.line_ << "] "
       << (var.type_ == "int" ? "INT: " : "DOUBLE: ")
       << var.name_;
    if (var.initialized_) {
      os << " = " << var.value_;
    }
    os << std::endl;
  }
  return os;
}

    
    
    

