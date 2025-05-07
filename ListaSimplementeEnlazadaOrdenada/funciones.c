#include "ListaSimplementeEnlazada.h"

int compararPersonasDni(const void* nodo1,const void* nodo2)
{
    tPersona* per1 = (tPersona*)nodo1;
    tPersona* per2 = (tPersona*)nodo2;

    return(per1->id - per2->id);

}

int compararPersonasNombre(const void* nodo1,const void* nodo2)
{
    tPersona* per1 = (tPersona*)nodo1;
    tPersona* per2 = (tPersona*)nodo2;

    return(strcmp(per1->nombre,per2->nombre));

}

int compararPersonasNombreClave(const void* nodo1,const void* nodo2)
{
    char* per1 = (char*)nodo1;
    tPersona* per2 = (tPersona*)nodo2;

    return(strcmp(per1,per2->nombre));

}

void cambiarDni(tNodo* nodo)
{
    tPersona persona;
    memcpy(&persona, nodo->dato, MIN(sizeof(tPersona), nodo->tam));
    persona.id = 0000;
    memcpy(nodo->dato, &persona, sizeof(tPersona));
}
void mostrarPersonas(tNodo* nodo)
{
    tPersona persona;
    memcpy(&persona, nodo->dato, MIN(sizeof(tPersona), nodo->tam));
    printf("Nombre: %s, DNI: %d\n", persona.nombre, persona.id);
}
