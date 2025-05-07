#ifndef LISTASIMPLEMENTEENLAZADA_H_INCLUDED
#define LISTASIMPLEMENTEENLAZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(x,y) (((x)<(y))?(x):(y))


typedef struct sNodo
{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
} tNodo;

typedef tNodo* tLista;

typedef int(*tCMP)(const void* dato1, const void* dato2);
typedef int (*tUnir)(void* orig, const void* dupl);

void crearLista(tLista* pLista);
int ponerEnLista(tLista* pLista, const void* dato, unsigned tam);
int sacarDeLista(tLista* pLista, void* dato, unsigned tam);
int listaVacia(const tLista* pLista);
void vaciarLista(tLista* lista);
void mapLista(tLista* lista, void accion(tNodo* nodo));
int insertarSinDuplicados(tLista* pLista, const void* dato, unsigned tam,tCMP);
int insertarOrdenado(tLista* pLista, const void* dato, unsigned tam, tCMP cmp,int dup);
int eliminarElementoPorClave(tLista* pLista,void* dato, unsigned tam,const void* clave, tCMP cmp);
int unirDuplicadosOrdenado(tLista *pLista, tCMP cmp, tUnir unir);

#endif // LISTASIMPLEMENTEENLAZADA_H_INCLUDED
