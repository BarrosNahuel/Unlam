#include "ListaSimplementeEnlazada.h"

void crearLista(tLista* pLista)
{
    (*pLista) = NULL;
}
int ponerEnLista(tLista* pLista, const void* dato, unsigned tam)
{
    tNodo* nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue)
        return SIN_MEM;
    nue->dato = malloc(tam);
    if(!nue->dato)
    {
        free(nue);
        return SIN_MEM;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    nue->sig = *pLista;
    *pLista = nue;
    return TODO_OK; ///preferiria un TODO_OK
}
int sacarDeLista(tLista* pLista, void* dato, unsigned tam)
{
    tNodo* elim = *pLista;
    if(!*pLista) ///*pLista == NULL es un poco mas legible
        return ERROR;
    memcpy(dato, elim->dato, MIN(tam, elim->tam));
    *pLista = elim->sig;
    free(elim->dato);
    free(elim);
    return TODO_OK;
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

int mapLista(tLista* pLista, void accion(tNodo* nodo))
{
    tNodo* nodo = *pLista;
    if(!(*pLista))
        return ERROR;
    while(nodo)
    {
        accion(nodo);
        nodo = nodo->sig;
    }
    return TODO_OK;
}

int insertarSinDuplicados(tLista* pLista, const void* dato, unsigned tam, tCMP cmp)
{
    tNodo* nodoActual = *pLista;
    tNodo* nodoNuevo = (tNodo*) malloc(sizeof(tNodo)); ///seria mas viable primero validar que el dato no esta repetido
    if(!nodoNuevo)                                     ///y y luego, si no esta repetido, reservar memoria, copiar dato, etc
        return SIN_MEM;
    nodoNuevo->dato = malloc(tam);
    if(!nodoNuevo->dato)
    {
        free(nodoNuevo);
        return SIN_MEM;
    }
    memcpy(nodoNuevo->dato, dato, tam);
    nodoNuevo->tam = tam;
    while(nodoActual != NULL)
    {
        if(cmp(nodoActual, nodoNuevo))
        {
            free(nodoNuevo->dato);
            free(nodoNuevo);
            return SIN_MEM;
        }
        nodoActual = nodoActual->sig;
    }
    nodoNuevo->sig = *pLista;
    *pLista = nodoNuevo;
    return TODO_OK;
}

int insertarOrdenado(tLista* pLista, const void* dato, unsigned tam, tCMP cmp,int dup)
{
    tNodo* nodoNuevo;
    int comp = 1;

    while(*pLista != NULL && (comp = cmp(dato,(*pLista)->dato)) > 0)
    {
        pLista = &(*pLista)->sig;
    }

    if(dup==NO && comp == 0)///es para no tener duplicados
        return DUPLICADO;

    ///Reservo memoria
    nodoNuevo = (tNodo*) malloc(sizeof(tNodo));
    if(!nodoNuevo)
        return SIN_MEM;
    nodoNuevo->dato = malloc(tam);
    if(!nodoNuevo->dato)
    {
        free(nodoNuevo);
        return SIN_MEM;
    }

    ///Inserto el dato
    memcpy(nodoNuevo->dato, dato, tam);
    nodoNuevo->tam = tam;
    nodoNuevo->sig = *pLista;
    *pLista = nodoNuevo;
    return TODO_OK;
}


int eliminarElemento(tLista* pLista,void* dato, unsigned tam,const void* clave, tCMP cmp)
{
    tNodo* elim;
    if(! *pLista)
        return ERROR;

    while(*pLista != NULL &&  cmp(clave,(*pLista)->dato) != 0)
    {
        pLista = &(*pLista)->sig;
    }
    if(*pLista == NULL)
        return ERROR;

    elim = *pLista;
    *pLista = elim->sig;
    memcpy(dato,elim->dato,tam);

    free(elim->dato);
    free(elim);


    return TODO_OK;
}














