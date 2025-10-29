#include "listaCircular.h"
void crearPilaC(tPilaC *p){
    *p = NULL;
}
void vaciarPilaC(tPilaC *p){
    tNodo *elim = *p, *pri = *p;
    do{
        *p = elim->sig;
        free(elim->dato);
        free(elim);
        elim = *p;
    }while(elim != pri);
    *p = NULL;
}
int pilaVacia(const tPilaC *p){
    return (*p == NULL);
}
int pilaLlena(const tPilaC *p, unsigned tam){
    return 0;
}
int apilar(tPilaC *p, const void *dato, unsigned tam){
    tNodo *nue;
    if((nue = (tNodo*)malloc(sizeof(tNodo))) == NULL || (nue->dato = malloc(tam)) == NULL){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;

    if(*p){
        nue->sig = (*p)->sig;
    }
    else{
        *p = nue;
    }
    (*p)->sig = nue;

    return 1;
}
int verTope(const tPilaC *p, void *dato, unsigned tam){
    if(!*p) return 0;
    memcpy(dato, (*p)->sig->dato, MIN(tam, (*p)->sig->tam));
    return 1;
}
int desapilar(tPilaC *p, void *dato, unsigned tam){
    tNodo *elim;
    if(!*p) return 0;

    elim = (*p)->sig;
    memcpy(dato, elim->dato, MIN(tam, elim->tam));

    if(elim != elim->sig){
        (*p)->sig = elim->sig;
    }
    else{
        *p = NULL;
    }
    return 1;
}

void crearColaC(tColaC *p){
    *p = NULL;
}
void vaciarColaC(tColaC *p){
    tNodo *elim = *p, *pri = *p;
    do{
        *p = elim->sig;
        free(elim->dato);
        free(elim);
        elim = *p;
    }while(elim != pri);
    *p = NULL;
}
int colaVacia(const tColaC *p){
    return (*p == NULL);
}
int colaLlena(const tColaC *p, unsigned tam){
    return 0;
}
int ponerEnCola(tColaC *p, const void *dato, unsigned tam){
    tNodo *nue;
    if((nue = (tNodo*)malloc(sizeof(tNodo))) == NULL || (nue->dato = malloc(tam)) == NULL){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;

    if(*p){
        nue->sig = (*p)->sig;
    }
    else{
        *p = nue;
    }
    (*p)->sig = nue;
    *p = nue;
    return 1;
}
int verPrimero(const tColaC *p, void *dato, unsigned tam){
    if(!*p) return 0;
    memcpy(dato, (*p)->sig->dato, MIN(tam, (*p)->sig->tam));
    return 1;
}
int sacarDeCola(tColaC *p, void *dato, unsigned tam){
    tNodo *elim;
    if(!*p) return 0;

    elim = (*p)->sig;
    memcpy(dato, elim->dato, MIN(tam, elim->tam));

    if(elim != *p){
        (*p)->sig = elim->sig;
    }
    else{
        *p = NULL;
    }
    return 1;
}



