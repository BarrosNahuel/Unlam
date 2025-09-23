#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "lista.h"

#define MENSAJE_LISTA   "ELIJA UNA DE LAS SIGUIENTES OPCIONES:\n"                                   \
                        "a. Lista con datos simples cargados desde un archivo de texto.\n"          \
                        "b. Lista con datos de una estructura cargados desde un archivo binario.\n" \
                        "c. Salir.\n"                                                               \
                        ">"

#define OPCIONES_LISTA "abc"

#define MENSAJE_DUPL "ELIJA UNA DE LAS SIGUIENTES OPCIONES:\n"  \
                    "a. Lista con elementos duplicado.\n"       \
                    "b. Lista sin elementos duplicados.\n"      \
                    ">"
#define OPCIONES_DUPL "ab"

#define MENSAJE_ACUM "ELIJA UNA DE LAS SIGUIENTES OPCIONES:\n"  \
                    "a. Acumular elementos duplicado.\n"        \
                    "b. No acumular elementos duplicados.\n"    \
                    ">"
#define OPCIONES_ACUM "ab"

#define SIN_DUPL 0
#define CON_DUPL 1
#define CON_ACUM 'a'
#define SIN_ACUM 'b'

typedef struct{
    char nom[25];
    int cant;
    char marca[25];
}tProducto;

void crearLoteSimple();
void crearLoteEstructura();
char menu(const char *msj, const char *opc);
int cargarListaArchTxtOrd(tLista *p, const char *nombArch, CMP cmp ,int dupl, void acc(void*, const void*));
int cargarListaArchBinOrd(tLista *p, const char *nombArch, CMP cmp,int dupl, void acc(void*, const void*));
void mostrarFloat(void *d);
void mostrarProductos(void *d);
int compararFloat(const void *d1, const void *d2);
int compararProductos(const void *d1, const void *d2);

void accFloat(void* acum, const void* dato);
void accProductos(void* acum, const void* dato);

#endif // FUNCIONES_H_INCLUDED
