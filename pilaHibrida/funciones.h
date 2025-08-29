#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "pilaHibrida.h"

typedef struct{
    char nombre[20];
    int leg;
    char dpto[20];
}tEstudiante;

void crearLote();
int cargarPilaDesdeArchBin(tPila *p, const char *nombArch, unsigned tam);

#endif // FUNCIONES_H_INCLUDED
