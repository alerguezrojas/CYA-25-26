// nfa.h
#ifndef NFA_H
#define NFA_H

#include <set>
#include <map>
#include <stack>
#include <string>
#include <iostream>

#include "automata.h"
#include "state.h"
#include "transition.h"
#include "symbol.h"
#include "chain.h"

/**
 * @brief Clase que representa un autómata finito no determinista (NFA),
 *        con soporte para transiciones ε (representadas como '&').
 * 
 * Hereda de Automata e implementa el método ReadChains(), que simula
 * el comportamiento del NFA para una cadena dada.
 */
class NFA : public Automata {
 public:
  NFA() = default;

  /**
   * @brief Constructor que inicializa el NFA a partir de sus componentes.
   */
  NFA(const Alphabet& alphabet,
      const std::set<State>& states,
      const State& start_state,
      const std::set<State>& accept_states,
      const std::set<Transition>& transitions);

  /**
   * @brief Simula la lectura de una cadena sobre el NFA.
   * @param chain Cadena de entrada a evaluar.
   * @return true si la cadena es aceptada; false si es rechazada.
   */
  bool ReadChains(const Chain& chain) const override;

 private:
  /**
   * @brief Calcula el ε-closure de un conjunto de estados.
   * @param state_ids Conjunto de estados inicial.
   * @return Conjunto de estados alcanzables mediante ε-transiciones.
   */
  std::set<std::string> EpsilonClosure(const std::set<std::string>& state_ids) const;

  /**
   * @brief Devuelve los estados alcanzables desde un conjunto dado al leer un símbolo.
   * @param from Estados origen.
   * @param a Símbolo a consumir.
   * @return Conjunto de estados alcanzables.
   */
  std::set<std::string> Move(const std::set<std::string>& from, const Symbol& a) const;

  /**
   * @brief Busca un estado por su identificador dentro del conjunto de estados.
   * @param id Identificador del estado.
   * @return Puntero al estado encontrado o nullptr si no existe.
   */
  const State* FindState(const std::string& id) const;
};

#endif  // NFA_H
