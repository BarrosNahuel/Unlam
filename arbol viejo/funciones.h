#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "arbol.h"

typedef struct{
    int dni;
    char nya[21];
    char sex;
}tPersona;

int crearLote(FILE *p);
int compararPersonas(const void *d1, const void *d2);
void mostrarPersonas(const void *p);
int compararInt(const void* dato1, const void *dato2);
void mostrarInt(void* dato);
void escribirPersonaIndice(void *dst, const void* src, unsigned pos);
unsigned leerArchivoBin(void **dst, void* src, unsigned pos, void *param);

#endif // FUNCIONES_H_INCLUDED
