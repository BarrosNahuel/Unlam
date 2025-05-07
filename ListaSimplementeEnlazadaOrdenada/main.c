///GRUPO GENERICO
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
    for(i=0; i<sizeof(personas)/sizeof(tPersona); i++) /// (Observacion - bajo valor) Mejor forma seria: sizeof(personas) / sizeof(personas[0]) -> Esto nos permoite cambiar el tipo de dato a futuro
    {
        insertarOrdenado(&lista, personas+i, sizeof(tPersona),compararPersonasDni,NO);
    }
    mapLista(&lista, mostrarPersonas);
    if(insertarOrdenado(&lista, &per1, sizeof(tPersona), compararPersonasDni,NO))
        printf("Se inserto correctamente\n");
    if(insertarOrdenado(&lista, &per2, sizeof(tPersona), compararPersonasDni,NO))
        printf("\nSe inserto correctamente\n");
    if(eliminarElemento(&lista, &per1, sizeof(tPersona),nom,compararPersonasNombreClave))
        printf("OK\n");
    mapLista(&lista, mostrarPersonas);
    vaciarLista(&lista);

    ///

    return 0;
}
