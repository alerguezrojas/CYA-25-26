// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 4: Expresiones regulares en C++
// Autor: Alejandro Rodríguez Rojas
// Correo: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo functions.h: Declaración de funciones auxiliares
// Referencias:
// Historial de revisiones
//   23/09/2025 - Creación del código versión 1.0

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "variable.h"
#include "loop.h"
#include "comment.h"

#include <iostream>
#include <fstream>
#include <string>

void PrintUsage();
void PrintHelp();

struct MatchResult {
  std::string program_name_;
  Variable variable_;
  Loop loop_;
  bool main_found_ = false;
  int line_number_ = 1;
  Comment line_comment_;
  Comment multiple_comment_;
};

bool CheckFile(const std::string& file_name);
bool CheckParameters(int argc, char* argv[]);
void ReadCode(const std::string& input_file, MatchResult& result);
void OutputResults(std::ostream& os, const MatchResult& result);
void PrintResults(const MatchResult& result);
void WriteResults(const std::string& output_file, const MatchResult& result);


#endif // FUNCTIONS_H