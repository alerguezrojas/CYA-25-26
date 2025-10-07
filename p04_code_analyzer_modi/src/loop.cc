// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 4: Expresiones regulares en C++
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 14/10/2025
// Archivo loop.cc Fichero que contiene la implementación de la clase Loop
// Referencias:
// Historial de revisiones
//   04/10/25 - Creacion del codigo version 1.0

#include "loop.h"

/**
 * Método para buscar y almacenar bucles en una línea dada.
 * Maneja bucles for y while.
 * Los bucles detectados se almacenan en el vector loops_.
 * @param line La línea de código a analizar.
 * @param line_number El número de línea actual en el archivo.
 * @return void
 */
void Loop::SearchLoop(const std::string& line, int line_number) {
  std::regex loop_regex(
    R"((?:^|[^/])\b(for\s*\([^;()]+:[^;()]+\)|for\s*\([^;()]+;[^;()]+;[^;()]+\)|while\s*\([^)]*\))\s*\{)"
  );
  std::smatch match;
  if (std::regex_search(line, match, loop_regex)) {
    Loop loop;
    loop.line_ = line_number;
    if (line.find("for") != std::string::npos) {
      loop.type_ = "for";
      ++for_count_;
    } else if (line.find("while") != std::string::npos) {
      loop.type_ = "while";
      ++while_count_;
    }
    loops_.push_back(loop);
  }
}

/**
 * Sobrecarga del operador de salida para imprimir todos los bucles almacenados.
 * Imprime cada bucle con su tipo y línea.
 * @param os El stream de salida.
 * @param loop El objeto Loop que contiene los bucles a imprimir.
 * @return std::ostream& El stream de salida modificado.
 */
std::ostream& operator<<(std::ostream& os, const Loop& loop) {
  for (auto loop : loop.loops_) {
    os << "[Line " << loop.line_ << "] LOOP: " << loop.type_ << std::endl;
  }
  return os;
}