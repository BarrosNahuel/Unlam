#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PILA 500
#define MAX_COLA 500
#define MIN(x,y) (((x)<(y))?(x):(y))

//typedef struct sNodo{
//    void* dato;
//    unsigned tam;
//    struct sNodo* sig;
//}tNodo;
//typedef tNodo* tPila;
//typedef struct{
//    tNodo *pri;
//    tNodo *ult;
//}tCola;
typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo *sig, *ant;
}tNodo;
typedef tNodo* tLista;
typedef int(*tCMP)(const void *, const void *);
//typedef struct{
//    char cola[MAX_COLA];
//    unsigned pri, ult, tam;
//}tCola;
//typedef struct{
//    char pila[MAX_PILA];
//    unsigned tam;
//}tPila;
///PILA
//void crearPila(tPila *p);
//int pilaVacia(const tPila *p);
//int apilar(tPila *p, const void* dato, unsigned tam);
//int verTope(const tPila *p, void* dato, unsigned tam);
//int desapilar(tPila *p, void* dato, unsigned tam);
//void vaciarPila(tPila *p);
//int pilaLlena(const tPila *p, unsigned tam);
//
/////COLA
//void crearCola(tCola *p);
//int ponerEnCola(tCola *p, const void *dato, unsigned tam);
//int verPrimero(const tCola *p, void *dato, unsigned tam);
//int sacarDeCola(tCola *p, void *dato, unsigned tam);
//int colaVacia(const tCola *p);
//int colaLlena(const tCola *p, unsigned tam);
//void vaciarCola(tCola *p);

///LISTA
void crearLista(tLista *p);
int ponerEnLista(tLista *p, const void *dato, unsigned tam);
int ponerEnListaOrdenado(tLista *p, const void *dato, unsigned tam, tCMP cmp, unsigned duplicados);
void mapLista(tLista *p, void accion(void* dato));
int sacarDeLista(tLista *p, void *dato, unsigned tam);
void ordenarListaSeleccion(tLista *p, tCMP cmp);
void vaciarLista(tLista *p);

///LISTA DOBLE
void crearListaDoble(tLista *p);
int ponerEnListaDoble(tLista *p, const void *dato, unsigned tam);
int ponerEnListaDobleOrdenado(tLista *p, const void *dato, unsigned tam, tCMP cmp, unsigned duplicados);
void mapListaDoble(tLista *p, void accion(void* dato));
int sacarDeListaDoble(tLista *p, void *dato, unsigned tam, const void* clave, tCMP cmp);
void ordenarListaDobleSeleccion(tLista *p, tCMP cmp);
void vaciarListaDoble(tLista *p);


int comparar(const void* dato1, const void *dato2);
void mostrar(void *dato);


#endif // FUNCIONES_H_INCLUDED
