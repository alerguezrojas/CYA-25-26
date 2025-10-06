// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 4: Expresiones regulares en C++
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 14/10/2025
// Archivo comment.h: Fichero que contiene la definición de la clase Comment
// Referencias:
// Historial de revisiones
//   04/10/25 - Creacion del codigo version 1.0

#ifndef COMMENT_H
#define COMMENT_H

#include <string>
#include <vector>
#include <regex>
#include <string>
#include <sstream>


class Comment {
  public:
    Comment() = default;
    ~Comment() = default;
    void SearchComment(const std::string& line, int line_number);
    std::string PrintDescription() const;
    friend std::ostream& operator<<(std::ostream& os, const Comment& comment);

  private:
    std::string type_;
    int start_line_;
    int end_line_;
    std::string content_;
    std::vector<std::string> content_lines_;
    std::vector<Comment> comments_;
};

#endif  // COMMENT_H