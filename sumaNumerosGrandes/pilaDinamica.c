#include "pila.h"

void crearPila(tPila *p){
    *p = NULL;
}
void vaciarPila(tPila *p){
    tNodo *aux;
    while(*p){
        aux = *p;
        *p = aux->sig;
        free(aux->dato);
        free(aux);
    }
}
int pilaVacia(const tPila *p){
    return *p == NULL;
}
int pilaLlena(const tPila *p){
    return 0;
}
int apilar(tPila *p, const void *dato, unsigned tam){
    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    nue->sig = *p;
    *p = nue;

    return 1;
}
int desapilar(tPila *p, void *dato, unsigned tam){
    tNodo *aux = *p;
    if(!aux)
        return 0;

    memcpy(dato, aux->dato, MIN(aux->tam, tam));
    *p = aux->sig;
    free(aux->dato);
    free(aux);

    return 1;
}
int verTope(const tPila *p, void *dato, unsigned tam){
    if(!*p)
        return 0;
    memcpy(dato, (*p)->dato, MIN(tam, (*p)->tam));
    return 1;
}
