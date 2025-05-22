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

void nombreInforme(char* nombre){
    char cad[20];
    struct tm *timepo;
    time_t comienzo = time(NULL);
    timepo = localtime(&comienzo);
    strftime(cad, 20, "%Y-%m-%d-%H-%M", timepo);
    strcat(nombre, "informe-juego_");
    strcat(nombre, cad);
}

int main(){
    char nombre[40];
    nombreInforme(nombre);
    printf("%s", nombre);
    return 0;
}
