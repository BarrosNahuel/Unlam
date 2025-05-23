#include "TPAlgoritmos.h"
/*
%d Es reemplazado por el día del mes como un número decimal (01-31)
%H Es reemplazado por la hora (reloj de 24 horas) como un número decimal (00-23)
%m Es reemplazado por el mes como un número decimal (01-12)
%M Es reemplazado por el minuto como un número decimal (00-59)
%Y Es reemplazado por el año con siglo como un número decimal
*/
///informe-juego_2025-02-01-12-20.txt
///%Y-%m-%d-%H-%M
void nombreInforme(char* nombre){
    time_t comienzo = time(NULL);
    struct tm *timepo = localtime(&comienzo);
    strftime(nombre, 40, "informe-juego_%Y-%m-%d-%H-%M.txt", timepo);
}

void registrarTurno(tCola* turnos, const char* jugador, unsigned puntosBot, unsigned puntosJugador, unsigned turno, int carta){
    tTurno jugada = {"", puntosBot, puntosJugador, turno, carta};
    strcpy(jugada.jugador, jugador);
    ponerEnCola(turnos, &jugada, sizeof(tTurno));
}

int generarInforme(tCola* turnos){
    char nombreArchivo[40];
    FILE* p;
    tTurno turno;
    nombreInforme(nombreArchivo);
    p = fopen(nombreArchivo, "wt");
    if(!p)
        return 0;
    while(sacarDeCola(turnos, &turno, sizeof(tTurno))){
        switch(turno.carta){
            case MAS1:
                fprintf(p, "Turno %d: El jugador %s jugó la carta MAS 1. Puntos de %s: %d, puntos del Bot: %d\n", turno.turno, turno.jugador, turno.jugador, turno.puntosJugador, turno.puntosBot);
                break;

            case MAS2:
                fprintf(p, "Turno %d: El jugador %s jugó la carta MAS 2. Puntos de %s: %d, puntos del Bot: %d\n", turno.turno, turno.jugador, turno.jugador, turno.puntosJugador, turno.puntosBot);
                break;

            case MENOS1:
                fprintf(p, "Turno %d: El jugador %s jugó la carta MENOS 1. Puntos de %s: %d, puntos del Bot: %d\n", turno.turno, turno.jugador, turno.jugador, turno.puntosJugador, turno.puntosBot);
                break;

            case MENOS2:
                fprintf(p, "Turno %d: El jugador %s jugó la carta MENOS 2. Puntos de %s: %d, puntos del Bot: %d\n", turno.turno, turno.jugador, turno.jugador, turno.puntosJugador, turno.puntosBot);
                break;

            case ESPEJO:
                fprintf(p, "Turno %d: El jugador %s jugó la carta ESPEJO. Puntos de %s: %d, puntos del Bot: %d\n", turno.turno, turno.jugador, turno.jugador, turno.puntosJugador, turno.puntosBot);
                break;

            case REPETIR:
                fprintf(p, "Turno %d: El jugador %s jugó la carta REPETIR TURNO. Puntos de %s: %d, puntos del Bot: %d\n", turno.turno, turno.jugador, turno.jugador, turno.puntosJugador, turno.puntosBot);
                break;
        }
    }
        if(turno.puntosJugador == 12)
            fprintf(p, "El jugador %s ha ganado la partida logrando llegar a 12 puntos\n",turno.jugador);
        else
            fprintf(p, "El jugador %s ha perdido la partida, el Bot logro llegar a los 12 puntos primero\n",turno.jugador);
    fclose(p);
    return 1;
}
/*
int informe(const char* nombreArchivo, const char* jugador, unsigned puntosBot, unsigned puntosJugador, unsigned turno, int carta){
    FILE *p;
    p = fopen(nombreArchivo, "at");
    if(!p){
        return 0;
    }
    switch(carta){
        case MAS1:
            if(TURNO_JUGADOR)
                fprintf(p, "Turno %d: El jugador %s jugó la carta MAS 1. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, jugador, puntosJugador, puntosBot);
            else
                fprintf(p, "Turno %d: El Bot jugó la carta MAS 1. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, puntosJugador, puntosBot);
            break;

        case MAS2:
            if(TURNO_JUGADOR)
                fprintf(p, "Turno %d: El jugador %s jugó la carta MAS 2. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, jugador, puntosJugador, puntosBot);
            else
                fprintf(p, "Turno %d: El Bot jugó la carta MAS 2. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, puntosJugador, puntosBot);
            break;

        case MENOS1:
            if(TURNO_JUGADOR)
                fprintf(p, "Turno %d: El jugador %s jugó la carta MENOS 1. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, jugador, puntosJugador, puntosBot);
            else
                fprintf(p, "Turno %d: El Bot jugó la carta MENOS 1. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, puntosJugador, puntosBot);
            break;

        case MENOS2:
            if(TURNO_JUGADOR)
                fprintf(p, "Turno %d: El jugador %s jugó la carta MENOS 2. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, jugador, puntosJugador, puntosBot);
            else
                fprintf(p, "Turno %d: El Bot jugó la carta MENOS 2. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, puntosJugador, puntosBot);
            break;

        case ESPEJO:
            if(TURNO_JUGADOR)
                fprintf(p, "Turno %d: El jugador %s jugó la carta ESPEJO. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, jugador, puntosJugador, puntosBot);
            else
                fprintf(p, "Turno %d: El Bot jugó la carta ESPEJO. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, puntosJugador, puntosBot);
            break;

        case REPETIR:
            if(TURNO_JUGADOR)
                fprintf(p, "Turno %d: El jugador %s jugó la carta REPETIR TURNO. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, jugador, puntosJugador, puntosBot);
            else
                fprintf(p, "Turno %d: El Bot jugó la carta REPETIR TURNO. Puntos de %s: %d, puntos del Bot: %d\n", turno, jugador, puntosJugador, puntosBot);
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
}*/
