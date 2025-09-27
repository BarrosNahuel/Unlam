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
    if(!elim)
        return 0;
    memcpy(dato, elim->dato, MIN(elim->tam, tam));
    *p = elim->sig;
    free(elim->dato);
    free(elim);
    return 1;
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
void mapLista(tLista *p, void acc(const void *d)){
    while(*p){
        acc((*p)->dato);
        p = &(*p)->sig;
    }
}
//void ordenarListaSeleccion(tLista *p, CMP cmp){
//    tNodo **min, *aux;
//    while(*p){
//        min = p;
//        aux = (*p)->sig;
//
//        while(aux){
//            if(cmp((*min)->dato, aux->dato) > 0)
//                *min = aux;
//            aux = aux->sig;
//        }
//
//        if(p != min){
//           aux = *p;
//           *p = *min;
//           *min = aux;
//
//           aux = (*p)->sig;
//           (*p)->sig = (*min)->sig;
//           (*min)->sig = aux;
//        }
//        p = &(*p)->sig;
//    }
//}
void ordenarListaSeleccion(tLista *p, CMP cmp){
    tNodo *pri, *aux;
    while(*p){
        pri = *p;
        aux = (*p)->sig;

        while(aux){
            if(cmp((*p)->dato, aux->dato) > 0)
                *p = aux; //<--- aux = *p p=
            aux = aux->sig;
        }

        if(*p != pri){
            aux = (*p)->sig;
            (*p)->sig = pri;
            *p = aux;
        }

        p = &(*p)->sig;
    }
}














