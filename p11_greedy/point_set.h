#pragma once

#include "point_types.h"
#include "sub_tree.h"
#include <vector>

typedef std::vector<EMST::sub_tree> forest;

class point_set : public CyA::point_vector {
private:
    CyA::tree emst_;
    double emst_cost_; // Variable auxiliar para guardar el coste final

public:
    point_set(const CyA::point_vector &points);
    ~point_set(void);

    void EMST(void);

    void write_tree(std::ostream &os) const;
    void write(std::ostream &os) const;
    void write_dot(std::ostream &os) const; // Para el opcional -d

    inline const CyA::tree& get_tree(void) const { return emst_; }
    inline const CyA::point_vector& get_points(void) const { return *this; }
    inline double get_cost(void) const { return emst_cost_; }

private:
    void compute_arc_vector(CyA::arc_vector &av) const;
    void find_incident_subtrees(const forest& st, const CyA::arc &a, int& i, int& j) const;
    void merge_subtrees(forest& st, const CyA::arc &a, int i, int j) const;

    double compute_cost(void) const;
    double euclidean_distance(const CyA::arc& a) const;
};