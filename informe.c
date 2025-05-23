#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
%d Es reemplazado por el día del mes como un número decimal (01-31)
%H Es reemplazado por la hora (reloj de 24 horas) como un número decimal (00-23)
%m Es reemplazado por el mes como un número decimal (01-12)
%M Es reemplazado por el minuto como un número decimal (00-59)
%Y Es reemplazado por el año con siglo como un número decimal
*/
///informe-juego_2025-02-01-12-20.txt
///%Y-%m-%d-%H-%M
///Wed May 21 19:42:35 2025
#define MAS1 1
#define MAS2 2
#define MENOS2 -2
#define MENOS1 -1
#define ESPEJO 0
#define REPETIR -3
#define FIN_DEL_JUEGO 3
void nombreInforme(char* nombre);
int informe(const char* nombreArchivo, const char* jugador, unsigned puntosBot, unsigned puntosJugador, unsigned turno, int carta);

int main(){
    char nombre[40];
    nombreInforme(nombre);
    if(informe(nombre, "Nahuel", 2, 10, 6, MENOS1))
        printf("asd\n");
    return 0;
}

void nombreInforme(char* nombre){
    char cad[20];
    struct tm *timepo;
    time_t comienzo = time(NULL);
    timepo = localtime(&comienzo);
    strftime(cad, 20, "%Y-%m-%d-%H-%M", timepo);
    strcat(nombre, "informe-juego_");
    strcat(nombre, cad);
    strcat(nombre, ".txt");
}
int informe(const char* nombreArchivo, const char* jugador, unsigned puntosBot, unsigned puntosJugador, unsigned turno, int carta){
    FILE *p;
    p = fopen(nombreArchivo, "at");
    if(!p)
        return 0;
    switch(carta){
        case MAS1:
            fprintf(p, "Turno %d: El jugador %s jugó la carta MAS 1. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, jugador, puntosJugador, puntosBot);
            break;
        case MAS2:
            fprintf(p, "Turno %d: El jugador %s jugó la carta MAS 2. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, jugador, puntosJugador, puntosBot);
            break;
        case MENOS1:
            fprintf(p, "Turno %d: El jugador %s jugó la carta MENOS 1. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, jugador, puntosJugador, puntosBot);
            break;
        case MENOS2:
            fprintf(p, "Turno %d: El jugador %s jugó la carta MENOS 2. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, jugador, puntosJugador, puntosBot);
            break;
        case ESPEJO:
            fprintf(p, "Turno %d: El jugador %s jugó la carta ESPEJO. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, jugador, puntosJugador, puntosBot);
            break;
        case REPETIR:
            fprintf(p, "Turno %d: El jugador %s jugó la carta REPETIR TURNO. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, jugador, puntosJugador, puntosBot);
            break;
        case FIN_DEL_JUEGO:
            if(puntosJugador == 12)
                fprintf(p, "El jugador %s ha ganado la partida logrando llegar a 12 puntos\n",jugador);
            else
                fprintf(p, "El jugador %s ha perdido la partida, el Bot logro llegar a los 12 puntos primero\n",jugador);
            break;
    }
    fclose(p);
    return 1;
}
