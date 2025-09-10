#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

#define CHTOINT(a) (a = (a)-48)

void crearArchivosPrueba();
int sumarNumeros(const char *archivoNumero1, const char *archivoNumero2, const char *archRes);
int cargarNumerosEnPila(tPila *p, const char *nombArch);
int cargarPilaEnArchTxt(tPila *p, const char *nombArch);

#endif // FUNCIONES_H_INCLUDED
