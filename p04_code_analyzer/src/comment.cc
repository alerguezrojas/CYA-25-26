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
  std::regex single_comment(R"(^\s*//(.*))");
  std::regex start_description(R"(\s*\/\*.*\s*)");
  std::regex end_description(R"(\s*.*\*\/\s*)");
  std::smatch match;

  static bool in_description = false;
  static Comment description_comment;

  if (std::regex_search(line, match, single_comment)) {
    Comment comment;
    comment.type_ = "Single";
    comment.content_ = match.str(1);
    comment.start_line_ = line_number;
    comments_.push_back(comment);
  } else if (std::regex_search(line, match, start_description)) {
    in_description = true;
    if (line_number == 1) {
      description_comment.type_ = "Description";
    } else {
      description_comment.type_ = "Multiple";
    }
    description_comment.start_line_ = line_number;
    description_comment.content_lines_.push_back(match.str(1));
  } else if (in_description) {
    if (std::regex_search(line, match, end_description)) {
      in_description = false;
      description_comment.content_lines_.push_back(match.str(1));
      comments_.push_back(description_comment);
      description_comment.content_lines_.clear();
    } else {
      description_comment.content_lines_.push_back(line);
    }
  }

  if (in_description) {
    description_comment.end_line_ = line_number + 1;
  }
}

std::ostream& operator<<(std::ostream& os, const Comment& comments) {
  for (auto comment : comments.comments_) {
    if (comment.type_ == "Single") {
      os << "[Line " << comment.start_line_ << "] //" << comment.content_ << std::endl;
    } else if (comment.type_ == "Description") {
      os << "[Line " << comment.start_line_ << "-" << comment.end_line_ << "] DESCRIPTION "<< std::endl;
    } else if (comment.type_ == "Multiple") {
      os << "[Line " << comment.start_line_ << "-" << comment.end_line_ << "] MULTIPLE" << std::endl;
    }
    return os;
  }
}

std::string Comment::PrintDescription() const {
  std::string description;
  for (auto comment : comments_) {
    if (comment.type_ == "Description") {
      description += "/**";
      for (auto line : comment.content_lines_) {
        description += line + "\n";
      }
      description += "*/\n";
    }
  }

  return description;
}



