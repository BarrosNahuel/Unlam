#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "ListaSimplementeEnlazada.h"
#define TAM_DESC 30
#define TAM_NOM 30
typedef struct
{
    int id;
    char nombre[TAM_NOM];
} tPersona;

typedef struct{
    int cod;
    char desc[TAM_DESC];
    int cant;
}tPedido;
///PEDIDOS
void mostrarPedidos(tNodo *nodo);
int unirPedidos(void* orig, const void* dupl);
int compararPedidos(const void* dato1,const void* dato2);

///PERSONAS
void mostrarPersonas(tNodo* nodo);
void cambiarDni(tNodo* nodo);
int compararPersonasDni(const void* dato1,const void* dato2);
int compararPersonasNombre(const void* dato1,const void* dato2);
int compararPersonasNombreClave(const void* dato1,const void* dato2);
int crearLotePruebas(tLista *pLista);


#endif // FUNCIONES_H_INCLUDED
