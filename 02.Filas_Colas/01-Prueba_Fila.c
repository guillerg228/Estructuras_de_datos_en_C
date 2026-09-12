#include "fila.h"

int main(){

    Nodo *first = NULL;
    first = add(first, 3);
    first = add(first, 4);
    first = add(first, 5);
    first = add(first, 6);
    first = add(first, 7);

    show(first);

    first = del(first);
    show(first);
    first = del(first);
    show(first);
    first = del(first);
    show(first);


}