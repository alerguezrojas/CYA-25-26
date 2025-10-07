// Universidad de La Laguna
// Archivo ifelse.cc: Implementacion de la clase IfElse

#include "ifelse.h"
#include <regex>

void IfElse::SearchIfElse(const std::string& line, int line_number) {
  // Detecta if, else if y else (evita coincidencias dentro de comentarios)
  static const std::regex if_regex(R"((?:^|[^\w])if\s*\()" );
  static const std::regex else_if_regex(R"((?:^|[^\w])else\s+if\s*\()" );
  static const std::regex else_regex(R"((?:^|[^\w])else\b)" );

  std::smatch match;
  if (std::regex_search(line, match, else_if_regex)) {
    IfElse node;
    node.type_ = "else if";
    node.line_ = line_number;
    ++else_if_count_;
    branches_.push_back(node);
  } else if (std::regex_search(line, match, if_regex)) {
    IfElse node;
    node.type_ = "if";
    node.line_ = line_number;
    ++if_count_;
    branches_.push_back(node);
  } else if (std::regex_search(line, match, else_regex)) {
    IfElse node;
    node.type_ = "else";
    node.line_ = line_number;
    ++else_count_;
    branches_.push_back(node);
  }
}

std::ostream& operator<<(std::ostream& os, const IfElse& ifelse) {
  for (const auto& b : ifelse.branches_) {
    os << "[Line " << b.line_ << "] IF-ELSE: " << b.type_ << std::endl;
  }
  return os;
}
