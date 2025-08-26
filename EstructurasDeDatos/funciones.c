#include "funciones.h"

//void crearPila(tPila *p){
//    p->tam = MAX_PILA;
//}
//int pilaVacia(const tPila *p){
//    return p->tam == MAX_PILA;
//}
//int apilar(tPila *p, const void* dato, unsigned tam){
//    if(p->tam < tam + sizeof(unsigned)){
//        return 0;
//    }
//    p->tam -= tam;
//    memcpy(p->pila + p->tam, dato, tam);
//    p->tam -= sizeof(unsigned);
//    memcpy(p->pila + p->tam, &tam, sizeof(unsigned));
//    return 1;
//}
//int verTope(const tPila *p, void* dato, unsigned tam){
//    unsigned tamDato;
//    if(p->tam == MAX_PILA)
//        return 0;
//    memcpy(&tamDato, p->pila + p->tam, sizeof(unsigned));
//    memcpy(dato, p->pila + p->tam + sizeof(unsigned), MIN(tam, tamDato));
//    return 1;
//}
//int desapilar(tPila *p, void* dato, unsigned tam){
//    unsigned tamDato;
//    if(p->tam == MAX_PILA)
//        return 0;
//    memcpy(&tamDato, p->pila + p->tam, sizeof(unsigned));
//    p->tam += sizeof(unsigned);
//    memcpy(dato, p->pila + p->tam, MIN(tam, tamDato));
//    p->tam += tamDato;
//    return 1;
//}
//void vaciarPila(tPila *p){
//    p->tam = MAX_PILA;
//}
//int pilaLlena(const tPila *p, unsigned tam){
//    return (p->tam < (tam + sizeof(unsigned)));
//}


//void crearPila(tPila *p){
//    *p = NULL;
//}
//int pilaVacia(const tPila *p){
//    return *p == NULL;
//}
//int apilar(tPila *p, const void* dato, unsigned tam){
//    tNodo* nue;
//    if(!(nue = (tNodo*)malloc(sizeof(tNodo))) || !(nue->dato = malloc(tam))){
//        free(nue);
//        return 0;
//    }
//    memcpy(nue->dato, dato, tam);
//    nue->tam = tam;
//    nue->sig = *p;
//    *p = nue;
//    return 1;
//}
//int verTope(const tPila *p, void* dato, unsigned tam){
//    if(!*p)
//        return 0;
//    memcpy(dato, (*p)->dato, MIN(tam, (*p)->tam));
//    return 1;
//}
//int desapilar(tPila *p, void* dato, unsigned tam){
//    tNodo *elim = *p;
//    if(!elim)
//        return 0;
//    memcpy(dato, elim->dato, MIN(tam, elim->tam));
//    *p = elim->sig;
//    free(elim->dato);
//    free(elim);
//    return 1;
//}
//void vaciarPila(tPila *p){
//    tNodo *elim = *p;
//    while(elim){
//        *p = elim->sig;
//        free(elim->dato);
//        free(elim);
//        elim = *p;
//    }
//}
//int pilaLlena(const tPila *p, unsigned tam){
//    return 0;
//}

