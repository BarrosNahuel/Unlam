#include "listacircular.h"

void crearPila(tPila *pila){
    *pila = NULL;
}
void crearCola(tCola *cola){
    *cola = NULL;
}

int pilaLlena(const tPila *pila){
    return 0;
}
int colaLlena(const tCola *cola, unsigned tamElem){
    return 0;
}
int pilaVacia(const tPila *pila){
    return (*pila) == NULL;
}
int colaVacia(const tCola *cola){
    return (*cola) == NULL;
}
int apilar(tPila *pila, const void *dato, unsigned tam){
    tNodo *nue;
    nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    if(!(*pila)){
        (*pila) = nue;
    }
    else{
        nue->sig = (*pila)->sig;
    }
    (*pila)->sig = nue;


    return 1;
}
int ponerEnCola(tCola *cola, const void *dato, unsigned tam ){
    tNodo* nue;
    nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;

    if(!(*cola)){
        (*cola) = nue;
        (*cola)->sig = nue;
    }
    else{
        nue->sig = (*cola)->sig;
        (*cola)->sig = nue;
        (*cola) = nue;
    }
    return 1;
}
int desapilar(tPila *pila, void *dato, unsigned tam){
    tNodo *elim;
    if(!(*pila))
        return 0;
    elim = (*pila)->sig;
    memcpy(dato, elim->dato, MIN(tam, elim->tam));
    if((*pila) == elim){
        (*pila) = NULL;
    }
    else{
        (*pila)->sig = elim->sig;
    }
    free(elim->dato);
    free(elim);
    return 1;
}

int sacarDeCola(tCola *cola, void *dato, unsigned tam){
    tNodo* elim;
    if(!(*cola))
        return 0;
    elim = (*cola)->sig;
    memcpy(dato, elim->dato, MIN(tam, elim->tam));
    if((*cola) == elim){
        (*cola) = NULL;
    }
    else{
        (*cola)->sig = elim->sig;
    }
    free(elim->dato);
    free(elim);
    return 1;
}

int verTopePila(const tPila *pila, void* dato, unsigned tam){
    if(!(*pila))
        return 0;
    memcpy(dato, ((*pila)->sig)->dato, MIN(tam, ((*pila)->sig)->tam));
    return 1;
}
int verTopeDeCola(const tPila *cola, void *dato, unsigned tam){
    if(!(*cola))
        return 0;
    memcpy(dato, ((*cola)->sig)->dato, MIN(tam, ((*cola)->sig)->tam));
    return 1;
}
void vaciarPila(tPila *pila){
    tNodo *elim;
    while()
}
