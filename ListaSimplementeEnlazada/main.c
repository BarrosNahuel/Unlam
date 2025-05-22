#include "ListaSimplementeEnlazada.h"

int main()
{
    tLista lista;
    tPersona personas[]={
        {1234, "candela"},
        {1235, "nahuel"},
        {1236, "nico"},
        {1237, "lucas"},
        {1238, "llobell"},
        {1239, "mateo"},
    }, per1 = {1234, "candela"}, per2 = {1240, "asdf"};
    int i;

    crearLista(&lista);
    for(i=0;i<sizeof(personas)/sizeof(tPersona);i++){
        ponerEnLista(&lista, personas+i, sizeof(tPersona));
    }
    mapLista(&lista, mostrarPersonas);
    if(insertarSinDuplicados(&lista, &per1, sizeof(tPersona), compararPersonas))
        printf("Se inserto correctamente\n");
    if(insertarSinDuplicados(&lista, &per2, sizeof(tPersona), compararPersonas))
        printf("Se inserto correctamente\n");
    mapLista(&lista, mostrarPersonas);
    vaciarLista(&lista);
    return 0;
}
