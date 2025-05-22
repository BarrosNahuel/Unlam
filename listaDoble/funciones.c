#include "funciones.h"

int compararInt(const void* a, const void* b){
    int *dato1 = (int*)a, *dato2 = (int*)b;
    return *dato1 - *dato2;
}
void mostrarInt(const void* a){
    int* dato1 = (int*) a;
    printf("%d\n", *dato1);
}

int esMultiplo(const void* dato, const void* multiplo){
    int *dato1 = (int*)dato, *dato2 = (int*)multiplo;
    return ((*dato1)%(*dato2)==0);
}
