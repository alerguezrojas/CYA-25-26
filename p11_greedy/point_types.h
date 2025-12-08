// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 11: Algoritmos Voraces (Greedy). Euclidean Minimum Spanning Tree
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 09/12/2025
// Archivo point_types.h: Fichero que contiene las definiciones de los tipos de datos usados en el programa

#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <set>

#define MAX_SZ 3
#define MAX_PREC 0

namespace CyA {
    typedef std::pair<double, double> point;
    typedef std::pair<point, point> line;
    typedef std::vector<point> point_vector;
    
    // Un arco es un par de puntos
    typedef std::pair<point, point> arc;
    // Un arco ponderado es un par <peso, arco>
    typedef std::pair<double, arc> weigthed_arc;
    typedef std::vector<weigthed_arc> arc_vector;
    
    typedef std::set<point> point_collection;
    typedef std::vector<arc> tree;
}

std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps);
std::ostream& operator<<(std::ostream& os, const CyA::point& ps);

std::istream& operator>>(std::istream& is, CyA::point_vector& ps);
std::istream& operator>>(std::istream& is, CyA::point& ps);