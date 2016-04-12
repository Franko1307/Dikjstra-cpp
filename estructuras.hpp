#pragma once //Para que sólo se incluya una vez
#include "prototipos.hpp"
enum Estado { NO_TOCADO, TOCADO, DEFINITIVO }; //Estados de 'bandera'

template <typename Type> struct nodo_en_lista {
  nodo<Type> *dir_nodo; //Dirección del nodo en la lista de nodos.
  nodo_en_lista<Type> *ant;
  nodo_en_lista<Type> *sig;
  bool operator < (const float &i) {return this->dir_nodo->ruta_corta < i;}
  bool operator > (const nodo_en_lista<Type> &i) {return this->dir_nodo->ruta_corta < i->dir_nodo->ruta_corta;}
};
template <typename Type> class lista_arco;
template <typename Type> struct nodo {
  Type id_nodo;
  Estado estado;
  float ruta_corta;
  nodo<Type> *ant;
  nodo<Type> *sig;
  nodo_en_lista<Type> *dir_nodo_en_lista;
  lista_arco<Type> *saliente;
  bool operator < (const Type &i) {return this->id_nodo < i;}
  bool operator == (const Type &i) {return this->id_nodo == i;}
};
template <typename Type> struct arco {
  float peso; //El peso que hay entre los dos nodos.
  nodo<Type> *dir_nodo;
  arco<Type> *sig;
  bool operator < (const Type &i) {return this->dir_nodo->id_nodo < i;}
  bool operator == (const Type &i) {return this->dir_nodo->id_nodo == i;}
};
