#include "point_set.h"
#include <algorithm>
#include <cmath>
#include <iomanip>

namespace CyA {

    point_set::point_set(const std::vector<point> &points) : point_vector(points) {}

    point_set::~point_set(void) {}

    void point_set::quickHull(void) {
        hull_.clear();
        if (empty()) return;

        CyA::point min_x_point;
        CyA::point max_x_point;

        x_bounds(min_x_point, max_x_point);

        quickHull(CyA::line(min_x_point, max_x_point), side::LEFT);
        quickHull(CyA::line(min_x_point, max_x_point), side::RIGHT);

        std::sort(hull_.begin(), hull_.end());
        hull_.erase(std::unique(hull_.begin(), hull_.end()), hull_.end());
    }

    void point_set::quickHull(const CyA::line &l, int side) {
        CyA::point farthest;
        if (farthest_point(l, side, farthest)) {
            quickHull(CyA::line(l.first, farthest), 
                      -find_side(CyA::line(l.first, farthest), l.second));
            quickHull(CyA::line(farthest, l.second), 
                      -find_side(CyA::line(farthest, l.second), l.first));
        } else {
            hull_.push_back(l.first);
            hull_.push_back(l.second);
        }
    }

    bool point_set::farthest_point(const CyA::line &l, int side, CyA::point &farthest) const {
        if (empty()) return false;
        farthest = at(0); 
        double max_dist = -1.0;
        bool found = false;

        for (const CyA::point &p : *this) {
            const double dist = distance(l, p);
            if (find_side(l, p) == side && dist > max_dist) {
                farthest = p;
                max_dist = dist;
                found = true;
            }
        }
        return found;
    }

    double point_set::point_2_line(const CyA::line &l, const CyA::point &p) const {
        const CyA::point &p1 = l.first;
        const CyA::point &p2 = l.second;
        return (p.second - p1.second) * (p2.first - p1.first) -
               (p2.second - p1.second) * (p.first - p1.first);
    }

    int point_set::find_side(const line &l, const point &p) const {
        double val = point_2_line(l, p);
        if (val > 0) return side::LEFT;
        if (val < 0) return side::RIGHT;
        return side::CENTER;
    }

    double point_set::distance(const CyA::line &l, const CyA::point &p) const {
        return std::abs(point_2_line(l, p));
    }

    void point_set::x_bounds(point &min_x, point &max_x) const {
        if (empty()) return;
        min_x = max_x = at(0);
        for (const auto &p : *this) {
            if (p.first < min_x.first) min_x = p;
            if (p.first > max_x.first) max_x = p;
        }
    }

    void point_set::write_hull(std::ostream &os) const {
        for (const auto &p : hull_) {
            os << "(" << p.first << ", " << p.second << ")" << std::endl;
        }
    }

    void point_set::write(std::ostream &os) const {
        for (const auto &p : *this) {
            os << "(" << p.first << ", " << p.second << ")" << std::endl;
        }
    }

    // ---------------------------------------------------------
    // IMPLEMENTACIÓN DE GRAPHVIZ
    // ---------------------------------------------------------
    void point_set::write_graphviz(std::ostream &os) const {
        os << "graph convex_hull {\n";
        os << "  node [shape=point, width=0.1, height=0.1];\n";
        
        // 1. Dibujar TODOS los puntos como nodos negros
        // Usamos las coordenadas como ID del nodo "x_y"
        for (const auto &p : *this) {
            os << "  \"" << p.first << "_" << p.second << "\" [pos=\"" 
               << p.first << "," << p.second << "!\"];\n";
        }

        // 2. Preparar la envoltura para dibujar las aristas
        // Copiamos la envoltura para no modificar la original
        point_vector sorted_hull = hull_;
        
        if (!sorted_hull.empty()) {
            // Calculamos el centroide para ordenar angularmente
            double cx = 0.0, cy = 0.0;
            for (const auto &p : sorted_hull) { cx += p.first; cy += p.second; }
            cx /= sorted_hull.size();
            cy /= sorted_hull.size();

            // Ordenamos angularmente respecto al centroide
            std::sort(sorted_hull.begin(), sorted_hull.end(), 
                [cx, cy](const point &a, const point &b) {
                    return std::atan2(a.second - cy, a.first - cx) < 
                           std::atan2(b.second - cy, b.first - cx);
                });

            // 3. Dibujar aristas rojas conectando los puntos ordenados
            os << "  edge [color=red, penwidth=2.0];\n";
            for (size_t i = 0; i < sorted_hull.size(); ++i) {
                const point &p1 = sorted_hull[i];
                // El siguiente punto (usando módulo para cerrar el ciclo al final)
                const point &p2 = sorted_hull[(i + 1) % sorted_hull.size()];
                
                os << "  \"" << p1.first << "_" << p1.second << "\" -- \"" 
                   << p2.first << "_" << p2.second << "\";\n";
            }
        }
        os << "}\n";
    }

}