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

#include "comment.h"
#include <regex>

/**
 * Método para buscar y almacenar comentarios en una línea dada.
 * Maneja comentarios de una línea (//) y bloques de comentarios (/* ... * /).
 * Los bloques pueden abarcar múltiples líneas.
 * La descripción inicial (si está en la primera línea) se marca como "Description".
 * Los comentarios de bloque y de línea se almacenan en el vector comments_.
 * @param line La línea de código a analizar.
 * @param line_number El número de línea actual en el archivo.
 * @return void
 */
void Comment::SearchComment(const std::string& line, int line_number) {
  // Estado para bloques multi-línea
  static bool in_block = false;
  static Comment current_block;

  // Regex
  static const std::regex single_comment(R"(//(.*))"); // // en cualquier parte
  static const std::regex start_block(R"(/\*)");       // inicio de bloque
  static const std::regex end_block(R"(\*/)");         // fin de bloque

  std::smatch match;

  // 1) Si estamos dentro de un bloque, acumulamos y miramos si cierra
  if (in_block) {
    current_block.content_lines_.push_back(line);
    if (std::regex_search(line, match, end_block)) {
      in_block = false;
      current_block.end_line_ = line_number;
      comments_.push_back(current_block);
      current_block.content_lines_.clear();
    }
    return; // estando en bloque, no procesamos // para evitar falsos positivos
  }

  // 2) ¿Empieza un bloque en esta línea?
  if (std::regex_search(line, match, start_block)) {
    in_block = true;
    current_block = Comment();
    current_block.start_line_ = line_number;
    current_block.type_ = (line_number == 1 ? "Description" : "Multiple");
    current_block.content_lines_.push_back(line);

    // Si cierra en la misma línea
    if (std::regex_search(line, match, end_block)) {
      in_block = false;
      current_block.end_line_ = line_number;
      comments_.push_back(current_block);
      current_block.content_lines_.clear();
    }
    return;
  }

  // 3) Fuera de bloque: busca // donde sea (incluye comentarios al final de línea)
  if (std::regex_search(line, match, single_comment)) {
    Comment comment;
    comment.type_ = "Single";
    comment.start_line_ = line_number;
    comment.end_line_ = line_number;
    comment.content_ = match.str(1);
    comments_.push_back(comment);
  }
}

/**
 * Método para imprimir la descripción inicial del código.
 * Busca en los comentarios almacenados uno marcado como "Description".
 * Si lo encuentra, concatena sus líneas de contenido y las devuelve.
 * Si no hay descripción, devuelve una cadena vacía.
 * @return std::string La descripción encontrada o cadena vacía.
 */
std::string Comment::PrintDescription() const {
  std::ostringstream oss;
  for (const auto& comment : comments_) {
    if (comment.type_ == "Description") {
      for (const auto& l : comment.content_lines_) {
        oss << l << "\n";
      }
    }
  }
  return oss.str();
}

/**
 * Sobrecarga del operador de salida para imprimir todos los comentarios almacenados.
 * Imprime cada comentario con su tipo, líneas y contenido.
 * Los comentarios de bloque se imprimen línea por línea.
 * @param os El stream de salida.
 * @param comments El objeto Comment que contiene los comentarios a imprimir.
 * @return std::ostream& El stream de salida modificado.
 */
std::ostream& operator<<(std::ostream& os, const Comment& comments) {
  for (const auto& comment : comments.comments_) {
    if (comment.type_ == "Single") {
      os << "[Line " << comment.start_line_ << "] //" << comment.content_ << "\n";
    } else if (comment.type_ == "Multiple") {
      os << "[Line " << comment.start_line_ << "-" << comment.end_line_ << "] MULTIPLE\n";
      for (const auto& l : comment.content_lines_) os << l << "\n";
    } else if (comment.type_ == "Description") {
      os << "[Line " << comment.start_line_ << "-" << comment.end_line_ << "] DESCRIPTION\n";
    }
  }
  return os;
}




