#include "funciones.h"

void crearPila(tPila *p){
    p->tope = TAM_PILA;
}
void vaciarPila(tPila *p){
    tDato *aux;
    while(p->tope < TAM_PILA){
        aux = (tDato*)(p->pila + p->tope);
        free(aux->dato);
        p->tope += sizeof(tDato);
    }
}
int pilaLlena(const tPila *p, unsigned tam){
    return (p->tope<sizeof(tDato));
}
int pilaVacia(const tPila *p){
    return (p->tope==TAM_PILA);
}
int apilar(tPila *p, const void *dato, unsigned tam){
    tDato aux;
    if(p->tope == 0)
        return 0;

    aux.dato = malloc(tam);
    if(!aux.dato)
        return 0;
    aux.tam = tam;
    memcpy(aux.dato, dato, tam);

    p->tope -= sizeof(tDato);
    memcpy(p->pila + p->tope, &aux, sizeof(tDato));
    return 1;
}
int desapilar(tPila *p, void *dato, unsigned tam){
    tDato *aux;
    if(p->tope == TAM_PILA)
        return 0;

    aux = (tDato*)(p->pila + p->tope);
    memcpy(dato, aux->dato, MIN(tam, aux->tam));
    p->tope += sizeof(tDato);

    return 1;
}
int verTope(const tPila *p, void *dato, unsigned tam){
    tDato *aux;
    if(p->tope == TAM_PILA)
        return 0;

    aux = (tDato*)(p->pila + p->tope);
    memcpy(dato, aux->dato, MIN(tam, aux->tam));

    return 1;
}
