#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) ((x)<(y)?(x):(y))

typedef struct sNodo{
    void *dato;
    unsigned tam;
    struct sNodo *sig;
}tNodo;

typedef tNodo* tLista;
typedef int (*CMP)(const void*, const void*);

void crearLista(tLista *p);
int insertarOrdenado(tLista *p, const void *dato, unsigned tam, CMP cmp, int duplicado, void acc(void*, const void*));
int sacarDeLista(tLista *p, void *dato, unsigned tam);
void mapLista(tLista *p, void accion(void*));
void vaciarLista(tLista *p);

#endif // LISTA_H_INCLUDED
