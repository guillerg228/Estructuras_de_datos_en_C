#ifndef _BIBLIOTECA_h_
#define _BIBLIOTECA_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maximo(a,b)  (((a)>(b))?(a):(b))

typedef struct _Libro {
    char titulo[100];
    char autor[100];
    int anio;
    struct _Libro *izquierda;
    struct _Libro *derecha;
} Libro;

Libro * crearLibro(char *titulo, char *autor, int anio){
    Libro *nuevo;
    nuevo=(Libro *)malloc(sizeof(Libro));

    strcpy(nuevo->titulo, titulo);
    strcpy(nuevo->autor, autor);
    nuevo->anio = anio;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;
    return nuevo;
}

Libro* insertarLibro(Libro* estante, char *titulo, char *autor, int anio) {
    if (estante == NULL)    return crearLibro(titulo, autor, anio);
    
    if (anio < estante->anio)
        estante->izquierda = insertarLibro(estante->izquierda, titulo, autor, anio);
    else
        estante->derecha = insertarLibro(estante->derecha, titulo, autor, anio);
    
    return estante;
}

void mostrarLibro(Libro *libro){
    printf("\n\t------------------------------------------");
    printf("\n\tTitulo: %s", libro->titulo);
    printf("\n\tAutor: %s", libro->autor);
    printf("\n\tAnio: %d", libro->anio);
    printf("\n\t------------------------------------------");
}

void inorden(Libro *estante){
    if(estante != NULL){
        inorden(estante->izquierda);
        mostrarLibro(estante);
        inorden(estante->derecha);
    }
}

void preorden(Libro *estante){
    if(estante != NULL){
        mostrarLibro(estante);
        preorden(estante->izquierda);
        preorden(estante->derecha);
    }
}

void postorden(Libro *estante){
    if(estante != NULL){
        preorden(estante->izquierda);
        preorden(estante->derecha);
        mostrarLibro(estante);
    }
}

Libro* buscarLibro(Libro *estante, int anio){
    if(estante == NULL)
        return NULL;
    
    if(anio == estante->anio)        // Compara por año
        return estante;
    else if(anio < estante->anio)     // Si el año es menor, va a la izquierda
        return buscarLibro(estante->izquierda, anio);
    else                              // Si el año es mayor, va a la derecha
        return buscarLibro(estante->derecha, anio);
}

void moverIzquierda(Libro **estante){
    Libro *mayor, *padre;
    padre = (*estante);
    mayor = (*estante)->izquierda;
    
    while(mayor->derecha != NULL){
        padre = mayor;
        mayor = mayor->derecha;
    }
    strcpy((*estante)->titulo, mayor->titulo);
    strcpy((*estante)->autor, mayor->autor);
    (*estante)->anio = mayor->anio;
    
    if (padre == (*estante))
        padre->izquierda = mayor->izquierda;
    else
        padre->derecha = mayor->izquierda;
    (*estante) = mayor;
}

void eliminarLibro(Libro **estante, int anio){
    Libro *aux;
    if(*estante == NULL){
        printf("\n\tLibro del anio %d no encontrado.", anio);
    } else {
        if (anio < (*estante)->anio)           // Compara por año
            eliminarLibro(&(*estante)->izquierda, anio);
        else if (anio > (*estante)->anio)      // Compara por año
            eliminarLibro(&(*estante)->derecha, anio);
        else if (anio == (*estante)->anio){    // Encuentra el año
            aux = (*estante);
            if (aux->izquierda == NULL){
                (*estante) = aux->derecha;
            } else if (aux->derecha == NULL){
                (*estante) = aux->izquierda;
            } else
                moverIzquierda(&aux);
            printf("\n\tLibro del anio %d eliminado del estante.", anio);
            free(aux);
        }
    }
}

int altura(Libro *estante){
    if(estante == NULL)
        return 0;
    else
        return maximo(altura(estante->izquierda)+1, altura(estante->derecha)+1);
}

int contarLibros(Libro *estante){
    if(estante == NULL)
        return 0;
    else
        return 1 + contarLibros(estante->izquierda) + contarLibros(estante->derecha);
}

#endif