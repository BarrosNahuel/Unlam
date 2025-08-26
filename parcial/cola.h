#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) (((x)<(y))?(x):(y))

typedef struct sNodo{
    void *dato;
    unsigned tam;
    struct sNodo *sig;
}tNodo;

typedef struct{
    tNodo *pri;
    tNodo *ult;
}tCola;

void crearCola(tCola *cola);
int ponerEnCola(tCola *cola, const void *dato, unsigned tam);
int sacarDeCola(tCola *cola, void *dato, unsigned tam);

#endif // COLA_H_INCLUDED
