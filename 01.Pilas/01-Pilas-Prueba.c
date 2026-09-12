#include "pila.h"

int main(){

    Nodo* top = NULL;
    top = push(top, 7);
    top = push(top, 3);
    top = push(top, 9);
    top = push(top, 1);
    show(top);

    top = pop(top);
    printf("\n");
    show(top);
    printf("\nLongitud de la pila: %d",size_p(top));

}
