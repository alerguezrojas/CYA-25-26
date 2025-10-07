// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 4: Expresiones regulares en C++
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 14/10/2025
// Archivo loop.h Fichero que contiene la definición de la clase Loop
// Referencias:
// Historial de revisiones
//   04/10/25 - Creacion del codigo version 1.0

#ifndef LOOP_H
#define LOOP_H

#include <string>
#include <regex>
#include <vector>

class Loop {
  public:
    Loop() = default;
    ~Loop() = default;
    void SearchLoop(const std::string& line, int line_number);
    friend std::ostream& operator<<(std::ostream& os, const Loop& loop);

  private:
    std::string type_;
    int line_;
    int for_count_ = 0;
    int while_count_ = 0;
    std::vector<Loop> loops_;
};

#endif  // LOOP_H