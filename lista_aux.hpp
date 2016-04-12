#pragma once

#include "prototipos.hpp"
#include "estructuras.hpp"

template <typename Type> class lista_aux {
  Donde donde;
  nodo_en_lista<Type> *principio;
  nodo_en_lista<Type> *anterior;
  nodo_en_lista<Type> *lugar_agregado;
public:
  lista_aux() : principio(NULL), anterior(NULL), lugar_agregado(NULL){}
  ~lista_aux() {
    anterior = NULL;
    lugar_agregado = NULL;
    eliminar(principio);
  }
  void pintar();
  void buscar(float);
  void agregar(nodo<Type>*);
  void ajustar(nodo_en_lista<Type>*);
  nodo<Type> *sacar_primero();
};
template <typename Type> void lista_aux<Type>::ajustar(nodo_en_lista<Type> *n) {
  if (!n->ant || n->ant->dir_nodo->ruta_corta < n->dir_nodo->ruta_corta) return;

  nodo_en_lista<Type> *i = n->ant;

  n->ant->sig = n->sig;
  if (n->sig) n->sig->ant = n->ant;
  while (i && i > n) i = i->ant;

  n->ant = i;
  if (i) {
    n->sig = i->sig;
    i->sig->ant = n;
    i->sig = n;
  } else {
    n->sig = principio;
    principio->ant = n;
    principio = n;
  }
}
template <typename Type> void lista_aux<Type>::buscar(float x) {
  donde = INICIO;
  if (!principio) return;
  donde = MIFA;
  nodo_en_lista<Type> *i = principio;
  while( i &&  *i < x ) {anterior = i; i = i->sig;}
  if   (i == principio) donde = INICIO;
}
template <typename Type> void lista_aux<Type>::agregar(nodo<Type> *x) {
  buscar(x->ruta_corta);
  nodo_en_lista<Type> *i = new nodo_en_lista<Type>;
  lugar_agregado = i;
  x->dir_nodo_en_lista = i;
  i->dir_nodo = x;
  i->sig = NULL;
  i->ant =NULL;

  if (donde == MIFA) {
    i->sig = anterior->sig;
    i->ant = anterior;
    anterior->sig = i;
    if (i->sig)i->sig->ant = i;
  } else {
    i->sig = principio;
    if (principio) principio->ant = i;
    principio = i;
  }
}
template <typename Type> nodo<Type> *lista_aux<Type>::sacar_primero() {
  if (!principio) return NULL;
  nodo_en_lista<Type> *i = principio;
  principio = i->sig;

  if (principio) principio->ant = NULL;

  nodo<Type> *x = i->dir_nodo;
  x->dir_nodo_en_lista = NULL;
  delete i;
  return x;
}
template <typename Type> void lista_aux<Type>::pintar() {
  nodo_en_lista<Type> *i = principio;
  while (i) {
    std::cout << i->dir_nodo->id_nodo << "[" << i->dir_nodo->ruta_corta << "]" << "->";
    i = i->sig;
  }
  std::cout << "\b\b  "<< std::endl;
}
