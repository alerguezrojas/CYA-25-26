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