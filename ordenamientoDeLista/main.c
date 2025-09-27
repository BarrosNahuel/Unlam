#include "lista.h"
#include <time.h>

int compararInt(const void *d1, const void *d2){
    return (*(int*)d1 - *(int*)d2);
}
void mostrarInt(const void *d){
    printf("[%d]", *(int*)d);
}

int main()
{
    tLista lista;
    int dato, i;
    crearLista(&lista);
    srand(time(NULL));
    for(i = 0; i < 10; i++){
        dato = rand()%10;
        insertarEnLista(&lista, &dato, sizeof(int));
    }
    mapLista(&lista, mostrarInt);
    printf("\n");
    ordenarListaSeleccion(&lista, compararInt);
    mapLista(&lista, mostrarInt);
    return 0;
}
