#include "lista.h"

int main(){

    Nodo *lista = NULL;

    lista = InsertarInicio(lista, 10);
    lista = InsertarInicio(lista, 11);
    lista = InsertarInicio(lista, 12);
    lista = InsertarInicio(lista, 13);
    show(lista);

    lista = InsertarFinal(lista, 40);
    lista = InsertarFinal(lista, 43);
    show(lista);

    lista = InsertarPosicion(lista, 5, 1);
    lista = InsertarPosicion(lista, 2, 8);
    show(lista);

    lista = EliminarFinal(lista);
    show(lista);
    lista = EliminarInicio(lista);
    show(lista);
    lista = EliminarPosicion(lista, 3);
    show(lista);
}