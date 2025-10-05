// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 4: Expresiones regulares en C++
// Autor: Alejandro Rodríguez Rojas
// Correo: alu0101317038@ull.edu.es
// Fecha de entrega: 23/09/2025
// Archivo functions.cc: Implementación de funciones auxiliares
// Referencias:
// Historial de revisiones
//   23/09/2025 - Creación del código versión 1.0

#include "functions.h"

void PrintUsage() {
  std::cout << "Modo de empleo: ./p04_code_analyzer [code.cc] [codescheme.txt]\n"
            << "Pruebe './p04_code_analyzer --help' para más información.\n";
}

void PrintHelp() {
    std::cout << "Modo de empleo: ./p04_code_analyzer [code.cc] [codescheme.txt]\n"
              << "Este programa lee un código C++ y lo analiza utilizando expresiones "
                 "regulares. Recibirá por línea de comandos el nombre del archivo de "
                 "entrada (código C++ a analizar) y el nombre del archivo de salida "
                 "(que contendrá el archivo analizado). La información que este programa "
                 "extraerá es la declaración de variables int y double, bucles for y while, "
                 "detectará si contiene una función main() y los diferentes comentarios de "
                 "una línea o de múltiples líneas." << std::endl;
}

bool CheckFile(const std::string& file_name) {
  std::ifstream file(file_name);
  if (!file) {
    std::cerr << "Error: no se pudo abrir el fichero '" << file_name << "'.\n";
    return false;
  }
  file.close();
  return true;
}

bool CheckParameters(int argc, char* argv[]) {
  if (argc == 1) {
    PrintUsage();
    return false;
  }
  if (argc == 2 &&
    (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h")) {
    PrintHelp();
    return false;
  }
  if (argc != 3) {
    PrintUsage();
    return false;
  }
  return true;
}

void ReadCode(const std::string& input_file, MatchResult& result) {
  std::ifstream fin(input_file);
  if (!fin) {
    std::cerr << "Error: no se pudo abrir el fichero de entrada '"
              << input_file << "'.\n";
    return;
  }

  std::string line;
  int line_number = 0;

  while (std::getline(fin, line)) {
    ++line_number;
    if (line.empty()) continue;

    result.line_comment_.SearchComment(line, line_number);
    result.multiple_comment_.SearchComment(line, line_number);
    result.variable_.SearchVariable(line, line_number);
    result.loop_.SearchLoop(line, line_number);
    if (!result.main_found_) {
      std::regex main_regex("\\s*int\\s*main\\s*\\(.*\\).*");
      if (std::regex_search(line, main_regex)) {
        result.main_found_ = true;
        result.line_number_ = line_number;
      }
    }
  }
} // The file closes automatically when its destructor is called

void OutputResults(std::ostream& out, MatchResult& result) {
  out << "PROGRAM: " << result.program_name_ << std::endl;
  out << "DESCRIPTION: " << std::endl;
  std::string description = result.line_comment_.PrintDescription();
  out << (description.empty() ? "False" : description) << std::endl;
  out << "\nVARIABLES: " << std::endl;
  out << result.variable_;
  out << "\nSTATEMENTS: " << std::endl;
  out << result.loop_;
  out << "\nMAIN FUNCTION:\n" << (result.main_found_ ? "True" : "False") << std::endl;
  out << "\nCOMMENTS: " << std::endl;
  out << result.line_comment_;
}

void PrintResults(const MatchResult& result) {
  OutputResults(std::cout, const_cast<MatchResult&>(result));
}

void WriteResults(const std::string& output_file, const MatchResult& result) {
  std::ofstream fout(output_file);
  if (!fout) {
    std::cerr << "Error: no se pudo abrir el fichero de salida '"
              << output_file << "'.\n";
    return;
  }
  OutputResults(fout, const_cast<MatchResult&>(result));
} // The file closes automatically when its destructor is called

