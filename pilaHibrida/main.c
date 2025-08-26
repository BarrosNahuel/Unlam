#include "funciones.h"

int main()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i, dato;
    tPila pila;
    crearPila(&pila);
    if(pilaVacia(&pila)){
        printf("Pila vacia\n");
    }
    for(i=0;i<10;i++){
        apilar(&pila, v+i, sizeof(int));
    }
    if(pilaLlena(&pila)){
        printf("Pila llena\n");
    }
    for(i=0;i<10;i++){
        desapilar(&pila, &dato, sizeof(int));
        printf("%d\n", dato);
    }

    if(pilaVacia(&pila)){
        printf("Pila vacia\n");
    }
    for(i=0;i<10;i++){
        apilar(&pila, v+i, sizeof(int));
    }
    if(pilaLlena(&pila)){
        printf("Pila llena\n");
    }
    vaciarPila(&pila);
    if(pilaVacia(&pila)){
        printf("Pila vacia\n");
    }

    return 0;
}
