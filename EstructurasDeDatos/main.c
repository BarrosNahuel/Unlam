#include "funciones.h"

int main()
{
    char cad1[] = "Hola";
    char cad2[] = "Gente";
    char cad3[] = "Como";
    char cad4[] = "Estan";
    char cad5[] = "!";
    void *dato;
    unsigned pos;
    tLista lista;

    crearListaDoble(&lista);

    dato = malloc(sizeof(unsigned) + sizeof(cad2));
    pos = 2;
    memcpy(dato, &pos, sizeof(unsigned));
    memcpy((char*)dato + sizeof(unsigned), cad2, sizeof(cad2));
    ponerEnListaDoble(&lista, dato, sizeof(unsigned) + sizeof(cad2));
    free(dato);

    dato = malloc(sizeof(unsigned) + sizeof(cad1));
    pos = 1;
    memcpy(dato, &pos, sizeof(unsigned));
    memcpy((char*)dato + sizeof(unsigned), cad1, sizeof(cad1));
    ponerEnListaDoble(&lista, dato, sizeof(unsigned) + sizeof(cad1));
    free(dato);

    dato = malloc(sizeof(unsigned) + sizeof(cad5));
    pos = 5;
    memcpy(dato, &pos, sizeof(unsigned));
    memcpy((char*)dato + sizeof(unsigned), cad5, sizeof(cad5));
    ponerEnListaDoble(&lista, dato, sizeof(unsigned) + sizeof(cad5));
    free(dato);


    dato = malloc(sizeof(unsigned) + sizeof(cad3));
    pos = 3;
    memcpy(dato, &pos, sizeof(unsigned));
    memcpy((char*)dato + sizeof(unsigned), cad3, sizeof(cad3));
    ponerEnListaDoble(&lista, dato, sizeof(unsigned) + sizeof(cad3));
    free(dato);

    dato = malloc(sizeof(unsigned) + sizeof(cad4));
    pos = 4;
    memcpy(dato, &pos, sizeof(unsigned));
    memcpy((char*)dato + sizeof(unsigned), cad4, sizeof(cad4));
    ponerEnListaDoble(&lista, dato, sizeof(unsigned) + sizeof(cad4));
    free(dato);

    ordenarListaDobleSeleccion(&lista, comparar);
    mapListaDoble(&lista, mostrar);
    //vaciarLista(&lista);

    return 0;
}
