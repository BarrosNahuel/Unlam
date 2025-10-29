#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "arbol.h"

#define SALTO printf("\n"); \

typedef struct{
    int dni;
    char nya[21];
    char sex;
}tPersona;
typedef struct{
    int dni;
    long offset;
}tIndicePersona;

int leerDatosArchivoPer(void* dest, FILE *arch);
int leerDatosArchivoIdx(void* dest, FILE *arch);
int compararInt(const void*d1, const void*d2);
int compararIndPer(const void*d1, const void*d2);
void mostrarInt(void *d);
void mostrarPersonaIdx(void *d);
void crearLote();
#endif // FUNCIONES_H_INCLUDED
