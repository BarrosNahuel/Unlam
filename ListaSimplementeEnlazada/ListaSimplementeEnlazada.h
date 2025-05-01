#ifndef LISTASIMPLEMENTEENLAZADA_H_INCLUDED
#define LISTASIMPLEMENTEENLAZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tLista;

void crearLista(tLista* pLista);
int ponerEnLista(tLista* pLista, const void* dato, unsigned tam);
int sacarDeLista(tLista* pLista, void* dato, unsigned tam);
int listaVacia(const tLista* pLista);
void vaciarLista(tLista* lista);
int mapLista(tLista* lista, void accion(tNodo* nodo));


#endif // LISTASIMPLEMENTEENLAZADA_H_INCLUDED
