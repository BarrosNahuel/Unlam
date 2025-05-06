#include "ListaSimplementeEnlazada.h"

int compararPersonas(const tNodo* nodo1,const tNodo* nodo2){
    tPersona per1, per2;
    if(!nodo1 || !nodo2)
        return 0;
    memcpy(&per1, nodo1->dato, nodo1->tam);
    memcpy(&per2, nodo2->dato, nodo2->tam);
    if(per2.id == per1.id){
        return 1;
    }
    else{
        return 0;
    }
}
void cambiarDni(tNodo* nodo){
    tPersona persona;
    memcpy(&persona, nodo->dato, MIN(sizeof(tPersona), nodo->tam));
    persona.id = 0000;
    memcpy(nodo->dato, &persona, sizeof(tPersona));
}
void mostrarPersonas(tNodo* nodo){
    tPersona persona;
    memcpy(&persona, nodo->dato, MIN(sizeof(tPersona), nodo->tam));
    printf("Nombre: %s, DNI: %d\n", persona.nombre, persona.id);
}
