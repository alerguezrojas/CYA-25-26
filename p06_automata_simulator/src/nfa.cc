// nfa.cc
#include "nfa.h"

NFA::NFA(const Alphabet& alphabet,
         const std::set<State>& states,
         const State& start_state,
         const std::set<State>& accept_states,
         const std::set<Transition>& transitions) {
  // Usamos los setters heredados de Automata
  SetAlphabet(alphabet);
  SetStates(states);
  SetStartState(start_state);
  SetAcceptStates(accept_states);
  SetTransitions(transitions);
}

const State* NFA::FindState(const std::string& id) const {
  for (const auto& s : states_) {
    if (s.GetStateId() == id) return &s;
  }
  return nullptr;
}

std::set<std::string> NFA::EpsilonClosure(const std::set<std::string>& state_ids) const {
  std::set<std::string> closure = state_ids;
  std::stack<std::string> st;
  for (const auto& id : state_ids) st.push(id);

  Symbol eps('&');
  while (!st.empty()) {
    std::string sid = st.top();
    st.pop();
    const State* s = FindState(sid);
    if (!s) continue;

    auto eps_trans = s->GetTransitions(eps);
    for (const auto& t : eps_trans) {
      const std::string& dest = t.GetDestinationId();
      if (!closure.count(dest)) {
        closure.insert(dest);
        st.push(dest);
      }
    }
  }
  return closure;
}

std::set<std::string> NFA::Move(const std::set<std::string>& from, const Symbol& a) const {
  std::set<std::string> result;
  for (const auto& sid : from) {
    const State* s = FindState(sid);
    if (!s) continue;
    auto trans = s->GetTransitions(a);
    for (const auto& t : trans) {
      result.insert(t.GetDestinationId());
    }
  }
  return result;
}


bool NFA::ReadChains(const Chain& chain) const {
  // Estado inicial → ε-closure({q0})
  std::set<std::string> current = { start_state_.GetStateId() };
  current = EpsilonClosure(current);

  // Recorrer los símbolos de la cadena
  for (const auto& sym : chain.GetChain()) {
    if (sym.GetSymbol() == '&') continue;  // '&' no se consume
    if (!alphabet_.Contains(sym)) {
      return false;  // símbolo fuera del alfabeto → rechazo inmediato
    }

    // Transiciones: Move + ε-closure
    auto next = Move(current, sym);
    current = EpsilonClosure(next);

    if (current.empty()) break;
  }

  // Aceptación: si alguno de los estados actuales es final
  for (const auto& sid : current) {
    for (const auto& acc : accept_states_) {
      if (sid == acc.GetStateId()) {
        return true;
      }
    }
  }
  return false;
}
