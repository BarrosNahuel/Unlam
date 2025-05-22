#include "listaDoble.h"

void crearLista(tLista* pLista){
    *pLista = NULL;
}
int listaVacia(tLista* pLista){
    return *pLista == NULL;
}
int insertarOrdenado(tLista* pLista, const void* dato, unsigned tam, tCMP cmp){///¿Duplicado?¿Accion?
    tNodo *nue, *ant, *act = *(pLista), *sig;
    int res;
    ///Si la lista está vacia
    if(!act){
        ant = NULL;
        sig = NULL;
    }
    ///Sino, me muevo para encontrar donde va
    else{
        while(act->sig && cmp(dato, act->dato)>0){
            act = act->sig;
        }
        while(act->ant && cmp(dato, act->dato)<0){
            act = act->ant;
        }
        ///sin duplicado o sino me fijo y hago la accion
        if((res = cmp(dato, act->dato))==0){
            return 0;
        }
    ///Me fijo como van ant y sig dependiendo si va a la izq o der de act
        if(res<0){
            ant = act->ant;
            sig = act;
        }
        else{
            ant = act;
            sig = act->sig;
        }
    }

    ///reservo memoria para nodo
    nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;

    ///Engancho el nodo a la lista
    nue->ant = ant;
    nue->sig = sig;
    if(ant)
        ant->sig = nue;
    if(sig)
        sig->ant = nue;

    *pLista = nue;
    return 1;
}
void mapListaDobleDerecha(tLista* pLista, void accion(const void*)){
    tNodo *aux = *(pLista);
    while(aux){
        accion(aux->dato);
        aux = aux->sig;
    }
}
void mapListaDobleIzquierda(tLista* pLista, void accion(const void*)){
    tNodo *aux = *(pLista);
    while(aux){
        accion(aux->dato);
        aux = aux->ant;
    }
}
int eliminarDeLista(tLista* pLista, void* dato, unsigned tam, void* clave, tCMP cmp){
    tNodo *act = *pLista, *ant, *sig;
    if(!act){
        return 0;
    }
    ///Sino me muevo para encontrar el que quiero
    while(act->sig && cmp(clave, act->dato)>0){
        act = act->sig;
    }
    while(act->ant && cmp(clave, act->dato)<0){
        act = act->ant;
    }
    ///si no lo encontre me voy
    if(cmp(clave, act->dato)!=0){
        return 0;
    }
    sig = act->sig;
    ant = act->ant;
    ///Desengancho el nodo a la lista
    if(ant)
        ant->sig = sig;
    if(sig)
        sig->ant = ant;
    ///copio la info
    memcpy(dato, act->dato, MIN(tam, act->tam));
    ///libero el nodo
    free(act->dato);
    free(act);
    ///Dejo pLista apuntando al sig o al ant
    if(sig)
        *pLista = sig;
    else
        *pLista = ant;
    return 1;
}
int eliminarVarios(tLista* pLista, void* clave, tCMP cmp){///DONDE QUEDA APUNTANDO PLISTA?
    tNodo *act = *pLista, *elim;
    if(!act){
        return 0;
    }
    *pLista = act->ant;///<-----

    while(act){
        if(cmp(clave, act->dato)==0){
            elim = act;
            act = act->sig;
            eliminarNodo(elim);
        }
        else
            act = act->sig;
    }
    act = *pLista;///<-----
    if(act->sig)
        *pLista =act->sig;
    else

    while(act){
        if(cmp(clave, act->dato)==0){
            elim = act;
            act = act->ant;
            eliminarNodo(elim);
        }
        else
            act = act->ant;
    }
//    pLista = ?? ///<-----
    return 1;
}
void vaciarLista(tLista* pLista){
    tNodo *act = *pLista, *sig = (*pLista)->sig, *ant = (*pLista)->ant;
    while(act->sig){
        free(act->dato);
        free(act);
        act = sig;
        sig = act->sig;
    }
    act = *pLista;
    while(act->ant){
        free(act->dato);
        free(act);
        act = ant;
        ant = act->ant;
    }
    *pLista = NULL;
}

int eliminarNodo(tNodo* nodo){
    tNodo *ant, *sig;
    if(!nodo)
        return 0;
    sig = nodo->sig;
    ant = nodo->ant;
    if(ant)
        ant->sig = sig;
    if(sig)
        sig->ant = ant;
    free(nodo->dato);
    free(nodo);
    return 1;
}
