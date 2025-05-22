#ifndef LISTASIMPLEMENTEENLAZADA_H_INCLUDED
#define LISTASIMPLEMENTEENLAZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(x,y) (((x)<(y))?(x):(y))

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tLista;

typedef struct{
    int id;
    char nombre[25];
}tPersona;

void crearLista(tLista* pLista);
int ponerEnLista(tLista* pLista, const void* dato, unsigned tam);
int sacarDeLista(tLista* pLista, void* dato, unsigned tam);
int listaVacia(const tLista* pLista);
void vaciarLista(tLista* lista);
int mapLista(tLista* lista, void accion(tNodo* nodo));
int insertarSinDuplicados(tLista* pLista, const void* dato, unsigned tam, int cmp(const tNodo* nodo1, const tNodo* nodo2));

void cambiarDni(tNodo* nodo);
void mostrarPersonas(tNodo* nodo);
int compararPersonas(const tNodo* nodo1,const tNodo* nodo2);
#endif // LISTASIMPLEMENTEENLAZADA_H_INCLUDED
