#include "listacircular.h"
int main()
{
    tProducto productos[CANT_PRODUCTOS]=
    {
        {"1)Martillo","Martillo de carpintero",25},
        {"2)Destornillador","Destornillador plano",40},
        {"3)Llave inglesa","Llave ajustable 12''",15},
        {"4)Taladro","Taladro electrico 500W",10},
        {"5)Alicate","Alicate de corte",30},
        {"6)Cinta métrica","Cinta de 5 metros",35},
        //{"Nivel",                   "Nivel de burbuja 40cm",12},
        {"7)Pala","Pala de punta",18},
        {"8)Maza","Maza de demolicion",8},
        {"9)Cuter","Cuter retractil",45},
        {"10)Llave Allen","Juego de llaves Allen",25},
        {"11)Tenaza","Tenaza de construccion",30},
    };
    tCola cola;
    crearCola(&cola);
    tProducto produ;

    printf(colaVacia(&cola)?"\nPILA VACIA":"\nPILA NO VACIA");
    for(int i=0; i<CANT_PRODUCTOS; i++)
    {
        ponerEnCola(&cola,&productos[i],sizeof(tProducto));
        printf("\n%-9s: %-20s%-25s%d","APILADO",productos[i].producto,productos[i].descripcion,productos[i].stock);
    }
    printf(colaVacia(&cola)?"\nPILA VACIA":"\nPILA NO VACIA");

    puts("\n\n\n");
    verTopeDeCola(&cola,&produ,sizeof(tProducto));
    printf("\n%-9s: %-20s%-25s%d","TOPE:",produ.producto,produ.descripcion,produ.stock);
    puts("\n\n\n");
    for(int i=0; i<CANT_PRODUCTOS; i++)
    {
        sacarDeCola(&cola,&produ,sizeof(tProducto));
        printf("\n%-9s: %-20s%-25s%d","DESAPILADO",produ.producto,produ.descripcion,produ.stock);//""
    }
    printf(colaVacia(&cola)?"\nPILA VACIA":"\nPILA NO VACIA");

/*
    vaciarCola(&cola);
    printf(colaVacia(&cola)?"\nPILA VACIA":"\nPILA NO VACIA");

    tPila pila;
    tProducto produ;
    crearPila(&pila);

    printf(pilaVacia(&pila)?"\nPILA VACIA":"\nPILA NO VACIA");
    for(int i=0; i<CANT_PRODUCTOS; i++)
    {
        apilar(&pila,&productos[i],sizeof(tProducto));
        printf("\n%-9s: %-20s%-25s%d","APILADO",productos[i].producto,productos[i].descripcion,productos[i].stock);
    }
    printf(pilaVacia(&pila)?"\nPILA VACIA":"\nPILA NO VACIA");

    puts("\n\n\n");
    verTopePila(&pila,&produ,sizeof(tProducto));
    printf("\n%-9s: %-20s%-25s%d","TOPE:",produ.producto,produ.descripcion,produ.stock);
    puts("\n\n\n");
    for(int i=0; i<CANT_PRODUCTOS; i++)
    {
        desapilar(&pila,&produ,sizeof(tProducto));
        printf("\n%-9s: %-20s%-25s%d","DESAPILADO",produ.producto,produ.descripcion,produ.stock);//""
    }


    vaciarPila(&pila);
    printf(pilaVacia(&pila)?"\nPILA VACIA":"\nPILA NO VACIA");
*/
    return 0;
}
