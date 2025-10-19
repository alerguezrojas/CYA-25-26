// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <optional>

#include "nfa.h"
#include "chain.h"

/**
 * @brief Muestra el modo de empleo básico.
 */
void PrintUsage(const std::string& prog);

/**
 * @brief Muestra la ayuda (--help).
 */
void PrintHelp(const std::string& prog);

/**
 * @brief Lee un fichero .fa y construye un NFA.
 * @param path Ruta del fichero .fa
 * @param error_out Mensaje de error (si ocurre)
 * @return NFA válido o std::nullopt si hay error.
 */
std::optional<NFA> LoadNFAFromFile(const std::string& path, std::string& error_out);

/**
 * @brief Lee un fichero .txt con cadenas (una por línea).
 *        Cada línea puede tener formato:
 *        "1 cadena" o simplemente "cadena".
 *        La cadena vacía se representa como '&'.
 * @return vector de pares {etiqueta, Chain}.
 */
std::vector<std::pair<std::string, Chain>> LoadChainsFromTxt(
    const std::string& path,
    std::string& error_out);

/**
 * @brief Ejecuta la simulación de las cadenas sobre el NFA y muestra los resultados.
 */
void SimulateAndReport(const NFA& nfa,
                       const std::vector<std::pair<std::string, Chain>>& inputs);

#endif  // FUNCTIONS_H
