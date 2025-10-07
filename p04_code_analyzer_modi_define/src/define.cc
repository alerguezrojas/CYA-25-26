// Universidad de La Laguna
// Archivo define.cc: Implementacion de la clase Define

#include "define.h"
#include <regex>

void Define::SearchDefine(const std::string& line, int line_number) {
  // Regex para capturar: #define NOMBRE [valor opcional]
  static const std::regex define_regex(R"(^\s*#\s*define\s+([A-Za-z_]\w*)\s*(.*)\s*$)");
  std::smatch match;
  if (std::regex_search(line, match, define_regex)) {
    Define d;
    d.name_ = match[1].str();
    d.value_ = match[2].str();
    d.line_ = line_number;
    defines_.push_back(d);
  }
}

std::ostream& operator<<(std::ostream& os, const Define& define) {
  for (const auto& d : define.defines_) {
    os << "[Line " << d.line_ << "] DEFINE: " << d.name_;
    if (!d.value_.empty()) os << " = " << d.value_;
    os << std::endl;
  }
  return os;
}
