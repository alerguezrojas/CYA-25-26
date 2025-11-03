// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 04/11/2025
// Archivo functions.h: Fichero que contiene la definición de funciones auxiliares
// Referencias:
// Historial de revisiones
//   03/11/2025 - Creacion del codigo version 1.0

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "alphabet.h"
#include "string.h"
#include "grammar.h"

const char SPACE = ' ';

const std::string kHowUse =
    std::string(
        "How to use: ./bin/p08_Grammar2CNF data/input.gra data/output.gra\n"
        "Try './bin/p08_Grammar2CNF --help || -h' for more information.");

const std::string kHelp =
    std::string(
        "Usage: ./bin/p08_grammar_converter data/grammar_file.gra data/output_grammar_file.gra\n"
        "\n"
        "Converts a context-free grammar to Chomsky normal form.\n"
        "\n"
        "Options:\n"
        "  -h, --help    Show this help message and exit\n"
        "\n"
        "Arguments:\n"
        "  grammar_file.gra    File containing the context-free grammar\n"
        "\n"
        "Description:\n"
        "  This program allows you to convert a context-free grammar specified by an input file\n"
        "  to Chomsky normal form. The program will read from a file the production rules of the grammar\n"
        "  and then convert it to Chomsky normal form.\n"
        "\n"
        "  The grammar file should have the following format:\n"
        "    - The first line contains the number of terminals.\n"
        "    - The next lines contain the terminal symbols.\n"
        "    - The next line contains the number of non-terminals.\n"
        "    - The next lines contain the non-terminal symbols.\n"
        "    - The next line contains the number of production rules.\n"
        "    - The next lines contain the production rules in the format \"left_side right_side\".\n"
        "\n"
        "Example of a file specifying a context-free grammar:\n"
        "  3\n"
        "  a\n"
        "  b\n"
        "  c\n"
        "  4\n"
        "  S\n"
        "  A\n"
        "  B\n"
        "  C\n"
        "  4\n"
        "  S A\n"
        "  S B\n"
        "  A a\n"
        "  B b "
        "  B C\n"
        "  C c\n");

bool check_parameters(int argc, char* argv[]);
bool check_file(std::string file_name);
template <typename T>
std::vector<T> read_file(const std::string& file_name);
void write_file(const std::string& file_name, const Grammar& grammar);

#endif  // FUNCTIONS_H