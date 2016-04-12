#pragma once
#include "lista_nodo.hpp"
#include "prototipos.hpp"
#include "estructuras.hpp"
#include "lista_aux.hpp"
template <typename Type> class grafo {
  lista_nodo<Type> *ListaNodo;
  lista_aux<Type> *ListaAux;
  bool hay_ruta_corta;
public:
  grafo() : hay_ruta_corta(false){
    ListaNodo = new lista_nodo<Type>;
    ListaAux = new lista_aux<Type>;
  }
  ~grafo() {delete ListaNodo;delete ListaAux;}
  void agregar(const Type, const Type, const float);
  void ruta_corta() { if (hay_ruta_corta) ListaAux->pintar(); }
  void obten_ruta_corta(const Type, const Type);
  void pintar(){return ListaNodo->pintar();}
};
template <typename Type> void grafo<Type>::obten_ruta_corta(const Type n1, const Type n2) {
  hay_ruta_corta = false;
  if (!ListaNodo->buscar(n2) || !ListaNodo->buscar(n1) ) return;

  nodo<Type> *i = ListaNodo->obtener_agregado();
  i->ruta_corta = 0;
  do {
    i->estado = DEFINITIVO;
    if (*i == n2) {
      delete ListaAux;
      ListaAux = new lista_aux<Type>;
      do ListaAux->agregar(i); while(i = i->ant);
      hay_ruta_corta = true;
      return;
    }
    arco<Type> *a = i->saliente->obtener_principio();
    while (a) {
      if (a->dir_nodo->estado == NO_TOCADO) {
        a->dir_nodo->estado = TOCADO;
        a->dir_nodo->ant = i;
        a->dir_nodo->ruta_corta = i->ruta_corta + a->peso;
        ListaAux->agregar(a->dir_nodo);
      } else if (a->dir_nodo->ruta_corta > a->peso + i->ruta_corta){
        a->dir_nodo->ant = i;
        a->dir_nodo->ruta_corta = i->ruta_corta + a->peso;
        ListaAux->ajustar(a->dir_nodo->dir_nodo_en_lista);
      }
      a = a->sig;
    }
  }while(i = ListaAux->sacar_primero());
}
template <typename Type> void grafo<Type>::agregar(const Type n1, const Type n2, const float l) {
  nodo<Type> *n;
  nodo<Type> *m;
  ListaNodo->agregar(n1);
  n = ListaNodo->obtener_agregado();
  ListaNodo->agregar(n2);
  m = ListaNodo->obtener_agregado();
  n->saliente->agregar(m,l);
}
