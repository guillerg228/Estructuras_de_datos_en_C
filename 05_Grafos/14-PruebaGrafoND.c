#include <stdio.h>
#include "grafoND.h"

int main() {

    Vertice *listaVertices = NULL;   // Lista enlazada de vértices
    Arista *listaGlobal = NULL;      // Lista global de TODAS las aristas


    listaVertices = insertarVertice(listaVertices, 'A');
    listaVertices = insertarVertice(listaVertices, 'B');
    listaVertices = insertarVertice(listaVertices, 'C');
    listaVertices = insertarVertice(listaVertices, 'D');


    printf("\nInsertando aristas no dirigidas...\n");

    insertarArista(listaVertices, 'A', 'B', 3, &listaGlobal);
    insertarArista(listaVertices, 'A', 'C', 1, &listaGlobal);
    insertarArista(listaVertices, 'B', 'D', 4, &listaGlobal);
    insertarArista(listaVertices, 'C', 'D', 2, &listaGlobal);
    insertarArista(listaVertices, 'B', 'C', 5, &listaGlobal);


    printf("\nMostrando grafo (lista de adyacencia):\n");
    verGrafo(listaVertices);


    printf("\nMostrando lista global de aristas:\n");
    verAristasGlobales(listaGlobal);


    return 0;
}
