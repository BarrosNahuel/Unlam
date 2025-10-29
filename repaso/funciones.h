#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SALTO printf("\n");

typedef struct{
    int dni;
    int legajo;
    float promedio;
    int edad;
    char genero;
}tAlumno;

void* myMemcpy(void* dest, const void* src, unsigned tam);
void* myMemmove(void* dest, const void* src, unsigned tam);
int isFibonacci(int nro);
void desofuscarLinea(char *linea);
void ejercicio52(const char *linea, char *primerPalabra, int* cantRep, int *cantPal, int *palLarga);
int ejercicio513(const char* nombArch);

int** crearMatrizD(int f, int c);
void destruirMatrizD(int** mat, int c);
int sumarDiagonalSuperior(int** mat, int cf, int cc);
int esMatrizIdentidad(int **mat, int cf, int cc);
int insertarOrdenado(void *vec, void *dato, unsigned tam, unsigned *ce, unsigned ceMax, int cmp(const void *d1, const void *d2));
int compararFloat(const void *d1, const void *d2);

#endif // FUNCIONES_H_INCLUDED
