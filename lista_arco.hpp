#pragma once //Para que se incluya sólo una vez

#include "prototipos.hpp"
#include "estructuras.hpp"
template <typename Type> class lista_arco {
  Donde donde;
  arco<Type> *principio;
  arco<Type> *anterior;
  arco<Type> *lugar_agregado;
public:
  lista_arco() : principio(NULL), anterior(NULL), donde(INICIO){}
  ~lista_arco() {
    anterior = NULL;
    lugar_agregado = NULL;
    eliminar(principio);
  }
  bool buscar(const Type);
  void agregar(nodo<Type> *, const float);
  void pintar();
  arco<Type> *obtener_principio(){return principio;}
};
template <typename Type> bool lista_arco<Type>::buscar(const Type _nodo) {
  donde = INICIO;
  if (!principio) return false;
  arco<Type> *i = principio;
  donde = MIFA;
  while ( i && *i < _nodo) {anterior = i;i = i->sig;}
  if (i == principio) donde = INICIO;
  if ( i && *i == _nodo) {lugar_agregado = i;return true;}
  return false;
}
template <typename Type> void lista_arco<Type>::agregar(nodo<Type> *x, const float l) {
  if (buscar(x->id_nodo)) return;
  arco<Type> *nuevo_arco = new arco<Type>;
  lugar_agregado = nuevo_arco;
  nuevo_arco->dir_nodo = x;
  nuevo_arco->peso = l;
  if (donde == MIFA) {
    nuevo_arco->sig = anterior->sig;
    anterior->sig = nuevo_arco;
  } else {
    nuevo_arco->sig = principio;
    principio = nuevo_arco;
  }
}
template <typename Type> void lista_arco<Type>::pintar() {
  arco<Type> *i = principio;
  std::cout << "{ ";
  while (i) {
    std::cout << i->dir_nodo->id_nodo << "["<<i->peso<<"] ,";
    i = i->sig;
  }
  std::cout << "\b }";
}
