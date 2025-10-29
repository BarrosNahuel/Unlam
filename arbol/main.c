#include "arbol.h"
#include "funciones.h"

int main()
{
    int clave, dato, altura, i;
    FILE *pf;
    tArbol arbol;

    crearLote();
    crearArbolB(&arbol);
    crearArchivoIndice("datos.dat", "datos.idx", sizeof(tIndicePersona), leerDatosArchivoPer, compararIndPer);
    pf = fopen("datos.idx", "r+b");
    if(!pf) return 1;
    cargarArbolDesdeArchivoOrdenado(&arbol, pf, sizeof(tIndicePersona), leerDatosArchivoIdx);

    altura = alturaArbol(&arbol);
    for(i=0;i<altura;i++){
        verNodosDeNivel(&arbol, i, mostrarPersonaIdx);
        SALTO
    }
    return 0;
}
