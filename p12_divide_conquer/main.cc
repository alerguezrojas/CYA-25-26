#include <iostream>
#include <vector>
#include <string>
#include "point_set.h"

// g++ -o p12_divide_conquer main.cc point_set.cc
// ./p12_divide_conquer < input1.txt
// ./p12_divide_conquer -d < input1.txt > output1.dot
// neato -Tpdf output1.dot -o output1.pdf


int main(int argc, char* argv[]) {
    // 1. Comprobar argumentos de línea de comandos
    bool dot_mode = false;
    
    // Si hay un argumento y es "-d", activamos modo DOT
    if (argc > 1 && std::string(argv[1]) == "-d") {
        dot_mode = true;
    }

    // 2. Lectura de puntos desde entrada estándar (cin)
    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<CyA::point> points;
    points.reserve(n);

    double x, y;
    for (int i = 0; i < n; ++i) {
        std::cin >> x >> y;
        points.push_back({x, y});
    }

    // 3. Ejecutar algoritmo Quickhull
    CyA::point_set ps(points);
    ps.quickHull();

    // 4. Salida según el modo elegido
    if (dot_mode) {
        // Opción -d: Salida en formato DOT para Graphviz
        ps.write_graphviz(std::cout);
    } else {
        // Por defecto: Salida en formato numérico (x, y)
        ps.write_hull(std::cout);
    }

    return 0;
}