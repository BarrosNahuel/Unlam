#include "funciones.h"

int main()
{
    tLista lista;
    crearLista(&lista);

    crearLoteInt(&lista);
    mapLista(&lista, mostrarInt);
    printf("\n");
    ordenarListaSeleccion(&lista, compararInt);
    mapLista(&lista, mostrarInt);
    vaciarLista(&lista);
    printf("\n");

    crearLoteTxt();
    cargarListaTxt(&lista, "lote.txt", sizeof(tPersona), trozar);
    mapLista(&lista, mostrarPersonas);
    printf("\n");
    ordenarListaSeleccion(&lista, compararPersonas);
    mapLista(&lista, mostrarPersonas);
    vaciarLista(&lista);
    return 0;
}
