#include "funciones.h"

int main(){
    float vec[4] = {1.1, 2.2, 3.3, 4.4}, elem = 0;
    unsigned ce = 4;
    for(int i = 0; i<ce; i++){
        printf("[%.2f]", *(vec + i));
    }
    insertarOrdenado(vec, &elem, sizeof(float), &ce, 4, compararFloat);
    SALTO
    for(int i = 0; i<ce; i++){
        printf("[%.2f]", *(vec + i));
    }
    return 0;
}

