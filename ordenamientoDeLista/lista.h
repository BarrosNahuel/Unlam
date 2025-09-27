#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) (((x)<(y))?(x):(y))

typedef struct sNodo{
    void *dato;
    unsigned tam;
    struct sNodo *sig;
}tNodo;

typedef tNodo* tLista;
typedef int (*CMP)(const void*, const void*);

void crearLista(tLista *p);
int insertarEnLista(tLista *p, const void *dato, unsigned tam);
int sacarDeLista(tLista *p, void *dato, unsigned tam);
void vaciarLista(tLista *p);
void ordenarListaSeleccion(tLista *p, CMP cmp);
void mapLista(tLista *p, void acc(const void *d));

#endif // LISTA_H_INCLUDED
