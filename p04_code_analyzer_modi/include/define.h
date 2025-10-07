// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Practica 4: Expresiones regulares en C++
// Archivo define.h: Declaracion de la clase Define (deteccion de #define)

#ifndef DEFINE_H
#define DEFINE_H

#include <string>
#include <regex>
#include <vector>

class Define {
 public:
  Define() = default;
  ~Define() = default;
  void SearchDefine(const std::string& line, int line_number);
  friend std::ostream& operator<<(std::ostream& os, const Define& define);

 private:
  std::string name_;
  std::string value_;
  int line_ = 0;
  std::vector<Define> defines_;
};

#endif  // DEFINE_H
