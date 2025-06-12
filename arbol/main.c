#include "arbol.h"
/*
                          |100|
                     /           \
                    /             \
                |50|              |200|
               /    \          /        \
            |25|    |70|    |150|        |400|
           /       /    \       \       /     \
        |10|     |60|   |80|    |160| |300|   |450|
       /    \               \
     |5|    |20|            |90|
                \
                |23|
*/
int main()
{
    int vec[] = {100, 200, 50, 25, 70, 150, 400, 10, 20, 60, 80, 160, 300, 450, 5, 23, 90}, i, clave = 25;
    tArbol raiz, *subarbol;
    crearArbol(&raiz);
    for(i=0;i<sizeof(vec)/sizeof(int);i++){
        insertarArbolRec(&raiz, vec+i, sizeof(int), compararInt);
    }
    printf("Recorrido en Pre-Orden:");
    recorrerPreOrden(&raiz, mostrarInt);
    SALTO/*
    printf("Recorrido en In-Orden:");
    recorrerInOrden(&raiz, mostrarInt);
    SALTO
    printf("Recorrido en Pos-Orden:");
    recorrerPosOrden(&raiz, mostrarInt);
    SALTO*/

    eliminarPorClave(&raiz, &i, sizeof(int), &clave, compararInt);

    printf("Recorrido en Pre-Orden:");
    recorrerPreOrden(&raiz, mostrarInt);
/*
    printf("Cantidad de nodos: %d\n", contarNodos(&raiz));
    printf("Cantidad de hojas: %d\n", contarHojas(&raiz));
    printf("Cantidad de NO hojas: %d\n", contarNoHojas(&raiz));
    printf("Cantidad de nodos con hijos por izq: %d\n", cantNodosConHijosPorIzq(&raiz));
    printf("Cantidad de nodos solo con hijos por izq: %d\n", cantNodosSoloConHijosPorIzq(&raiz));
    printf("Altura del arbol: %d\n", alturaDelArbol(&raiz));
    printf("Cantidad de nodos en el nivel 3: %d\n", cantNodosEnNivel(&raiz, 3));
    printf("Cantidad de nodos hasta el nivel 3: %d\n", cantNodosHastaNivel(&raiz, 3));
    printf("Cantidad de nodos desde el nivel 3: %d\n", cantNodosDesdeNivel(&raiz, 3));
    printf("Buscar por clave y mostrar arbol: (clave = 200) ");
    subarbol = buscarPorClave(&raiz, &clave, compararInt);
    recorrerInOrden(subarbol, mostrarInt);
    SALTO
    printf("Cantidade de nodos del subarbol derecho de la clave 200: %d\n", cantNodosSubArbolDerClave(&raiz, &clave, compararInt));
    if(eliminarHoja(&raiz, &hoja, compararInt)){
        printf("Se elimino la hoja con valor %d\n", hoja);
        recorrerInOrden(&raiz, mostrarInt);
    }
    else
        printf("No se elimino la hoja con valor %d", hoja);
    SALTO
    eliminarArbol(&raiz);
    printf("Arbol:");
    recorrerInOrden(&raiz, mostrarInt);*/
    return 0;
}
