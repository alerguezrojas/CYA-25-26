// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 4: Expresiones regulares en C++
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 14/10/2025
// Archivo variable.h: Fichero que contiene la definición de la clase Variable
// Referencias:
// Historial de revisiones
//   04/10/25 - Creacion del codigo version 1.0

#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <regex>
#include <vector>

class Variable {
  public:
    Variable() = default;
    ~Variable() = default;
    void SearchVariable(const std::string& line, int line_number);
    friend std::ostream& operator<<(std::ostream& os, const Variable& variable);

  private:
    std::string type_;
    std::string name_;
    int line_;
    bool initialized_;
    std::string value_;
    int int_count_ = 0;
    int double_count_ = 0;
    std::vector<Variable> variables_;
};

#endif  // VARIABLE_H