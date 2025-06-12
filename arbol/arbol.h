#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAY(x,y) (((x)>(y))?(x):(y))
#define SALTO printf("\n");

typedef struct sNodo{
    void *dato;
    unsigned tam;
    struct sNodo* izq;
    struct sNodo* der;
}tNodo;

typedef tNodo* tArbol;
typedef int (*tCMP)(const void *dato1, const void *dato2);

void crearArbol(tArbol *p);
int insertarArbolIte(tArbol *p, const void *dato, unsigned tam, tCMP cmp);
int insertarArbolRec(tArbol *p, const void *dato, unsigned tam, tCMP cmp);
void recorrerPreOrden(tArbol *p, void accion(void* dato));
void recorrerInOrden(tArbol *p, void accion(void* dato));
void recorrerPosOrden(tArbol *p, void accion(void* dato));
void contarNodosTrampa(tArbol* p, int* cant);

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
tArbol buscarPorClave(tArbol *p, const void *dato, tCMP cmp);///10
int cantNodosSubArbolDerClave(tArbol *p, const void *dato, tCMP cmp);///11
int eliminarHoja(tArbol *p, const void *dato, tCMP cmp);///12
void eliminarArbol(tArbol *p);///13
//almacenarlo en un archivo y recuperarlo, contar las hojas,
//contar nodos, contar hojas, contar las no hojas, contar nodos con hijos por izq, contar nodos que solo tienen hijos por izq,
//altura del arbols, cantidad de nodos en un nivel, cantidad de nodos hasta un nivel, cantidad de nodos desde un nivel,
//buscar una clave(devuelve punt a punt o arbol mejor), cantidad de nodos del subarbol derecho de una clave, eliminar una hoja,
//eliminar el arbol,

int compararInt(const void* dato1, const void *dato2);
void mostrarInt(void* dato);

#endif // ARBOL_H_INCLUDED
