#include "ListaSimplementeEnlazada.h"

int main()
{
    tLista lista;
    tPersona personas[]={
        {1234, "candela"},
        {1235, "nahuel"},
    }, perAux;

    crearLista(&lista);
    if(ponerEnLista(&lista, &personas, sizeof(tPersona)))
        printf("Te la puse\n");
    if(ponerEnLista(&lista, &personas, sizeof(tPersona)))
        printf("Te la puse\n");
    if(sacarDeLista(&lista, &perAux, sizeof(tPersona)))
        printf("Nombre: %s, DNI: %d\n", perAux.nombre, perAux.id);
    if(listaVacia(&lista))
        printf("Lista vacia\n");
    vaciarLista(&lista);
    if(listaVacia(&lista))
        printf("Lista vacia\n");
    return 0;
}
