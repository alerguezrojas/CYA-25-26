// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2°
// Práctica 4: Expresiones regulares en C++
// Autor: Alejandro Rodríguez Rojas
// Correo: alu0101317038@ull.edu.es
// Fecha de entrega: 14/10/2025
// Archivo functions.cc: Implementación de funciones auxiliares (versión corregida)
// Referencias:
// Historial de revisiones
//   06/10/25 - Versión final ajustada al formato del enunciado
//   07/10/25 - Añadido filtrado de comentarios para evitar falsos positivos en main, variables y bucles

#include "functions.h"
#include <regex>
#include <filesystem>
#include <sstream>

/**
 * Imprime el uso correcto del programa.
 * @return void
 */
void PrintUsage() {
  std::cout << "Modo de empleo: ./p04_code_analyzer [data/factorial.cc] [data/salida.txt]\n"
            << "Pruebe './p04_code_analyzer --help' para más información.\n";
}

/**
 * Imprime la ayuda del programa, describiendo su funcionalidad.
 * @return void
 */
void PrintHelp() {
  std::cout
      << "Modo de empleo: ./p04_code_analyzer [data/factorial.cc] [data/salida.txt]\n"
      << "Este programa analiza un código C++ utilizando expresiones regulares.\n"
      << "Detecta:\n"
      << " - Declaraciones de variables int y double.\n"
      << " - Bucles for y while.\n"
      << " - Existencia de la función main().\n"
      << " - Comentarios de una línea y de bloque (/* ... */), incluyendo la descripción inicial.\n";
}

/**
 * Verifica si un archivo existe y es accesible.
 * @param file_name El nombre del archivo a verificar.
 * @return true Si el archivo existe y es accesible.
 * @return false Si el archivo no existe o no es accesible.
 */
bool CheckFile(const std::string& file_name) {
  std::ifstream file(file_name);
  if (!file) {
    std::cerr << "Error: no se pudo abrir el fichero '" << file_name << "'.\n";
    return false;
  }
  return true;
}

/**
 * Verifica los parámetros de entrada del programa.
 * Deben ser exactamente 2: archivo de entrada y archivo de salida.
 * @param argc El número de argumentos.
 * @param argv Los argumentos del programa.
 * @return true Si los parámetros son correctos.
 * @return false Si los parámetros son incorrectos o se solicita ayuda.
 */
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

/**
 * Limpia el código fuente de comentarios, preservando la numeración de líneas.
 * Maneja comentarios de una línea (//) y bloques de comentarios (/* ... * /).
 * También preserva literales de cadena y caracteres para evitar falsos positivos.
 * @param text El código fuente completo como una cadena.
 * @return std::string El código limpio sin comentarios.
 */
std::string CleanCode(const std::string& text) {
  std::string out;
  out.reserve(text.size());

  bool in_line_comment = false;
  bool in_block_comment = false;
  bool in_string = false; // dentro de "... "
  bool in_char = false;   // dentro de '...'
  const size_t n = text.size();

  for (size_t i = 0; i < n; ++i) {
    char c = text[i];
    char next = (i + 1 < n) ? text[i + 1] : '\0';

    // 1) Si estamos en comentario de línea: saltar hasta '\n' pero conservar '\n'
    if (in_line_comment) {
      if (c == '\n') {
        in_line_comment = false;
        out.push_back('\n'); // preserva numeración
      }
      continue;
    }

    // 2) Si estamos en comentario de bloque: saltar todo, pero copiar '\n'
    if (in_block_comment) {
      if (c == '\n') out.push_back('\n'); // preserva numeración
      if (c == '*' && next == '/') {      // fin del bloque
        in_block_comment = false;
        ++i; // saltar '/'
      }
      continue;
    }

    // 3) Literales: copiar tal cual y atender escapes
    if (in_string) {
      out.push_back(c);
      if (c == '\\' && i + 1 < n) { out.push_back(text[++i]); }
      else if (c == '"') { in_string = false; }
      continue;
    }
    if (in_char) {
      out.push_back(c);
      if (c == '\\' && i + 1 < n) { out.push_back(text[++i]); }
      else if (c == '\'') { in_char = false; }
      continue;
    }

    // 4) Apertura de comentarios (solo si no estamos en literal)
    if (c == '/' && next == '/') { in_line_comment = true; ++i; continue; }
    if (c == '/' && next == '*') { in_block_comment = true; ++i; continue; }

    // 5) Apertura de literales
    if (c == '"')  { in_string = true; out.push_back(c); continue; }
    if (c == '\'') { in_char = true;   out.push_back(c); continue; }

    // 6) Carácter normal
    out.push_back(c);
  }

  return out;
}

