#include "fila.h"

int main(){

    NodoF *first1 = NULL, *first2 = NULL, *first3 = NULL;

    first1 = add(first1, 3);
    first1 = add(first1, 5);
    first1 = add(first1, 8);

    first2 = add(first2, 1);
    first2 = add(first2, 2);
    first2 = add(first2, 4);
    first2 = add(first2, 6);
    first2 = add(first2, 9);
    first2 = add(first2, 10);
    first2 = add(first2, 12);
    first2 = add(first2, 15);

//Unicamente para union de filas ordenadas ascendentemente
    first3 = union_filas(first1, first2);
    show(first3);
}