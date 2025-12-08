// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 11: Algoritmos Voraces (Greedy). Euclidean Minimum Spanning Tree
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 09/12/2025
// Archivo sub_tree.cc: Fichero que contiene las definiciones de los métodos de la clase sub_tree

#include "sub_tree.h"
#include <algorithm>

namespace EMST {
    sub_tree::sub_tree(void) : arcs_(), points_(), cost_(0) {}
    
    sub_tree::~sub_tree(void) {}

    void sub_tree::add_arc(const CyA::arc &a) {
        arcs_.push_back(a);
        points_.insert(a.first);
        points_.insert(a.second);
    }

    void sub_tree::add_point(const CyA::point &p) {
        points_.insert(p);
    }

    bool sub_tree::contains(const CyA::point &p) const {
        return points_.find(p) != points_.end();
    }

    void sub_tree::merge(const sub_tree &st, const CyA::weigthed_arc &a) {
        // Añadir los arcos del otro subárbol
        arcs_.insert(arcs_.end(), st.arcs_.begin(), st.arcs_.end());
        // Añadir el arco que une ambos árboles
        arcs_.push_back(a.second);

        // Añadir los puntos del otro subárbol
        points_.insert(st.points_.begin(), st.points_.end());

        // Sumar costes: coste propio + coste del otro + coste de la unión
        cost_ += st.get_cost() + a.first;
    }
}