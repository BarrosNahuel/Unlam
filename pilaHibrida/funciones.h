#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) ((x)<(y)?(x):(y))
#define TAM_PILA (sizeof(tDato)*10)

typedef struct{
    void *dato;
    unsigned tam;
}tDato;

typedef struct{
    char pila[TAM_PILA];
    unsigned tope;
}tPila;

void crearPila(tPila *p);
void vaciarPila(tPila *p);
int pilaLlena(const tPila *p, unsigned tam);
int pilaVacia(const tPila *p);
int apilar(tPila *p, const void *dato, unsigned tam);
int desapilar(tPila *p, void *dato, unsigned tam);
int verTope(const tPila *p, void *dato, unsigned tam);

#endif // FUNCIONES_H_INCLUDED
