#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) (((x)<(y))?(x):(y))

typedef struct sNodo{
    void *dato;
    unsigned tam;
    struct sNodo *sig;
}tNodo;

typedef tNodo* tPilaC;
typedef tNodo* tColaC;

void crearPilaC(tPilaC *p);
void vaciarPilaC(tPilaC *p);
int pilaVacia(const tPilaC *p);
int pilaLlena(const tPilaC *p, unsigned tam);
int apilar(tPilaC *p, const void *dato, unsigned tam);
int verTope(const tPilaC *p, void *dato, unsigned tam);
int desapilar(tPilaC *p, void *dato, unsigned tam);

void crearColaC(tColaC *p);
void vaciarColaC(tColaC *p);
int colaVacia(const tColaC *p);
int colaLlena(const tColaC *p, unsigned tam);
int ponerEnCola(tColaC *p, const void *dato, unsigned tam);
int verPrimero(const tColaC *p, void *dato, unsigned tam);
int sacarDeCola(tColaC *p, void *dato, unsigned tam);


#endif // LISTACIRCULAR_H_INCLUDED