//void crearCola(tCola *p){
//    p->pri = 0;
//    p->ult = 0;
//    p->tam = MAX_COLA;
//}
//int ponerEnCola(tCola *p, const void *dato, unsigned tam){
//    unsigned ini, fin;
//    if(p->tam < sizeof(unsigned) + tam)
//        return 0;
//    p->tam -= sizeof(unsigned) + tam;
//    if((ini = MIN(sizeof(unsigned), MAX_COLA - p->ult)) != 0)
//        memcpy(p->cola + p->ult, &tam, ini);
//    if((fin = sizeof(unsigned) - ini) != 0)
//        memcpy(p->cola, ((char*)&tam) + ini, fin);
//    p->ult = fin ? fin : p->ult + ini;
//    if((ini = tam, MAX_COLA - p->ult)) != 0)
//        memcpy(p->cola + p->ult, dato, ini);
//    if((fin = tam - ini) != 0)
//        memcpy(p->cola, (char*)dato + ini, fin);
//    p->ult = fin ? fin : p->ult + ini;
//    return 1;
//}
//int verPrimero(const tCola *p, void *dato, unsigned tam){
//    unsigned ini, fin, tamDato, pos = p->pri;
//    if(p->tam = MAX_COLA)
//        return 0;
//
//    if((ini = MIN(sizeof(unsigned), MAX_COLA - pos)) != 0)
//        memcpy(&tamDato, p->cola + pos, ini);
//    if((fin = sizeof(unsigned) - ini) != 0)
//        mempcpy(((char*)&tamDato) + ini, p->cola, fin);
//    pos = fin ? fin : pos + ini;
//    tamDato = MIN(tamDato, tam);
//    if((ini = MIN(tamDato, MAX_COLA - pos)) != 0)
//        memcpy(dato, p->cola + pos, ini);
//    if((fin = tamDato - ini) != 0)
//        memcpy((char*)dato + ini, p->cola, fin);
//
//    return 1;
//}
//int sacarDeCola(tCola *p, void *dato, unsigned tam){
//    unsigned ini, fin, tamDato;
//    if(p->tam == MAX_COLA)
//        return 0;
//    p->tam += tam + sizeof(unsigned);
//
//    if((ini = MIN(sizeof(unsigned), MAX_COLA - p->pri)) != 0)
//        memcpy(&tamDato, p->cola + p->pri, ini);
//    if((fin = sizeof(unsigned) - ini) != 0)
//        memcpy((char*)&tamDato + ini, p->cola, fin);
//    p->pri = fin ? fin : p->pri + ini;
//
//    tamDato = MIN(tamDato, tam)
//    if((ini = MIN(tamDato, MAX_COLA - p->pri)) != 0)
//        memcpy(dato, p->cola + p->pri, ini);
//    p->pri = (p->pri + ini < MAX_COLA) ? p->pri + ini : 0;
//    if((fin = tamDato - ini) != 0)
//        memcpy((char*)dato + ini, p->cola + p->pri, fin);
//    p->pri = fin ? fin : p->pri + ini;
//
//    return 1;
//}
//int colaVacia(const tCola *p){
//    return p->pri == p->ult;
//}
//int colaLlena(const tCola *p, unsigned tam){
//    return p->tam < tam + sizeof(unsigned);
//}
//void vaciarCola(tCola *p){
//    p->pri = p->ult;
//}

//void crearCola(tCola *p){
//    p->pri = NULL;
//    p->ult = NULL;
//}
//int ponerEnCola(tCola *p, const void *dato, unsigned tam){
//    tNodo *nue;
//    if(!(nue = (tNodo*)malloc(sizeof(tNodo))) || !(nue->dato = malloc(tam))){
//        free(nue);
//        return 0;
//    }
//    memcpy(nue->dato, dato, tam);
//    nue->tam = tam;
//    nue->sig = NULL;
//    if(p->pri)
//        p->ult->sig = nue;
//    else
//        p->pri = nue;
//    p->ult = nue;
//    return 1;
//}
//int verPrimero(const tCola *p, void *dato, unsigned tam){
//    if(!p->pri)
//        return 0;
//     memcpy(dato, p->pri->dato, MIN(p->pri->tam, tam));
//     return 1;
//}
//int sacarDeCola(tCola *p, void *dato, unsigned tam){
//    tNodo *elim = p->pri;
//    if(!elim)
//        return 0;
//    memcpy(dato, elim->dato, MIN(elim->tam, tam));
//    p->pri = elim->sig;
//    free(elim->dato);
//    free(elim);
//    return 1;
//}
//int colaVacia(const tCola *p){
//    return p->pri == NULL;
//}
//int colaLlena(const tCola *p, unsigned tam){
//    return 0;
//}
//void vaciarCola(tCola *p){
//    tNodo *elim = p->pri;
//    while(elim){
//        p->pri = elim->sig;
//        free(elim->dato);
//        free(elim);
//        elim = p->pri;
//    }
//}

