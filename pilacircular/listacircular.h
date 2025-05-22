#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_PRODUCTOS 11
#define MIN(X,Y) ((X)<=(Y)?(X):(Y))
typedef struct sNodo{
    void *dato;
    unsigned tam;
    struct sNodo *sig;
}tNodo;

typedef struct{
    char producto[20];
    char descripcion[30];
    int stock;
}tProducto;

typedef tNodo* tPila;
typedef tNodo *tCola;

int verTopePila(const tPila *pila, void* dato, unsigned tam);
void crearPila(tPila *pila);
void vaciarPila(tPila *pila);
int apilar(tPila *pila, const void *dato, unsigned tam);
int desapilar(tPila *pila, void *dato, unsigned tam);
int pilaVacia(const tPila *pila);
int pilaLlena(const tPila *pila);

void crearCola(tCola *cola);
int colaLlena(const tCola *cola, unsigned tamElem);
int colaVacia(const tCola *cola);
int ponerEnCola(tCola *cola, const void *elem, unsigned tamElem );
int sacarDeCola(tCola *cola, void *elem, unsigned tamElem);
int verTopeDeCola(const tPila *cola, void *elem, unsigned tamElem);
int vaciarCola(tCola *cola);
#endif // LISTACIRCULAR_H_INCLUDED
