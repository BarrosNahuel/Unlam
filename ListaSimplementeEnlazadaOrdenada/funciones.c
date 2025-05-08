#include "funciones.h"

int crearLotePruebas(tLista *pLista){
    int i;
    tPedido pedidos[] = {
        ///ordenado
//        {3522, "Pañales", 5},
//        {3522, "Pañales", 1},
//        {3522, "Pañales", 6},
//        {3540, "Chupetes", 2},
//        {3540, "Chupetes", 1},
//        {3540, "Chupetes", 3},
//        {3540, "Chupetes", 1},
//        {3641, "Lapices", 5},
//        {3644, "Gomas", 10},
//        {3644, "Gomas", 10},
//        {3644, "Gomas", 10},
//        {3644, "Gomas", 10},
//        {3644, "Gomas", 10},
//        {3644, "Gomas", 10},
//        {3644, "Gomas", 10},
//        {3644, "Gomas", 10},
//        {3644, "Gomas", 10},
//        {3644, "Gomas", 10},
//        {3645, "Borrador", 5}
        ///DESORDENADO
        {3522, "Pañales", 1},
        {3522, "Pañales", 6},
        {3540, "Chupetes", 2},
        {3522, "Pañales", 5},
        {3540, "Chupetes", 1},
        {3641, "Lapices", 5},
        {3644, "Gomas", 10},
        {3644, "Gomas", 10},
        {3644, "Gomas", 10},
        {3644, "Gomas", 10},
        {3540, "Chupetes", 1},
        {3644, "Gomas", 10},
        {3644, "Gomas", 10},
        {3644, "Gomas", 10},
        {3540, "Chupetes", 3},
        {3644, "Gomas", 10},
        {3644, "Gomas", 10},
        {3644, "Gomas", 10},
        {3645, "Borrador", 5}
    };
    for(i=0;i<sizeof(pedidos)/sizeof(tPedido);i++){
        ponerEnLista(pLista, pedidos+i, sizeof(tPedido));
    }
    return 1;
}
void mostrarPedidos(tNodo *nodo){
    tPedido pedido;
    memcpy(&pedido, nodo->dato, MIN(nodo->tam, sizeof(tPedido)));
    printf("Descripcion: %s\nCodigo: %d\nCantidad: %d\n\n", pedido.desc, pedido.cod, pedido.cant);
}
int compararPedidos(const void* dato1,const void* dato2){
    tPedido *ped1 = (tPedido*)dato1;
    tPedido *ped2 = (tPedido*)dato2;

    return (ped1->cod == ped2->cod);
}
int unirPedidos(void* orig, const void* dupl){
    tPedido *pedidoOrig = (tPedido*)orig;
    tPedido *pedidoDupl = (tPedido*)dupl;

    pedidoOrig->cant += pedidoDupl->cant;
    return 1;
}
int compararPersonasDni(const void* dato1,const void* dato2)
{
    tPersona* per1 = (tPersona*)dato1;
    tPersona* per2 = (tPersona*)dato2;

    return(per1->id - per2->id);

}

int compararPersonasNombre(const void* dato1,const void* dato2)
{
    tPersona* per1 = (tPersona*)dato1;
    tPersona* per2 = (tPersona*)dato2;

    return(strcmp(per1->nombre,per2->nombre));

}

int compararPersonasNombreClave(const void* dato1,const void* dato2)
{
    char* per1 = (char*)dato1;
    tPersona* per2 = (tPersona*)dato2;

    return(strcmp(per1,per2->nombre));

}

void cambiarDni(tNodo* nodo)
{
    tPersona persona;
    memcpy(&persona, nodo->dato, MIN(sizeof(tPersona), nodo->tam));
    persona.id = 0000;
    memcpy(nodo->dato, &persona, sizeof(tPersona));
}
void mostrarPersonas(tNodo* nodo)
{
    tPersona persona;
    memcpy(&persona, nodo->dato, MIN(sizeof(tPersona), nodo->tam));
    printf("Nombre: %s, DNI: %d\n", persona.nombre, persona.id);
}
