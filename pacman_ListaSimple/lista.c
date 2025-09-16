#include "lista.h"
void crearLista(tLista *p){
    *p = NULL;
}
int insertarOrdenado(tLista *p, const void *dato, unsigned tam, CMP cmp, int duplicado){
    tNodo *nue;
    int comp = 1;

    while((*p) != NULL && (comp = cmp(dato, (*p)->dato)) > 0){
        p = &(*p)->sig;
    }
    if(!duplicado && (comp == 0)){
        return 0;
    }

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
    if(!elim)
        return 0;
    memcpy(dato, elim->dato, MIN(tam, elim->tam));
    *p = elim->sig;
    free(elim->dato);
    free(elim);
    return 1;
}
void mapLista(tLista *p, void accion(void*)){
    while(*p){
        accion((*p)->dato);
        p = &(*p)->sig;
    }
}
void vaciarLista(tLista *p){
    tNodo *elim = *p;
    while(elim){
        *p = elim->sig;
        free(elim->dato);
        free(elim);
        elim = *p;
    }
}




