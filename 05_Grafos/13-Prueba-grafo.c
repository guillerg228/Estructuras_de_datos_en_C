#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


int main() {

    Vertice *lista = NULL;

    // Insertar vértices
    printf("Insertando vertices...\n");
    lista = insertarV(lista, 'A');
    lista = insertarV(lista, 'B');
    lista = insertarV(lista, 'C');

    // Insertar aristas
    printf("Insertando aristas...\n");
    insertarA(lista, 'A', 'B', 3);  // A -> B (3)
    insertarA(lista, 'A', 'C', 5);  // A -> C (5)
    insertarA(lista, 'B', 'C', 2);  // B -> C (2)
    insertarA(lista, 'C', 'A', 4);  // C -> A (4)

    // Ver grafo completo
    printf("\nMostrando grafo:\n");
    verGrafo(lista);

    return 0;
}
