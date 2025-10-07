// modi: archivo ifelse.h: Declaracion de la clase IfElse (deteccion de if/else)

#ifndef IFELSE_H
#define IFELSE_H

#include <string>
#include <regex>
#include <vector>

class IfElse {
 public:
  IfElse() = default;
  ~IfElse() = default;
  void SearchIfElse(const std::string& line, int line_number);
  friend std::ostream& operator<<(std::ostream& os, const IfElse& ifelse);

 private:
  std::string type_;
  int line_ = 0;
  int if_count_ = 0;
  int else_if_count_ = 0;
  int else_count_ = 0;
  std::vector<IfElse> branches_;
};

#endif  // IFELSE_H
