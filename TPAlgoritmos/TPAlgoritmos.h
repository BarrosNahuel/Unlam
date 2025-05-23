#ifndef TPALGORITMOS_H_INCLUDED
#define TPALGORITMOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cola.h"

#define MAS1 1
#define MAS2 2
#define MENOS2 -2
#define MENOS1 -1
#define ESPEJO 0
#define REPETIR -3
#define FIN_DEL_JUEGO 3
#define TURNO_JUGADOR 100
#define TURNO_BOT 200

typedef struct{
    char jugador[20];
    unsigned puntosBot;
    unsigned puntosJugador;
    unsigned turno;
    int carta;
}tTurno;

void nombreInforme(char* nombre);



//int informe(const char* nombreArchivo, const char* jugador, unsigned puntosBot, unsigned puntosJugador, unsigned turno, int carta);

#endif // TPALGORITMOS_H_INCLUDED
