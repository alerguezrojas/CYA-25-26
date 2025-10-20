// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 21/10/2025
// Archivo functions.h: Fichero que contiene las declaraciones de las funciones auxiliares
// Referencias:
// Historial de revisiones
//   19/10/2025 - Creacion del codigo version 1.0

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <optional>

#include "nfa.h"
#include "chain.h"

void PrintUsage(const std::string& prog);
void PrintHelp(const std::string& prog);
std::optional<NFA> LoadNFAFromFile(const std::string& path, std::string& error_out);
std::vector<std::pair<std::string, Chain>> LoadChainsFromTxt(
    const std::string& path, std::string& error_out);
void SimulateAndReport(const NFA& nfa, const std::vector<std::pair<std::string, 
                       Chain>>& inputs);

#endif  // FUNCTIONS_H
