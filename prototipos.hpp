#pragma once
enum Donde { VACIO, INICIO, MITAD, FINAL, MIFA }; //MIFA = MITAD o FINAL
template <typename Type> struct nodo_en_lista;
template <typename Type> struct nodo;
template <typename Type> struct arco;

template <typename Type> void eliminar(Type *principio) {
  Type *aux;
  while (principio) {
    aux = principio;
    principio = aux->sig;
    delete aux;
  }
}
