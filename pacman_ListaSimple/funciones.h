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

typedef struct{
    int dia;
    int mes;
    int anio;
}tFecha;
typedef struct{
    char nom[25];
    char sexo;
    tFecha fecNac;
}tPersona;

void crearLoteSimple();
void crearLoteEstructura();
char menu(const char *msj, const char *opc);
int cargarListaArchTxtOrd(tLista *p, const char *nombArch, CMP cmp ,int dupl);
int cargarListaArchBinOrd(tLista *p, const char *nombArch, CMP cmp,int dupl);
void mostrarFloat(void *d);
void mostrarPersona(void *d);
int compararFloat(const void *d1, const void *d2);
int compararPersonas(const void *d1, const void *d2);

#endif // FUNCIONES_H_INCLUDED
