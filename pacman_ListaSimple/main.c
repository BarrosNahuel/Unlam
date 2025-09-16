#include "funciones.h"

int main()
{
    char opcLista;
    int opcDupl;
    tLista lista;
    while((opcLista = menu(MENSAJE_LISTA, OPCIONES_LISTA)) != 'c'){
        opcDupl = (menu(MENSAJE_DUPL, OPCIONES_DUPL) == 'a')?1:0;
        crearLista(&lista);

        if(opcLista == 'a'){
            crearLoteSimple();
            cargarListaArchTxtOrd(&lista, "lote.txt", compararFloat,opcDupl);
            mapLista(&lista, mostrarFloat);
        }
        else{
            crearLoteEstructura();
            cargarListaArchBinOrd(&lista, "lote.dat", compararPersonas,opcDupl);
            mapLista(&lista, mostrarPersona);
        }
        vaciarLista(&lista);
        system("pause");
        system("cls");
    }

    return 0;
}
