// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 11: Algoritmos Voraces (Greedy). Euclidean Minimum Spanning Tree
// Autor: Alejandro Rodríguez Rojas
// Correro: alu0101317038@ull.edu.es
// Fecha de entrega: 09/12/2025
// Archivo point_set.cc: Fichero que contiene las definiciones de los métodos de la clase point_set

#include "point_set.h"
#include <cmath>
#include <algorithm>
#include <iomanip>

point_set::point_set(const CyA::point_vector &points) : CyA::point_vector(points), emst_cost_(0.0) {}

point_set::~point_set(void) {}

void point_set::EMST(void) {
    CyA::arc_vector av; // Vector de arcos con pesos para Kruskal
    compute_arc_vector(av); // Calcula las distancias entre todos los puntos (las ordena de menor a mayor)

    forest st;

    // Inicialmente cada punto es un subárbol
    for (const CyA::point &p : *this) {
        EMST::sub_tree s;
        s.add_point(p);
        st.push_back(s);
    }

    // Algoritmo de Kruskal
    for (const CyA::weigthed_arc &a : av) {
        int i, j; // Índices de los subárboles incidentes
        find_incident_subtrees(st, a.second, i, j);

        if (i != j) { // Si son distintos subárboles, los unimos
            merge_subtrees(st, a.second, i, j); // si ya  estan unidos, se descarta el arco
        }
    }

    // Al finalizar, el bosque debería tener un solo componente (el EMST)
    if (!st.empty()) {
        emst_ = st[0].get_arcs(); // Obtener los arcos del EMST
        emst_cost_ = st[0].get_cost(); // Obtener el coste total del EMST
    }
}

void point_set::compute_arc_vector(CyA::arc_vector &av) const {
    av.clear();
    const int n = size();

    for (int i = 0; i < n - 1; ++i) {
        const CyA::point &p_i = (*this)[i];
        for (int j = i + 1; j < n; ++j) {
            const CyA::point &p_j = (*this)[j];
            const double dist = euclidean_distance({p_i, p_j});
            av.push_back({dist, {p_i, p_j}});
        }
    }
    std::sort(av.begin(), av.end()); // Ordenar por peso (first del pair)
}

void point_set::find_incident_subtrees(const forest& st, const CyA::arc &a, int& i, int& j) const {
    i = -1;
    j = -1;
    for (int k = 0; k < st.size(); ++k) {
        if (st[k].contains(a.first)) i = k;
        if (st[k].contains(a.second)) j = k;
        if (i != -1 && j != -1) break;
    }
}

void point_set::merge_subtrees(forest& st, const CyA::arc &a, int i, int j) const {
    // Fusionar j dentro de i
    st[i].merge(st[j], {euclidean_distance(a), a});
    // Eliminar el subárbol j (importante usar iterador para erase)
    st.erase(st.begin() + j);
}

double point_set::euclidean_distance(const CyA::arc& a) const {
    return std::sqrt(std::pow(a.first.first - a.second.first, 2) + 
                     std::pow(a.first.second - a.second.second, 2));
}

double point_set::compute_cost(void) const {
    return emst_cost_;
}

void point_set::write(std::ostream &os) const {
    // Formato específico del output ejemplo
    for (const auto& arc : emst_) {
        os << "(" << std::setw(MAX_SZ) << arc.first.first << ", " 
           << std::setw(MAX_SZ) << arc.first.second << ") -> "
           << "(" << std::setw(MAX_SZ) << arc.second.first << ", " 
           << std::setw(MAX_SZ) << arc.second.second << ")" << std::endl;
    }
    os << std::endl << std::fixed << std::setprecision(2) << get_cost() << std::endl;
}

void point_set::write_dot(std::ostream &os) const {
    os << "graph {" << std::endl;
    
    // Escribir nodos con posición
    for (size_t i = 0; i < size(); ++i) {
        os << " " << i << " [pos = \"" 
           << (*this)[i].first << "," << (*this)[i].second << "!\"]" << std::endl;
    }
    os << std::endl;

    // Escribir arcos usando índices
    for (const auto& arc : emst_) {
        int idx1 = -1, idx2 = -1;
        // Buscar índices originales de los puntos
        for(size_t i = 0; i < size(); ++i) {
            if((*this)[i] == arc.first) idx1 = i;
            if((*this)[i] == arc.second) idx2 = i;
        }
        if(idx1 != -1 && idx2 != -1)
            os << " " << idx1 << " -- " << idx2 << std::endl;
    }
    os << "}" << std::endl;
}

void point_set::write_tree(std::ostream &os) const {
    write(os);
}