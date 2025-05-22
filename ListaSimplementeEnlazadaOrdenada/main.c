#include "ListaSimplementeEnlazada.h"
#include "funciones.h"

int main()
{
    tLista lista;
    crearLista(&lista);
    if(!crearLotePruebas(&lista))
        return 1;
    printf("<----------MOSTRANDO PEDIDOS---------->\n");
    mapLista(&lista, mostrarPedidos);
    printf("<------------------------------------->\n");

    ordenarListaBurbujeo(&lista, compararPedidos);

    printf("<----------MOSTRANDO PEDIDOS---------->\n");
    mapLista(&lista, mostrarPedidos);
    printf("<------------------------------------->\n");
    vaciarLista(&lista);

    return 0;
}
