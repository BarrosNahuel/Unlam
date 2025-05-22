#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define MIN(x,y) ((x)<(y)?(x):(y))
typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
    struct sNodo* ant;
}tNodo;

typedef tNodo* tLista;
typedef int(*tCMP)(const void*, const void*);

void crearLista(tLista* pLista);
int listaVacia(tLista* pLista);
int insertarOrdenado(tLista* pLista, const void* dato, unsigned tam, tCMP cmp);
void vaciarLista(tLista* lista);
int eliminarDeLista(tLista* pLista, void* dato, unsigned tam, void* clave, tCMP cmp);
int eliminarVarios(tLista* pLista, void* clave, tCMP cmp);
int eliminarNodo(tNodo* nodo);

void mapListaDobleDerecha(tLista* pLista, void accion(const void*));
void mapListaDobleIzquierda(tLista* pLista, void accion(const void*));

#endif // LISTADOBLE_H_INCLUDED
