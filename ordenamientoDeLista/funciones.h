#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "lista.h"
#include <time.h>

#define TAM_BUFF 200

typedef struct{
    char nya[26];
    char sex;
    int dni;
}tPersona;

void crearLoteTxt();
void crearLoteInt(tLista *p);
int cargarListaTxt(tLista *p, const char *nombArch,unsigned tam, int trozar(char *buffer, void *dato));
int trozar(char *buffer, void *dato);
int compararPersonas(const void *d1, const void *d2);
void mostrarPersonas(const void *d);
int compararInt(const void *d1, const void *d2);
void mostrarInt(const void *d);

#endif // FUNCIONES_H_INCLUDED