/**
 * Lee el código fuente desde un archivo, analiza su contenido y llena el resultado.
 * Analiza variables, bucles, existencia de main y comentarios.
 * @param input_file El nombre del archivo de entrada.
 * @param result La estructura MatchResult donde se almacenan los resultados.
 * @return void
 */
void ReadCode(const std::string& input_file, MatchResult& result) {
  std::ifstream fin(input_file);
  if (!fin) {
    std::cerr << "Error: no se pudo abrir el fichero de entrada '"
              << input_file << "'.\n";
    return;
  }

  // Guardamos todo el contenido en memoria
  std::ostringstream buffer;
  buffer << fin.rdbuf();
  std::string full_text = buffer.str();

  // Analizamos los comentarios por separado (mantiene el comportamiento previo)
  std::istringstream original_stream(full_text);
  std::string original_line;
  int line_number = 0;
  while (std::getline(original_stream, original_line)) {
    ++line_number;
    result.line_comment_.SearchComment(original_line, line_number);
  }

  // Limpiamos el texto de comentarios antes de buscar variables/bucles/main
  std::string cleaned_code = CleanCode(full_text);
  std::istringstream code_stream(cleaned_code);

  std::string line;
  int code_line_number = 0;

  while (std::getline(code_stream, line)) {
    ++code_line_number;
    if (line.empty()) continue;

    // Buscar variables y bucles solo en código limpio
    result.variable_.SearchVariable(line, code_line_number);
    result.loop_.SearchLoop(line, code_line_number);

    // Detección de función main (solo si aún no fue encontrada)
    if (!result.main_found_) {
      std::regex main_regex(R"(\bint\s+main\s*\()");
      if (std::regex_search(line, main_regex)) {
        result.main_found_ = true;
        result.line_number_ = code_line_number;
      }
    }
  }
}

/**
 * Escribe los resultados del análisis en un stream de salida.
 * Formatea la salida según el formato especificado en el enunciado.
 * @param out El stream de salida (puede ser std::cout o un archivo).
 * @param result La estructura MatchResult que contiene los resultados.
 * @return void
 */
void OutputResults(std::ostream& out, MatchResult& result) {
  // Obtener solo el nombre del fichero de entrada (sin ruta)
  std::string file_name = result.program_name_;
  size_t pos = file_name.find_last_of("/\\");
  if (pos != std::string::npos) file_name = file_name.substr(pos + 1);

  out << "PROGRAM: " << file_name << "\n\n";

  out << "DESCRIPTION:\n";
  std::string description = result.line_comment_.PrintDescription();
  if (description.empty()) {
    out << "No description found.\n\n";
  } else {
    out << description << "\n";
  }

  out << "VARIABLES:\n";
  out << result.variable_ << "\n";

  out << "STATEMENTS:\n";
  out << result.loop_ << "\n";

  out << "MAIN:\n";
  out << (result.main_found_ ? "True" : "False") << "\n\n";

  out << "COMMENTS:\n";
  out << result.line_comment_;
}

/**
 * Imprime los resultados del análisis en la salida estándar.
 * @param result La estructura MatchResult que contiene los resultados.
 * @return void
 */
void PrintResults(const MatchResult& result) {
  OutputResults(std::cout, const_cast<MatchResult&>(result));
}

/**
 * Escribe los resultados del análisis en un archivo.
 * @param output_file El nombre del archivo de salida.
 * @param result La estructura MatchResult que contiene los resultados.
 * @return void
 */
void WriteResults(const std::string& output_file, const MatchResult& result) {
  std::ofstream fout(output_file);
  if (!fout) {
    std::cerr << "Error: no se pudo abrir el fichero de salida '"
              << output_file << "'.\n";
    return;
  }
  OutputResults(fout, const_cast<MatchResult&>(result));
}
