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
    if(unirDuplicadosOrdenado(&lista, compararPedidos, unirPedidos)){
        printf("<----------MOSTRANDO PEDIDOS---------->\n");
        mapLista(&lista, mostrarPedidos);
        printf("<------------------------------------->\n");
    }
//    if(insertarOrdenado(&lista,))
//        printf("Se inserto correctamente\n");
//    if(insertarOrdenado(&lista,))
//        printf("\nSe inserto correctamente\n");
//    if(eliminarElementoPorClave(&lista,))
//        printf("OK\n");
//    mapLista(&lista, mostrarPedidos);
    vaciarLista(&lista);

    return 0;
}
