#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAY(x,y) (((x)>(y))?(x):(y))
#define SALTO printf("\n");

typedef struct sNodo{
    void *dato;
    unsigned tam;
    struct sNodo* izq;
    struct sNodo* der;
}tNodo;

typedef struct{
    void *clave;
    unsigned pos;
}tIndice;

typedef tNodo* tArbol;
typedef int (*tCMP)(const void *dato1, const void *dato2);
typedef unsigned (*tLEER)(void **dst, void* src, unsigned pos, void *param);

void crearArbol(tArbol *p);
int insertarArbolIte(tArbol *p, const void *dato, unsigned tam, tCMP cmp);
int insertarArbolRec(tArbol *p, const void *dato, unsigned tam, tCMP cmp);
void recorrerPreOrden(tArbol *p, void accion(const void* dato));
void recorrerInOrden(tArbol *p, void accion(const void* dato));
void recorrerPosOrden(tArbol *p, void accion(const void* dato));

int contarNodos(tArbol* p); ///1
int contarHojas(tArbol *p);///2
int contarNoHojas(tArbol *p);///3
int cantNodosConHijosPorIzq(tArbol *p);///4
int cantNodosSoloConHijosPorIzq(tArbol *p);///5
int alturaDelArbol(tArbol *p);///6
int __alturaDelArbol(tArbol *p, int nivel);///6
int cantNodosEnNivel(tArbol *p, int nivel);///7
int __cantNodosEnNivel(tArbol *p, int nivelActual, int nivelMax);///7
int cantNodosHastaNivel(tArbol *p, int nivel);///8
int __cantNodosHastaNivel(tArbol *p, int nivelActual, int nivelMax);///8
int cantNodosDesdeNivel(tArbol *p, int nivel);///9
int __cantNodosDesdeNivel(tArbol *p, int nivelActual, int nivelMax);///9
tArbol* buscarPorClave(tArbol *p, const void *dato, tCMP cmp);///10
int cantNodosSubArbolDerClave(tArbol *p, const void *dato, tCMP cmp);///11
int eliminarHoja(tArbol *p, const void *dato, tCMP cmp);///12
void eliminarArbol(tArbol *p);///13

int eliminarPorClave(tArbol *p, void* dato, unsigned tam, const void *clave, tCMP cmp);
tArbol* menorHoja(tArbol *p);
tArbol* mayorHoja(tArbol *p);

int cargarArbolDesdeDatosDesordenados(tArbol *p, void *src, unsigned tam, tCMP cmp, unsigned escribir(void *dst, const void* src, unsigned tam));
int cargarArbolIndiceDesdeDatosDesordenados(tArbol *p, void *src, unsigned tam, tCMP cmp, unsigned escribirIndice(void *dst, const void* src, unsigned tam, int pos));
void pasarArbolArchivoBin(tArbol *p, FILE *pf);
int cargarArbolDesdeDatosOrdenados(tArbol *p, void *src, tLEER leer, int li, int ls, void *param);


tNodo* dondeInsertar(tArbol *p, const void *dato, unsigned tam, tCMP cmp);


#endif // ARBOL_H_INCLUDED
