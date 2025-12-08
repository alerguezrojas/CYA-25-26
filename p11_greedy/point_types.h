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