#pragma once
#include "lista_arco.hpp"
template <typename Type> class lista_nodo {
  Donde donde;
  nodo<Type> *principio;
  nodo<Type> *anterior;
  nodo<Type> *lugar_agregado;
public:
  lista_nodo() : principio(NULL), anterior(NULL), lugar_agregado(NULL){}
  ~lista_nodo() {
    anterior = NULL;
    lugar_agregado = NULL;
    eliminar(principio);
  }
  bool buscar(const Type);
  void agregar(const Type);
  void pintar();
  nodo<Type> *obtener_agregado(){return lugar_agregado;}
};
template <typename Type> bool lista_nodo<Type>::buscar(const Type x) {
  donde = INICIO;
  if (!principio) return false;
  donde = MIFA;
  nodo<Type> *i = principio;
  while (i && *i < x) {anterior = i; i = i->sig;}
  if (i == principio) donde = INICIO;
  if (i && *i == x) {lugar_agregado = i;return true;}
  return false;
}
template <typename Type> void lista_nodo<Type>::agregar(const Type x) {
  if (buscar(x)) return;
  nodo<Type> *i = new nodo<Type>;
  i->id_nodo = x;
  i->saliente = new lista_arco<Type>;
  lugar_agregado = i;
  i->estado = NO_TOCADO;
  i->ant = NULL;
  i->sig = NULL;
  if (donde == MIFA) {
    i->sig = anterior->sig;
    anterior->sig = i;
  } else {
    i->sig = principio;
    principio = i;
  }
}
template <typename Type> void lista_nodo<Type>::pintar() {
  nodo<Type> *i = principio;
  while (i) {
    std::cout << "Nodo: " << i->id_nodo << std::endl;
    std::cout << "Salientes: "; i->saliente->pintar(); std::cout << std::endl;
    i = i->sig;
  }
}
