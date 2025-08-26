#include "cola.h"

void crearCola(tCola *cola){
    cola->pri = NULL;
    cola->ult = NULL;
}
int ponerEnCola(tCola *cola, const void *dato, unsigned tam){
    tNodo *nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    nue->sig = NULL;
    if(cola->pri){
        cola->ult->sig = nue;
    }
    else{
        cola->pri = nue;
    }
    cola->ult = nue;
    return 1;
}
int sacarDeCola(tCola *cola, void *dato, unsigned tam){
    tNodo *elim = cola->pri;
    if(!elim){
        return 0;
    }
    memcpy(dato, elim->dato, MIN(tam, elim->tam));
    cola->pri = elim->sig;
    free(elim->dato);
    free(elim);
    return 1;
}
