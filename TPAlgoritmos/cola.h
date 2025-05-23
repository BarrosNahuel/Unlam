#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "TPAlgoritmos.h"

#define MIN(x,y) (((x)<(y))?(x):(y))

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
}tNodo;

typedef struct{
    tNodo* pri;
    tNodo* ult;
}tCola;

void registrarTurno(tCola* turnos, const char* jugador, unsigned puntosBot, unsigned puntosJugador, unsigned turno, int carta);
int generarInforme(tCola* turnos);

void crearCola(tCola* cola);
void vaciarCola(tCola* cola);
int colaVacia(const tCola* cola);
int colaLlena(const tCola* cola, const void* dato, unsigned tam);
int ponerEnCola(tCola* cola, const void* dato, unsigned tam);
int sacarDeCola(tCola* cola, void* dato, unsigned tam);
int verPrimero(const tCola* cola, void* dato, unsigned tam);

#endif // COLA_H_INCLUDED
