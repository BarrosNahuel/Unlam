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
        if(cmp((*pLista)->dato, dato)==0)
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
    tNodo *sig, *elim;
    if(!*pLista)
        return 0;
    sig = (*pLista)->sig;
    while(sig){
        if(cmp((*pLista)->dato, sig->dato)==0){
            unir((*pLista)->dato, sig->dato);
            elim = sig;
            sig = elim->sig;
            (*pLista)->sig = sig;
            free(elim->dato);
            free(elim);
        }
        else{
            pLista = &(*pLista)->sig;
            sig = (*pLista)->sig;
        }
    }
    return 1;
}

void unirDuplicadosDesordenado(tLista *pLista, tCMP cmp, tUnir unir){
    tNodo **sig, *elim;
    int flag = 1;
    while(*pLista){
        ///Me paro en el puntero a la direccion del nodo al que voy a comparar,
        ///entonces si la comparacion da verdadera elimino el nodo apuntado por
        ///"nodo->sig" y puedo actualizar "nodo->sig" al siguiente nodo del nodo eliminado.

        ///Si no utilizo un doble puntero y elimino un nodo, el "nodo->sig" del nodo
        ///anterior al que elimine va a seguir apuntando a ese nodo que ya elimine y
        ///no tengo forma de cambiarlo.

        sig = &(*pLista)->sig;
        while(*sig){
            if(cmp((*pLista)->dato, (*sig)->dato)==0){
                unir((*pLista)->dato, (*sig)->dato);
                elim = *sig;
                *sig = elim->sig;
                ///Si el nodo siguiente a pLista se elimina, se actualiza pLista->sig
                if(flag){
                    (*pLista)->sig = *sig;
                }
                free(elim->dato);
                free(elim);
            }
            else{
                sig = &(*sig)->sig;
                ///actualizo la bandera porque ya no voy a tener que modificar el siguiente de pLista
                flag = 0;
            }
        }
        ///Avanzo pLista porque ya uní todos los de ese tipo, vuelvo a poner la flag en 1 por si tengo
        ///que actualizar pLista->sig
        pLista = &(*pLista)->sig;
        flag = 1;
    }
}

void ordenarListaBurbujeo(tLista *pLista, tCMP cmp)
{
    tNodo** nodo;
    tNodo* aux;
    int desordenado;

    do
    {
        desordenado = 0;
        nodo = pLista;

        while(*nodo && (*nodo)->sig)
        {
            if(cmp((*nodo)->dato, (*nodo)->sig->dato) > 0)
            {
                // NODO -> B -> A -> C
                aux = (*nodo)->sig; // AUX = A
                (*nodo)->sig = aux->sig; // B -> C
                aux->sig = *nodo; // A -> B
                *nodo = aux; // NODO -> A
                // NODO -> A -> B -> C

                desordenado = 1;
            }
            nodo = &(*nodo)->sig;
        }
    }while(desordenado);
}

void mapListaInversoRec(tLista *pLista, void accion(tNodo *nodo)){
    if(!(*pLista))
        return;
    mapListaInversoRec(&(*pLista)->sig, accion);
    accion(*pLista);
}
void mapListaInversoIte(tLista *pLista, void accion(tNodo *nodo)){
    tNodo *ini = *pLista, *fin = NULL;

    while(ini != fin){
        pLista = &ini;
        while((*pLista)->sig != fin)
            pLista = &(*pLista)->sig;
        accion(*pLista);
        fin = *pLista;
    }
}











