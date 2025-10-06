// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 4: Expresiones regulares en C++
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 14/10/2025
// Archivo comment.cc: Fichero que contiene la implementación de la clase Comment
// Referencias:
// Historial de revisiones
//   04/10/25 - Creacion del codigo version 1.0

#include "comment.h"

void Comment::SearchComment(const std::string& line, int line_number) {
  static bool in_description = false;
  static Comment current_block;

  std::regex single_comment(R"(^\s*//(.*))");
  std::regex start_block(R"(^\s*/\*.*)");
  std::regex end_block(R"(.*\*/\s*$)");
  std::smatch match;

  // Comentario de una línea
  if (std::regex_search(line, match, single_comment)) {
    Comment comment;
    comment.type_ = "Single";
    comment.content_ = match.str(1);
    comment.start_line_ = line_number;
    comment.end_line_ = line_number;
    comments_.push_back(comment);
    return;
  }

  // Comienzo de bloque /* ... */
  if (std::regex_search(line, match, start_block)) {
    in_description = true;
    current_block = Comment();  // reiniciar bloque
    current_block.start_line_ = line_number;
    current_block.type_ = (line_number == 1 ? "Description" : "Multiple");
  }

  if (in_description) {
    current_block.content_lines_.push_back(line);
  }

  // Fin de bloque */ ...
  if (in_description && std::regex_search(line, match, end_block)) {
    in_description = false;
    current_block.end_line_ = line_number;
    comments_.push_back(current_block);
    current_block.content_lines_.clear();
  }
}

std::string Comment::PrintDescription() const {
  std::ostringstream oss;
  for (const auto& comment : comments_) {
    if (comment.type_ == "Description") {
      for (const auto& line : comment.content_lines_) {
        oss << line << "\n";
      }
    }
  }
  return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Comment& comments) {
  for (const auto& comment : comments.comments_) {
    if (comment.type_ == "Single") {
      os << "[Line " << comment.start_line_ << "] // " << comment.content_ << "\n";
    } else if (comment.type_ == "Multiple") {
      os << "[Line " << comment.start_line_ << "-" << comment.end_line_ << "] MULTIPLE\n";
      for (const auto& line : comment.content_lines_) {
        os << line << "\n";
      }
    } else if (comment.type_ == "Description") {
      os << "[Line " << comment.start_line_ << "-" << comment.end_line_ << "] DESCRIPTION\n";
    }
  }
  return os;
}




