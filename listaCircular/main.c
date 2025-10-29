#include "listaCircular.h"

int main()
{
    char prueba[] = {'a', 'b', 'c', 'd', 'e', 'f'}, dato;
    int i;
    tPilaC pila;
    tColaC cola;

    crearPilaC(&pila);
    crearColaC(&cola);

    for(i=0;i<sizeof(prueba)/sizeof(char);i++){
        apilar(&pila, prueba + i, sizeof(char));
    }
//    vaciarPilaC(&pila);
    if(!verTope(&pila, &dato, sizeof(char))){
        printf("Pila Vacia\n");
    }
    for(i=0;i<sizeof(prueba)/sizeof(char);i++){
        desapilar(&pila, &dato, sizeof(char));
        printf("[%c]", dato);
    }
    printf("\n");
    for(i=0;i<sizeof(prueba)/sizeof(char);i++){
        ponerEnCola(&cola, prueba + i, sizeof(char));
    }
//    vaciarColaC(&cola);
    if(!verTope(&cola, &dato, sizeof(char))){
        printf("Cola Vacia\n");
    }
    for(i=0;i<sizeof(prueba)/sizeof(char);i++){
        sacarDeCola(&cola, &dato, sizeof(char));
        printf("[%c]", dato);
    }

    return 0;
}
