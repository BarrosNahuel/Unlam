#include "ListaSimplementeEnlazada.h"
#include "funciones.h"

int main()
{
    tLista lista;
    crearLista(&lista);
    if(!crearLotePruebas(&lista))
        return 1;
    ///Punto 1:
    printf("<----------MOSTRANDO PEDIDOS---------->\n");
    mapListaInversoRec(&lista, mostrarPedidos);
    printf("<------------------------------------->\n");

    ///Punto 2:
    printf("<----------MOSTRANDO PEDIDOS---------->\n");
    mapListaInversoIte(&lista, mostrarPedidos);
    printf("<------------------------------------->\n");
    vaciarLista(&lista);

    return 0;
}
