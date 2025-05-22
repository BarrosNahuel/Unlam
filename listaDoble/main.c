#include "listaDoble.h"

int main()
{
    tLista lista;
    int vec[] = {10, 3, 5, 1,10, 6, 6, 0,11}, i, clave=11, elim;
    crearLista(&lista);
    for(i=0;i<sizeof(vec)/sizeof(int);i++){
        insertarOrdenado(&lista, vec+i, sizeof(int), compararInt);
    }
    printf("|---VIENDO LISTA---|\n");
    printf("|---IZQUIERDA---|\n");
    mapListaDobleIzquierda(&lista, mostrarInt);
    printf("\n");
    printf("|---DERECHA---|\n");
    mapListaDobleDerecha(&lista, mostrarInt);

    eliminarDeLista(&lista, &elim, sizeof(int), &clave, compararInt);
    printf("Eliminado: %d\n", elim);

    printf("|---VIENDO LISTA---|\n");
    printf("|---IZQUIERDA---|\n");
    mapListaDobleIzquierda(&lista, mostrarInt);
    printf("\n");
    printf("|---DERECHA---|\n");
    mapListaDobleDerecha(&lista, mostrarInt);

    clave = 2;
    eliminarVarios(&lista, &clave, esMultiplo);

    vaciarLista(&lista);

    printf("|---VIENDO LISTA---|\n");
    printf("|---IZQUIERDA---|\n");
    mapListaDobleIzquierda(&lista, mostrarInt);
    printf("\n");
    printf("|---DERECHA---|\n");
    mapListaDobleDerecha(&lista, mostrarInt);
    return 0;
}
