#include "lista.h"

void crearLista(tLista *p){
    *p = NULL;
}
int insertarEnLista(tLista *p, const void *dato, unsigned tam){
    tNodo *nue;

    if((nue = (tNodo*)malloc(sizeof(tNodo))) == NULL || (nue->dato = malloc(tam)) == NULL){
        free(nue);
        return 0;
    }

    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    nue->sig = *p;
    *p = nue;

    return 1;
}
int sacarDeLista(tLista *p, void *dato, unsigned tam){
    tNodo *elim = *p;

    if(!elim) return 0;

    memcpy(dato, elim->dato, MIN(elim->tam, tam));
    *p = elim->sig;
    free(elim->dato);
    free(elim);
    return 1;
}
void mostrarListaInversoIt(const tLista *p, void mostrar(const void*)){
    tNodo *act = *p, *fin = NULL;
    while(*p != fin){
        while(act->sig != fin){
            act = act->sig;
        }
        fin = act;
        mostrar(act->dato);
        act = *p;
    }
}
void mostrarListaInversoRec(const tLista *p, void mostrar(const void*)){
    if(!(*p))
        return;
    mostrarListaInversoRec(&(*p)->sig, mostrar);
    mostrar((*p)->dato);
}
void vaciarLista(tLista *p){
    tNodo *elim;
    while(*p){
        elim = *p;
        *p = elim->sig;
        free(elim->dato);
        free(elim);
    }
}
