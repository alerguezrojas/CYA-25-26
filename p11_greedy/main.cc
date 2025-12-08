#include <iostream>
#include <fstream>
#include <string>
#include "point_set.h"
#include "point_types.h"

// FUNCIONAMIENTO:
// g++ -o p11_greedy main.cc point_types.cc sub_tree.cc point_set.cc -O2
// ./p11_greedy < input1.txt
// ./p11_greedy -d < input1.txt > output1.dot
// neato output1.dot -Tpdf -o output1.pdf

int main(int argc, char* argv[]) {
    CyA::point_vector points;
    
    // Lectura desde entrada estándar
    std::cin >> points;

    // Ejecución del algoritmo
    point_set ps(points);
    ps.EMST();

    // Verificación de argumentos para salida DOT opcional
    bool dot_output = false;
    if (argc > 1 && std::string(argv[1]) == "-d") {
        dot_output = true;
    }

    if (dot_output) {
        ps.write_dot(std::cout);
    } else {
        ps.write(std::cout);
    }

    return 0;
}