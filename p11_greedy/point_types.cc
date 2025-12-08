// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 11: Algoritmos Voraces (Greedy). Euclidean Minimum Spanning Tree
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 09/12/2025
// Archivo point_types.cc: Fichero que contiene las definiciones de los tipos de datos usados en el programa

#include "point_types.h"
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps) {
    os << ps.size() << std::endl;
    for (const CyA::point &p : ps) {
        os << p << std::endl;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const CyA::point& p) {
    os << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) 
       << p.first << "\t" 
       << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) 
       << p.second;
    return os;
}

std::istream& operator>>(std::istream& is, CyA::point_vector& ps) {
    int n;
    is >> n;
    ps.clear();
    for (int i = 0; i < n; ++i) {
        CyA::point p;
        is >> p;
        ps.push_back(p);
    }
    return is;
}

std::istream& operator>>(std::istream& is, CyA::point& p) {
    is >> p.first >> p.second;
    return is;
}