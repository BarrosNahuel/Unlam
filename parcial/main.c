#include "funciones.h"

int main()
{
    int porc = -1;
    char opc, nombTxtAprob[MAX_LINEA], nombTxtObs[MAX_LINEA];
    crearLotePruebas();
    do{
        opc = menu();
    switch(opc){
        case 'A':
        case 'a':
            printf("Ingrese el porcentaje de fallas:\n");
            scanf("%d", &porc);
            sprintf(nombTxtAprob, "lotesAprobados-%d.txt", porc);
            sprintf(nombTxtObs, "lotesObservados-%d.txt", porc);
            break;
        case 'B':
        case 'b':
            if(porc>=0){
                procesarArchivoBin("entrada.bin", nombTxtAprob, nombTxtObs, porc);
            }
            else
                printf("ERROR, se debe ingresar el porcentaje\n");
            break;
        case 'C':
        case 'c':
            mostrarArchivoBin("entrada.bin", sizeof(tProducto), mostrarProducto);
            break;
        case 'D':
        case 'd':
                printf("|-----|MOSTRANDO ARCHIVO DE PRODUCTOS APROBADOS|-----|\n");
                mostrarArchivoTex(nombTxtAprob);
                printf("|-----|MOSTRANDO ARCHIVO DE PRODUCTOS OBSERVADOS|-----|\n");
                mostrarArchivoTex(nombTxtObs);
            break;
        }
    }while(opc != 'e' && opc != 'E');
    return 0;
}
