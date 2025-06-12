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

int compararInt(const void* dato1, const void *dato2){
    return *(int*)dato1 - *(int*)dato2;
}
void recorrerPreOrden(tArbol *p, void accion(void* dato)){
    if(!*p)
        return;
    accion((*p)->dato);
    recorrerPreOrden(&(*p)->izq, accion);
    recorrerPreOrden(&(*p)->der, accion);
}
void recorrerInOrden(tArbol *p, void accion(void* dato)){
    if(!*p)
        return;
    recorrerInOrden(&(*p)->izq, accion);
    accion((*p)->dato);
    recorrerInOrden(&(*p)->der, accion);
}
void recorrerPosOrden(tArbol *p, void accion(void* dato)){
    if(!*p)
        return;
    recorrerPosOrden(&(*p)->izq, accion);
    recorrerPosOrden(&(*p)->der, accion);
    accion((*p)->dato);
}
void mostrarInt(void* dato){
    printf("%d ", *(int*)dato);
}
void contarNodosTrampa(tArbol *p, int* cant){
    if(!*p)
        return;
    (*cant)++;
    contarNodosTrampa(&(*p)->izq, cant);
    contarNodosTrampa(&(*p)->der, cant);
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
///revisar que sea hoja
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
///agregar funciones de mayor y menor hoja
int eliminarPorClave(tArbol *p, void* dato, unsigned tam, const void *clave, tCMP cmp){
    tArbol *raizElim = buscarPorClave(p, clave, cmp);
    tArbol *reemp = raizElim;
    tNodo *elim;
    if(!*raizElim)
        return 0;
    if(alturaDelArbol(&(*raizElim)->der) > alturaDelArbol(&(*raizElim)->izq)){
        while((*reemp)->izq)
            reemp = &(*reemp)->izq;
    }
    else{
        while((*reemp)->der)
            reemp = &(*reemp)->der;
    }

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

///calcular la cantidad de registros,
///indiceBal(ini, fin, raiz)
///si fin < ini FIN
///calculo medio
/// acceso directo con el medio sobre el archivo
/// leo el registro
/// pongo esa clave en la pos en raiz
/// indiceBal(ini, medio-1, raiz->izq)
/// indiceBal(medio+1, fin, raiz->der)
///





