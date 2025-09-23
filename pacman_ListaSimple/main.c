#include "funciones.h"

int main()
{
    char opcLista, opcAcum = SIN_ACUM;
    int opcDupl;
    tLista lista;

    crearLista(&lista);
    crearLoteSimple();
    crearLoteEstructura();

    while((opcLista = menu(MENSAJE_LISTA, OPCIONES_LISTA)) != 'c'){
        opcDupl = (menu(MENSAJE_DUPL, OPCIONES_DUPL) == 'a') ? CON_DUPL : SIN_DUPL;
        if(opcDupl == SIN_DUPL)
            opcAcum = menu(MENSAJE_ACUM, OPCIONES_ACUM);

        if(opcLista == 'a'){
            if(opcAcum == CON_ACUM)
                cargarListaArchTxtOrd(&lista, "lote.txt", compararFloat, opcDupl, accFloat);
            else
                cargarListaArchTxtOrd(&lista, "lote.txt", compararFloat, opcDupl, NULL);

            mapLista(&lista, mostrarFloat);
        }
        else{
            if(opcAcum == CON_ACUM)
                cargarListaArchBinOrd(&lista, "lote.dat", compararProductos, opcDupl, accProductos);
            else
                cargarListaArchBinOrd(&lista, "lote.dat", compararProductos, opcDupl, NULL);

            mapLista(&lista, mostrarProductos);
        }
        vaciarLista(&lista);
        system("pause");
        system("cls");
    }

    return 0;
}
