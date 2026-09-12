// Libreria para grafos no diriginos y no ponderados

#ifndef _GRAFO_H_
#define _GRAFO_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _Arista{
    char origen;         //Nombres de los vertices de origen y destino
    char destino;
    int peso;
    struct _Arista *aristasEnVertice;  // lista enlazada de aristas con origen en el mismo vertice
} Arista;

typedef struct _Vertice{
    char nombre;
    struct _Vertice *siguiente;  // Siguiente vértice en la lista (para lista enlazada de vertices)
    struct _Arista *listAd;    // Lista de aristas conectadas por el vertice (lista de adyacencia)
} Vertice;



Vertice *crearVertice(char n){
    Vertice *nuevo = (Vertice*)malloc(sizeof(Vertice)); // El vertice existe, mas no esta enlazado a nada
    nuevo->nombre = n;
    nuevo->siguiente = NULL;
    nuevo->listAd = NULL;
    return nuevo;
}

Arista *crearArista(char origen, char destino, int peso){ // Se crea una arista con peso, origen y destino. No se enlaza
    Arista *nuevo = (Arista*)malloc(sizeof(Arista));
    nuevo->origen = origen;
    nuevo->destino = destino;
    nuevo->peso = peso;
    nuevo->aristasEnVertice = NULL;
    return nuevo;
}

Vertice *insertarVertice(Vertice *first, char n){  // Inserta el vertice al final la lista enlazada creada para contenerlos
    Vertice *nuevo = crearVertice(n);

    if(first == NULL)
        return nuevo;

    Vertice *aux = first;
    while(aux->siguiente != NULL)
        aux = aux->siguiente;

    aux->siguiente = nuevo;
    return first;
}

Vertice *buscarVertice(Vertice *first, char n){  // Busca linealmente el vertice mediante su nombre
    while(first != NULL){
        if(first->nombre == n)
            return first;
        first = first->siguiente;
    }
    return NULL;
}


//Como el grafo es no dirigido, tenemos que realcionar la arista con ambos vertices, lo que se traduce en actualizar ambas listas de adyacencia

int insertarArista(Vertice *first, char origen, char destino, int peso, Arista **listaGlobal){

    Vertice *v1 = buscarVertice(first, origen);   // Se buscan los vertices de origen y destino que conectara la arista
    Vertice *v2 = buscarVertice(first, destino);

    if(v1 == NULL || v2 == NULL)   // verifica que los vertices existan
        return 0;  

    Arista *a1 = crearArista(origen, destino, peso);  //Crea una arista con los datos pasados como parametros (nodo de destino)
    a1->aristasEnVertice = v1->listAd;// Las aristas en el vertice que se enlaza la nueva arista tienen que ser las mismas que en la lista de adyasencia de dicho vertice
    v1->listAd = a1;     // El vertice 1 (origen) se relaciona con la arista creada, la arista se añade a la lista de adyacencia de dicho vertice

    Arista *a2 = crearArista(destino, origen, peso); // Hace lo mismo que en a1 y v1 pero con la arista origen
    a2->aristasEnVertice = v2->listAd;
    v2->listAd = a2;

    Arista *g = crearArista(origen, destino, peso);  //Agrega una sola arista a la lista de todas las aristas (A la que accedera kruskal)
    g->aristasEnVertice = *listaGlobal;
    *listaGlobal = g;

    return 1;
}


void verGrafo(Vertice *first){
    if(first == NULL){  
        printf("No hay vertices\n");
        return;
    }

    while(first != NULL){   // While para recorrer los vertices
        printf("\nVertice %c -> ", first->nombre);

        Arista *aux = first->listAd;  // Aux sirve para recorrer las aristasn en la lista de adyasencia del vertice actual

        if(aux == NULL){
            printf("Sin relaciones");
        }else{
            while(aux != NULL){
                printf("(%c, peso=%d)  ", aux->destino, aux->peso);  //Imprime los dartos
                aux = aux->aristasEnVertice;
            }
        }

        first = first->siguiente;
    }
    printf("\n");
}

void verAristasGlobales(Arista *lista){
    printf("\nLista GLOBAL de aristas:\n");
    while(lista != NULL){
        printf("(%c - %c, peso=%d)\n", lista->origen, lista->destino, lista->peso);
        lista = lista->aristasEnVertice;
    }
}

#endif
