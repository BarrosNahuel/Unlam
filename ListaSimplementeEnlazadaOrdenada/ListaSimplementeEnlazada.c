#include "ListaSimplementeEnlazada.h"

void crearLista(tLista* pLista)
{
    (*pLista) = NULL;
}
int ponerEnLista(tLista* pLista, const void* dato, unsigned tam)
{
    tNodo* nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tam);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    nue->sig = *pLista;
    *pLista = nue;
    return 1;
}
int sacarDeLista(tLista* pLista, void* dato, unsigned tam)
{
    tNodo* elim = *pLista;
    if(!*pLista)
        return 0;
    memcpy(dato, elim->dato, MIN(tam, elim->tam));
    *pLista = elim->sig;
    free(elim->dato);
    free(elim);
    return 1;
}
int listaVacia(const tLista* pLista)
{
    return (*pLista) == NULL;
}
void vaciarLista(tLista* pLista)
{
    tNodo* elim = *pLista;
    while(*pLista)
    {
        *pLista = elim->sig;
        free(elim->dato);
        free(elim);
        elim = *pLista;
    }
}

void mapLista(tLista* pLista, void accion(tNodo* nodo))
{
    while(*pLista)
    {
        accion(*pLista);
        pLista = &(*pLista)->sig;
    }
}

int insertarSinDuplicados(tLista* pLista, const void* dato, unsigned tam, tCMP cmp)
{
    tNodo* nodoNuevo;
    while(*pLista != NULL)
    {
        if(cmp((*pLista)->dato, dato))
            return 0;
        pLista = &(*pLista)->sig;
    }
    nodoNuevo = (tNodo*) malloc(sizeof(tNodo));
    if(!nodoNuevo)
        return 0;
    nodoNuevo->dato = malloc(tam);
    if(!nodoNuevo->dato)
    {
        free(nodoNuevo);
        return 0;
    }
    memcpy(nodoNuevo->dato, dato, tam);
    nodoNuevo->tam = tam;
    nodoNuevo->sig = *pLista;
    *pLista = nodoNuevo;
    return 1;
}

int insertarOrdenado(tLista* pLista, const void* dato, unsigned tam, tCMP cmp,int duplicado)
{
    tNodo* nodoNuevo;
    int comp = 1;

    while(*pLista != NULL && (comp = cmp(dato,(*pLista)->dato)) > 0)
    {
        pLista = &(*pLista)->sig;
    }

    if(duplicado && comp == 0)
        return 0;

    nodoNuevo = (tNodo*) malloc(sizeof(tNodo));
    if(!nodoNuevo)
        return 0;
    nodoNuevo->dato = malloc(tam);
    if(!nodoNuevo->dato)
    {
        free(nodoNuevo);
        return 0;
    }

    memcpy(nodoNuevo->dato, dato, tam);
    nodoNuevo->tam = tam;
    nodoNuevo->sig = *pLista;
    *pLista = nodoNuevo;
    return 1;
}


int eliminarElementoPorClave(tLista* pLista,void* dato, unsigned tam,const void* clave, tCMP cmp)
{
    tNodo* elim;
    if(! *pLista)
        return 0;

    while(*pLista != NULL &&  cmp(clave,(*pLista)->dato) != 0)
    {
        pLista = &(*pLista)->sig;
    }
    if(*pLista == NULL)
        return 0;

    elim = *pLista;
    *pLista = elim->sig;
    memcpy(dato,elim->dato,tam);

    free(elim->dato);
    free(elim);


    return 1;
}

int unirDuplicadosOrdenado(tLista *pLista, tCMP cmp, tUnir unir){
    tNodo *sig = (*pLista)->sig, *elim;
    if(!*pLista)
        return 0;
    while(sig){
        if(cmp((*pLista)->dato, sig->dato)){
            unir((*pLista)->dato, sig->dato);
            elim = sig;
            sig = elim->sig;
            free(elim->dato);
            free(elim);
        }
        else{
            *pLista = sig;
            sig = (*pLista)->sig;
        }
    }
    return 1;
}













