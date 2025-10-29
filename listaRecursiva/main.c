#include "lista.h"
#include "funciones.h"
int main()
{
    int v[] = {1,2,3,4,5,6,7,8,9};
    tLista lista;
    crearLista(&lista);
    for(int i = 0; i < sizeof(v)/sizeof(int); i++)
        insertarEnLista(&lista, v+i, sizeof(int));
    mostrarListaInversoIt(&lista, mostrarInt);
    printf("\n");
    mostrarListaInversoRec(&lista, mostrarInt);
    vaciarLista(&lista);
    printf("\n");
    printf("[%d]", tautologia(v, sizeof(v)/sizeof(int)));
    return 0;
}
