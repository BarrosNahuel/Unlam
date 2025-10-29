#include "arbol.h"


void crearArbol(tArbol *p){
    *p = NULL;
}
int insertarArbolIte(tArbol *p, const void *dato, unsigned tam, tCMP cmp){
    int res;
    while(*p){
        res = cmp(dato, (*p)->dato);
        if(res<0){
            p = &(*p)->izq;
        }
        else{
            if(res>0){
                p = &(*p)->der;
            }
            else{
                return 0;
            }
        }
    }
    (*p) = (tNodo*) malloc(sizeof(tNodo));
    if(!(*p))
        return 0;
    (*p)->dato = malloc(tam);
    if(!(*p)->dato){
        free(*p);
        return 0;
    }
    memcpy((*p)->dato, dato, tam);
    (*p)->tam = tam;
    (*p)->izq = NULL;
    (*p)->der = NULL;
    return 1;
}

int insertarArbolRec(tArbol *p, const void *dato, unsigned tam, tCMP cmp){
    int res;
    if(*p){
        res = cmp(dato, (*p)->dato);
        if(res<0){
            return insertarArbolRec(&(*p)->izq, dato, tam, cmp);
        }
        else{
            if(res>0){
                return insertarArbolRec(&(*p)->der, dato, tam, cmp);
            }
            else{
                return 0;
            }
        }
    }
    (*p) = (tNodo*) malloc(sizeof(tNodo));
    if(!(*p))
        return 0;
    (*p)->dato = malloc(tam);
    if(!(*p)->dato){
        free(*p);
        return 0;
    }
    memcpy((*p)->dato, dato, tam);
    (*p)->tam = tam;
    (*p)->izq = NULL;
    (*p)->der = NULL;
    return 1;
}

void recorrerPreOrden(tArbol *p, void accion(const void* dato)){
    if(!*p)
        return;
    accion((*p)->dato);
    recorrerPreOrden(&(*p)->izq, accion);
    recorrerPreOrden(&(*p)->der, accion);
}
void recorrerInOrden(tArbol *p, void accion(const void* dato)){
    if(!*p)
        return;
    recorrerInOrden(&(*p)->izq, accion);
    accion((*p)->dato);
    recorrerInOrden(&(*p)->der, accion);
}
void recorrerPosOrden(tArbol *p, void accion(const void* dato)){
    if(!*p)
        return;
    recorrerPosOrden(&(*p)->izq, accion);
    recorrerPosOrden(&(*p)->der, accion);
    accion((*p)->dato);
}

int contarNodos(tArbol* p){
    if(!*p)
        return 0;
    return contarNodos(&(*p)->izq) + contarNodos(&(*p)->der) + 1;
}

int contarHojas(tArbol *p){
    if(!*p)
        return 0;
    if(!((*p)->izq) && !((*p)->der))
        return 1;
    return contarHojas(&(*p)->der) + contarHojas(&(*p)->izq);
}

int contarNoHojas(tArbol *p){
    if(!*p)
        return 0;
    if(!((*p)->izq) && !((*p)->der))
        return 0;
    return contarNoHojas(&(*p)->der) + contarNoHojas(&(*p)->izq) + 1;
}
int cantNodosConHijosPorIzq(tArbol *p){
    if(!*p)
        return 0;
    if((*p)->izq)
        return cantNodosConHijosPorIzq(&(*p)->izq) + cantNodosConHijosPorIzq(&(*p)->der) + 1;
    return cantNodosConHijosPorIzq(&(*p)->der);
}

int cantNodosSoloConHijosPorIzq(tArbol *p){
    if(!*p)
        return 0;
    if(!(*p)->der && (*p)->izq)
        return cantNodosSoloConHijosPorIzq(&(*p)->izq) + 1;
    return cantNodosSoloConHijosPorIzq(&(*p)->izq) + cantNodosSoloConHijosPorIzq(&(*p)->der);
}

int alturaDelArbol(tArbol *p){
    return __alturaDelArbol(p, 0);

}

int __alturaDelArbol(tArbol *p, int nivel){
    if(!*p)
        return nivel;
    return MAY(__alturaDelArbol(&(*p)->izq, nivel+1),__alturaDelArbol(&(*p)->der, nivel+1));
}

