#ifndef _Grafo_H_
#define _Grafo_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _Arista{
    char destino;              // Nombre del vértice destino
    int peso;                  // Peso de la arista
    struct _Arista *siguiente; // lista enlazada de aristas con origen en el mismo vertice
}Arista;

typedef struct _Vertice{
    char nombre;               // Identificador del vértice
    struct _Vertice *siguiente;// Siguiente vértice en la lista
    struct _Arista *relacion;  // Lista de aristas conectadas por el vertice
}Vertice;

Vertice *nVertice(char n){
    Vertice *nuevo = (Vertice*)malloc(sizeof(Vertice));   // El vertice existe, mas no esta enlazado
    nuevo->nombre = n;
    nuevo->siguiente = NULL;
    nuevo->relacion = NULL;
    return nuevo;
}

Arista *nArista(int peso, char destino){
    Arista *nuevo = (Arista*)malloc(sizeof(Arista));   // Se crea una arista con peso y con destino
    nuevo->destino = destino;
    nuevo->peso = peso;
    nuevo->siguiente = NULL;
    return nuevo;
}

Vertice *insertarV(Vertice *first, char n){  // Inserta el vertice en la lista enlazada creada para contenerlos
    Vertice *nuevo = nVertice(n);

    if(first == NULL)
        return nuevo;

    Vertice *aux = first;
    while(aux->siguiente != NULL)
        aux = aux->siguiente;

    aux->siguiente = nuevo;
    return first;
}

Vertice *buscarV(Vertice *first, char nombre){  //Busqueda lineal
    while(first != NULL){
        if(first->nombre == nombre)
            return first;
        first = first->siguiente;
    }
    return NULL; // No encontrado
}



int insertarA(Vertice *first, char origen, char destino, int peso){   // Vertice *first ->

    Vertice *v = buscarV(first, origen);  //Busca el vertice origen
    if(v == NULL) return 0; 

    Arista *nuevo = nArista(peso, destino);  // Crea una arista con el destino y peso dados

//Inserta la arista en la lista enlazada relacionada al nodo origen 
    if(v->relacion == NULL){   
        v->relacion = nuevo;
        return 1;}

    Arista *aux = v->relacion;        // Insertar al final de la lista de aristas
    while(aux->siguiente != NULL)
        aux = aux->siguiente;

    aux->siguiente = nuevo;
    return 1;
}

void verGrafo(Vertice *first){
    if(first == NULL){
        printf("No hay vertices\n");
        return;
    }

    while(first != NULL){  // Recorre / Itera sobre los vertices en la lista
        printf("\nVertice %c -> ", first->nombre);

        Arista *aux = first->relacion;

        if(aux == NULL){          // Itera sobre las aristas relacionadas al vertice actual
            printf("Sin relaciones");
        }else{
            while(aux != NULL){
                printf("(%c, peso=%d)  ", aux->destino, aux->peso);
                aux = aux->siguiente;
            }
        }

        first = first->siguiente;
    }
    printf("\n");
}

#endif
