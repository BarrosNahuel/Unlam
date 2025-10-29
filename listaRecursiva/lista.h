#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define MIN(x,y) ((x)<(y)?(x):(y))
#define memcpy my_memcpy

typedef struct sNodo{
    void *dato;
    unsigned tam;
    struct sNodo *sig;
}tNodo;

typedef tNodo* tLista;

void crearLista(tLista *p);
int insertarEnLista(tLista *p, const void *dato, unsigned tam);
int sacarDeLista(tLista *p, void *dato, unsigned tam);
void mostrarListaInversoIt(const tLista *p, void mostrar(const void*));
void mostrarListaInversoRec(const tLista *p, void mostrar(const void*));
void vaciarLista(tLista *p);

#endif // LISTA_H_INCLUDED
