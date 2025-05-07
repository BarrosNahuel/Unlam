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

typedef struct
{
    int id;
    char nombre[25];
} tPersona;

typedef int(*tCMP)(const void* nodo1, const void* nodo2);

void crearLista(tLista* pLista);
int ponerEnLista(tLista* pLista, const void* dato, unsigned tam);
int sacarDeLista(tLista* pLista, void* dato, unsigned tam);
int listaVacia(const tLista* pLista);
void vaciarLista(tLista* lista);
void mapLista(tLista* lista, void accion(tNodo* nodo));
int insertarSinDuplicados(tLista* pLista, const void* dato, unsigned tam,tCMP);
int insertarOrdenado(tLista* pLista, const void* dato, unsigned tam, tCMP cmp,int dup);
int eliminarElemento(tLista* pLista,void* dato, unsigned tam,const void* clave, tCMP cmp);


void cambiarDni(tNodo* nodo);
void mostrarPersonas(tNodo* nodo);
int compararPersonasDni(const void* nodo1,const void* nodo2);
int compararPersonasNombre(const void* nodo1,const void* nodo2);
int compararPersonasNombreClave(const void* nodo1,const void* nodo2);
#endif // LISTASIMPLEMENTEENLAZADA_H_INCLUDED
