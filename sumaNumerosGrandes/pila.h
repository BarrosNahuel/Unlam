#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) ((x)<(y)?(x):(y))

typedef struct sNodo{
    void *dato;
    unsigned tam;
    struct sNodo *sig;
}tNodo;

typedef tNodo *tPila;

void crearPila(tPila *p);
void vaciarPila(tPila *p);
int pilaVacia(const tPila *p);
int pilaLlena(const tPila *p);
int apilar(tPila *p, const void *dato, unsigned tam);
int desapilar(tPila *p, void *dato, unsigned tam);
int verTope(const tPila *p, void *dato, unsigned tam);

#endif // PILA_H_INCLUDED
