#include "funciones.h"

int main()
{
    tEstudiante est;
    tPila pila;
    crearLote();
    crearPila(&pila);
    if(pilaVacia(&pila)){
        printf("Pila vacia\n");
    }
    cargarPilaDesdeArchBin(&pila, "prueba.dat", sizeof(tEstudiante));
    if(pilaLlena(&pila, sizeof(tEstudiante))){
        printf("Pila llena\n");
    }

    while(!pilaVacia(&pila)){
        desapilar(&pila, &est, sizeof(tEstudiante));
        printf("\nNombre: %s\nLegajo: %d\nDepartamento: %s\n", est.nombre, est.leg, est.dpto);
        puts("|------------------------|");
    }

    cargarPilaDesdeArchBin(&pila, "prueba.txt", sizeof(tEstudiante));
    if(pilaLlena(&pila, sizeof(tEstudiante))){
        printf("Pila llena\n");
    }
    vaciarPila(&pila);
    if(pilaVacia(&pila)){
        printf("Pila vacia\n");
    }

    return 0;
}
