// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 2: Cadenas y lenguajes
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo functions.h: Declaración de funciones auxiliares
// Referencias:
// Historial de revisiones
//   23/09/2025 - Creacion del codigo version 1.0

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "symbol.h"
#include "alphabet.h"
#include "chain.h"
#include "language.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void PrintUsage();
void PrintHelp();
void ProcessFile(const std::string& input_file, const std::string& output_file, int opcode);

#endif  // FUNCTIONS_H
