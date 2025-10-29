#include "funciones.h"

void mostrarInt(const void *d){
    printf("[%d]", *(int*)d);
}

int tautologia(int *v, unsigned cantElem){
    if(cantElem == 0) return 1;
    if(*v == 0) return 0;
    return tautologia(v + 1, cantElem - 1);
}

void* my_memcpy(void *dest, const void *src, unsigned tam){
    int i;
    for(i=0;i<tam;i++){
        *((char*)dest + i) = *((char*)src + i);
    }
    return dest;
}
