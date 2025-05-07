#include "ListaSimplementeEnlazada.h"

int main()
{
    tLista lista;
    tPersona personas[]=
    {
        {1234, "candela"},
        {1235, "nahuel"},
        {1236, "nico"},
        {1237, "lucas"},
        {1238, "llobell"},
        {1239, "mateo"},
    }, per1 = {1234, "candela"}, per2 = {1240, "Antonio"};
    int i;
    int clave = 1236;
    char* nom="mateo";

    crearLista(&lista);
    for(i=0; i<sizeof(personas)/sizeof(tPersona); i++)
    {
        insertarOrdenado(&lista, personas+i, sizeof(tPersona),compararPersonasDni,0);
    }
    mapLista(&lista, mostrarPersonas);
    if(insertarOrdenado(&lista, &per1, sizeof(tPersona), compararPersonasDni,0))
        printf("Se inserto correctamente\n");
    if(insertarOrdenado(&lista, &per2, sizeof(tPersona), compararPersonasDni,0))
        printf("\nSe inserto correctamente\n");
    if(eliminarElemento(&lista, &per1, sizeof(tPersona),nom,compararPersonasNombreClave))
        printf("OK\n");
    mapLista(&lista, mostrarPersonas);
    vaciarLista(&lista);

    return 0;
}