void crearLista(tLista *p){
    *p = NULL;
}
int ponerEnLista(tLista *p, const void *dato, unsigned tam){
    tNodo *nue;
    if(!(nue = (tNodo*)malloc(sizeof(tNodo))) || !(nue->dato = malloc(tam))){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    nue->sig = *p;
    (*p) = nue;
    return 1;
}
int ponerEnListaOrdenado(tLista *p, const void *dato, unsigned tam, tCMP cmp, unsigned duplicados){
    tNodo *nue;
    int res = 1;
    while(*p && (res = cmp(dato, (*p)->dato)) > 0){
        p = &(*p)->sig;
    }
    if(!duplicados && res == 0)
        return 0;
    if(!(nue = (tNodo*)malloc(sizeof(tNodo))) || !(nue->dato = malloc(tam))){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    nue->sig = *p;
    *p = nue;
    return 1;
}
void mapLista(tLista *p, void accion(void *dato)){
    while(*p){
        accion((*p)->dato);
        p = &(*p)->sig;
    }
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
void ordenarListaSeleccion(tLista *p, tCMP cmp){
    tNodo **nodo, **min, *aux;

    while(*p && (*p)->sig){
        min = p;
        nodo = &(*p)->sig;
        while(*nodo){
            if(cmp((*min)->dato, (*nodo)->dato) > 0){
                min = nodo;
            }
            nodo = &(*nodo)->sig;
        }
        if(min != p){
            aux = *min;
            *min = aux->sig;
            aux->sig = *p;
            *p = aux;
        }

        p = &(*p)->sig;
    }
}
void vaciarLista(tLista *p){
    tNodo *elim = *p;
    while(elim){
        p = &(*p)->sig;
        free(elim->dato);
        free(elim);
        elim = *p;
    }
}

int comparar(const void* dato1, const void *dato2){
    unsigned _dato1, _dato2;
    memcpy(&_dato1, dato1, sizeof(unsigned));
    memcpy(&_dato2, dato2, sizeof(unsigned));
    return _dato1 - _dato2;
}

void mostrar(void *dato){
    unsigned tam;
    memcpy(&tam, dato, sizeof(unsigned));
    printf("%s", (char*)dato+sizeof(unsigned));
}

void crearListaDoble(tLista *p){
    *p = NULL;
}
int ponerEnListaDoble(tLista *p, const void *dato, unsigned tam){
    tNodo *nue;
    if(!(nue = (tNodo*)malloc(sizeof(tNodo))) || !(nue->dato = malloc(tam))){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    if(*p){
        nue->sig = *p;
        nue->ant = (*p)->ant;
    }
    else{

        nue->ant = NULL;
        nue->sig = NULL;
    }
    *p = nue;
    return 1;
}
int ponerEnListaDobleOrdenado(tLista *p, const void *dato, unsigned tam, tCMP cmp, unsigned duplicados){
    tNodo *nue, *ant, *sig;
    int res;
    if(*p){
        while((*p)->sig && (res = cmp(dato, (*p)->dato)) > 0)
            p = &(*p)->sig;
        while((*p)->ant && (res = cmp(dato, (*p)->dato)) < 0)
            p = &(*p)->ant;
        if(!duplicados && res == 0){
            return 0;
        }
        if(res < 0){
            sig = *p;
            ant = (*p)->ant;
        }
        else{
            sig = (*p)->sig;
            ant = *p;
        }
    }
    else{
        sig = NULL;
        ant = NULL;
    }
    if(!(nue = (tNodo*)malloc(sizeof(tNodo))) || !(nue->dato = malloc(tam))){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;

    nue->sig = sig;
    nue->ant = ant;
    if(sig)
        sig->ant = nue;
    if(ant)
        ant->sig = nue;
    *p = nue;
    return 1;
}
void mapListaDoble(tLista *p, void accion(void* dato)){
    if(!*p)
        return;
    while((*p)->ant)
        p = &(*p)->ant;
    while(*p){
        accion((*p)->dato);
        p = &(*p)->sig;
    }
}
int sacarDeListaDoble(tLista *p, void *dato, unsigned tam, const void* clave, tCMP cmp){
    tNodo *elim = *p, *ant, *sig;
    int res;
    if(!elim)
        return 0;
    while(elim->sig && (res = cmp(clave, elim->dato)) > 0)
        elim = elim->sig;
    while(elim->ant && (res = cmp(clave, elim->dato)) < 0)
        elim = elim->ant;
    if(res != 0)
        return 0;
    ant = elim->ant;
    sig = elim->sig;
    if(ant)
        ant->sig = sig;
    if(sig)
        sig->ant = ant;

    memcpy(dato, elim->dato, MIN(elim->tam, tam));
    free(elim->dato);
    free(elim);

    if(ant)
        *p = ant;
    else
        *p = sig;
    return 1;
}
void ordenarListaDobleSeleccion(tLista *p, tCMP cmp){
    tNodo *aux, *ini, *min;
    ///Si la lista doble esta vacia ya esta ordenada
    if(!*p)
        return;
    ini = *p;
    ///Me paro en el primer elemento
    while(ini->ant)
        ini = ini->ant;

    while(ini){
        min = ini;
        aux = ini->sig;
        ///mientras haya lista comparo todos los elementos para encontrar el menor
        while(aux){
            if(cmp(min->dato, aux->dato) > 0)
                min = aux;
            aux = aux->sig;
        }
    ///cuando lo encuentro lo intercambio por el primero
        if(ini != min){
            aux = min->ant;
            min->ant = ini->ant;
            ini->ant = aux;
            if(aux)
                aux->sig = ini;

            aux = min->sig;
            min->sig = ini->sig;
            ini->sig = aux;
            if(aux)
                aux->ant = ini;
        }
    ///ahora el primero va a ser el siguiente del minimo
        ini = min->sig;
    }
    *p = min;
}
void vaciarListaDoble(tLista *p);






