#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

#define MAX_LINEA 50

typedef struct{
    char codLote[5];
    int idProducto;
    char resultadoControl[6];
}tProducto;

char menu();
void mostrarProducto(void *dato);
void crearLotePruebas();
int mostrarArchivoTex(const char *nombArch);
int mostrarArchivoBin(const char *nombArch, unsigned tam, void accion(void *dato));

int procesarArchivoBin(const char *archBin, const char* nombTxtAprob, const char* nombTxtObs, int porc);
int cargarEnArchivoTxt(const char* nombTxt, tCola *datos);

#endif // FUNCIONES_H_INCLUDED