int cantNodosEnNivel(tArbol *p, int nivel){
    return __cantNodosEnNivel(p, 1, nivel);
}
int __cantNodosEnNivel(tArbol *p, int nivelActual, int nivelMax){
    if(!*p)
        return 0;
    if(nivelActual == nivelMax)
        return 1;
    return __cantNodosEnNivel(&(*p)->izq, nivelActual+1, nivelMax) +
           __cantNodosEnNivel(&(*p)->der, nivelActual+1, nivelMax);
}

int cantNodosHastaNivel(tArbol *p, int nivel){
    return __cantNodosHastaNivel(p, 1, nivel);
}

int __cantNodosHastaNivel(tArbol *p, int nivelActual, int nivelMax){
    if(!*p)
        return 0;
    if(nivelActual <= nivelMax){
        return __cantNodosHastaNivel(&(*p)->izq, nivelActual + 1, nivelMax) +
               __cantNodosHastaNivel(&(*p)->der, nivelActual + 1, nivelMax) + 1;
    }
    return 0;
}

int cantNodosDesdeNivel(tArbol *p, int nivel){
    return __cantNodosDesdeNivel(p, 1, nivel);
}
int __cantNodosDesdeNivel(tArbol *p, int nivelActual, int nivelMax){
    if(!*p)
        return 0;
    if(nivelActual >= nivelMax){
        return __cantNodosDesdeNivel(&(*p)->izq, nivelActual + 1, nivelMax) +
               __cantNodosDesdeNivel(&(*p)->der, nivelActual + 1, nivelMax) + 1;
    }
    return __cantNodosDesdeNivel(&(*p)->izq, nivelActual + 1, nivelMax) +
           __cantNodosDesdeNivel(&(*p)->der, nivelActual + 1, nivelMax);
}
tArbol* buscarPorClave(tArbol *p, const void *dato, tCMP cmp){
    int res;
    if(!*p)
        return NULL;
    res = cmp(dato, (*p)->dato);
    if(res == 0)
        return p;
    else
        if(res<0)
            return buscarPorClave(&(*p)->izq, dato, cmp);
        else
            return buscarPorClave(&(*p)->der, dato, cmp);
}

int cantNodosSubArbolDerClave(tArbol *p, const void *dato, tCMP cmp){
    tArbol *p2 = buscarPorClave(p, dato, cmp);
    if(!*p2)
        return 0;
    return contarNodos(&(*p2)->der);
}

int eliminarHoja(tArbol *p, const void *dato, tCMP cmp){
    int res;
    if(!*p)
        return 0;
    res = cmp(dato, (*p)->dato);
    if(res == 0){
        if((*p)->der || (*p)->izq)
            return 0;
        free((*p)->dato);
        free(*p);
        *p = NULL;
        return 1;
    }
    else
        if(res < 0)
            return eliminarHoja(&(*p)->izq, dato, cmp);
        else
            return eliminarHoja(&(*p)->der, dato, cmp);
}
void eliminarArbol(tArbol *p){
    if(!*p)
        return;
    eliminarArbol(&(*p)->izq);
    eliminarArbol(&(*p)->der);
    free((*p)->dato);
    free((*p));
    (*p) = NULL;
}

void eliminarTodasLasHojas(tArbol *p){
    if(!*p)
        return;
    if(!((*p)->der) && !((*p)->izq)){
        free((*p)->dato);
        free((*p));
        (*p) = NULL;
        ///return;?
    }
    eliminarTodasLasHojas(&(*p)->der);
    eliminarTodasLasHojas(&(*p)->izq);
}
tArbol* menorHoja(tArbol *p){
    if(!*p)
        return NULL;
    while((*p)->izq)
        p = &(*p)->izq;
    return p;
}

tArbol* mayorHoja(tArbol *p){
    if(!*p)
        return NULL;
    while((*p)->der)
        p = &(*p)->der;
    return p;
}

