#include "ListaSimplementeEnlazada.h"

void crearLista(tLista* pLista){
    (*pLista) = NULL;
}
int ponerEnLista(tLista* pLista, const void* dato, unsigned tam){
    tNodo* nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    nue->sig = *pLista;
    *pLista = nue;
    return 1;
}
int sacarDeLista(tLista* pLista, void* dato, unsigned tam){
    tNodo* elim = *pLista;
    if(!*pLista)
        return 0;
    memcpy(dato, elim->dato, MIN(tam, elim->tam));
    *pLista = elim->sig;
    free(elim->dato);
    free(elim);
    return 1;
}
int listaVacia(const tLista* pLista){
    return (*pLista) == NULL;
}
void vaciarLista(tLista* pLista){
    tNodo* elim = *pLista;
    while(*pLista){
        *pLista = elim->sig;
        free(elim->dato);
        free(elim);
        elim = *pLista;
    }
}
int mapLista(tLista* pLista, void accion(tNodo* nodo)){
    tNodo* nodo = *pLista;
    if(!(*pLista))
        return 0;
    while(nodo){
        accion(nodo);
        nodo = nodo->sig;
    }
    return 1;
}

int insertarSinDuplicados(tLista* pLista, const void* dato, unsigned tam, int cmp(const tNodo* nodo1, const tNodo* nodo2)){
    tNodo* nodoActual = *pLista;
    tNodo* nodoNuevo = (tNodo*) malloc(sizeof(tNodo));
    if(!nodoNuevo)
        return 0;
    nodoNuevo->dato = malloc(tam);
    if(!nodoNuevo->dato){
        free(nodoNuevo);
        return 0;
    }
    memcpy(nodoNuevo->dato, dato, tam);
    nodoNuevo->tam = tam;
    while(nodoActual != NULL){
        if(cmp(nodoActual, nodoNuevo)){
            free(nodoNuevo->dato);
            free(nodoNuevo);
            return 0;
        }
        nodoActual = nodoActual->sig;
    }
    nodoNuevo->sig = *pLista;
    *pLista = nodoNuevo;
    return 1;
}
