int eliminarPorClave(tArbol *p, void* dato, unsigned tam, const void *clave, tCMP cmp){
    tArbol *raizElim = buscarPorClave(p, clave, cmp);
    tArbol *reemp = raizElim;
    tNodo *elim;

    if(!*raizElim)
        return 0;

    if(alturaDelArbol(&(*raizElim)->der) > alturaDelArbol(&(*raizElim)->izq))
        reemp = menorHoja(raizElim);
    else
        reemp = mayorHoja(raizElim);

    memcpy((*raizElim)->dato, dato, MIN((*raizElim)->tam, tam));
    free((*raizElim)->dato);

    (*raizElim)->dato = (*reemp)->dato;
    (*raizElim)->tam = (*reemp)->tam;

    elim = *reemp;
    if(elim->der)
        *reemp = elim->der;
    else
        *reemp = elim->izq;
    free(elim);

    return 1;
}

///Crea un arbol a partir de archivo, en el arbol se guarda la clave y su posicion en el archivo
//int cargarArbolDesdeDatosDesordenados(tArbol *p, FILE *pf, unsigned tam, tCMP cmp, void escribir(void *dst, const void* src, unsigned pos)){
int cargarArbolDesdeDatosDesordenados(tArbol *p, void *src, unsigned tam, tCMP cmp, unsigned escribir(void *dst, const void* src, unsigned tam)){
    tArbol *raiz = p;
    int res;
    void *dato = malloc(tam);
    if(!dato)
        return 0;
    fread(dato, tam, 1, (FILE*)src);
    (*p) = (tNodo*)malloc(sizeof(tNodo));
    if(!(*p) || !((*p)->tam = escribir(&(*p)->dato, dato, tam))){
        free(*p);
        return 0;
    }
    while(fread(dato, tam, 1, (FILE*)src)){
        p = raiz;
        while(*p && res!=0){
            res = cmp(dato, (*p)->dato);
            if(res == 0)
                break;
            if(res<0)
                p = &(*p)->izq;
            else
                p = &(*p)->der;
            }
        if(res != 0){
            (*p) = (tNodo*)malloc(sizeof(tNodo));
            if(!(*p) || !((*p)->tam = escribir(&(*p)->dato, dato, tam))){
                free(*p);
                return 0;
            }
        }
    }
    free(src);
    return 1;
}

int cargarArbolIndiceDesdeDatosDesordenados(tArbol *p, void *src, unsigned tam, tCMP cmp, unsigned escribirIndice(void *dst, const void* src, int pos)){
    tArbol *raiz = p;
    int res, pos = 0;
    void *dato = malloc(tam);
    if(!src)
        return 0;
    fread(dato, tam, 1, (FILE*)src);
    (*p) = (tNodo*)malloc(sizeof(tNodo));
    if(!(*p) || !((*p)->tam = escribirIndice(&(*p)->dato, src, pos))){
        free(*p);
        return 0;
    }
    while(fread(dato, tam, 1, (FILE*)src)){
        pos++;
        p = raiz;
        while(*p && res!=0){
            res = cmp(dato, (*p)->dato);
            if(res == 0)
                break;
            if(res<0)
                p = &(*p)->izq;
            else
                p = &(*p)->der;
            }
        if(res != 0){
            (*p) = (tNodo*)malloc(sizeof(tNodo));
            if(!(*p) || !((*p)->tam = escribirIndice(&(*p)->dato, src, pos))){
                free(*p);
                return 0;
            }
        }
    }
    free(src);
    return 1;
}

void pasarArbolArchivoBin(tArbol *p, FILE *pf){
    if(!*p)
        return;
    pasarArbolArchivoBin(&(*p)->izq, pf);
    pasarArbolArchivoBin(&(*p)->der, pf);
    fwrite((*p)->dato, (*p)->tam, 1, pf);
}

int cargarArbolDesdeDatosOrdenados(tArbol *p, void *src, tLEER leer, int li, int ls, void *param){
    int med = (ls+li)/2;
    if(ls<li)
        return 1;
    (*p) = (tNodo*)malloc(sizeof(tNodo));
    if(!(*p) || !((*p)->tam = leer(&(*p)->dato, src, med, param))){
        free(*p);
        return 0;
    }
    (*p)->izq = NULL;
    (*p)->der = NULL;
    if(!cargarArbolDesdeDatosOrdenados(&(*p)->izq, src, leer, li, med-1, param))
        return 0;
    return cargarArbolDesdeDatosOrdenados(&(*p)->der, src, leer, med+1, ls, param);
}





