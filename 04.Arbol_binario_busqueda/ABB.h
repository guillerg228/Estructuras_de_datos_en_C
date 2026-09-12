#ifndef _ABB_h_
#define _ABB_h_

#include <stdio.h>
#include <stdlib.h>

#define maximo(a,b)  (((a)>(b))?(a):(b))

typedef struct _Nodo{
    int valor;
    struct _Nodo *izquierda;
    struct _Nodo *derecha;
}Nodo;

Nodo * management(int valor){
    Nodo *nuevo;
    nuevo=(Nodo *)malloc(sizeof(Nodo));
    nuevo->valor=valor;
    nuevo->izquierda=NULL;
    nuevo->derecha=NULL;
    return nuevo;
}


Nodo* insertar(Nodo* arbol, int id) {
    if (arbol == NULL) return management(id);

    if (id < arbol->valor)
        arbol->izquierda = insertar(arbol->izquierda, id);
    else
        arbol->derecha = insertar(arbol->derecha, id);

    return arbol;
}

void preorder(Nodo *arbol){
    if(arbol!=NULL){
        printf("\t %d ",arbol->valor);
        preorder(arbol->izquierda);
        preorder(arbol->derecha);
    }
}


void moverIzquierda(Nodo **arbol){
    Nodo *mayor,*padre;
    padre=(*arbol);
    mayor=(*arbol)->izquierda;
    while(mayor->derecha!=NULL){
        padre=mayor;
        mayor=mayor->derecha;
    }
    (*arbol)->valor=mayor->valor;
    if (padre == (*arbol))
        padre->izquierda=mayor->izquierda;
    else
        padre->derecha=mayor->izquierda;
    (*arbol)=mayor;
}

Nodo* moverIzquierda(Nodo *arbol){
    Nodo *mayor = arbol->izquierda;
    Nodo *padre = arbol;

    while (mayor->derecha != NULL) {
        padre = mayor;
        mayor = mayor->derecha;
    }
    if (padre == arbol)
        padre->izquierda = mayor->izquierda;
    else
        padre->derecha = mayor->izquierda;
    return mayor;
}


void borrarNodo(Nodo **arbol,int valor){
    Nodo *aux;
    if(*(arbol)==NULL){printf("\n\tNo hay nada por borrar.");}
    else{
        if ( valor < (*arbol)->valor)
            borrarNodo(&(*arbol)->izquierda,valor);
        else if ( valor > (*arbol)->valor)
            borrarNodo(&(*arbol)->derecha,valor);
        if (valor == (*arbol)->valor){
            aux=(*arbol);
            if (aux->izquierda == NULL){
                (*arbol)=aux->derecha;
            } else if (aux->derecha == NULL){
                (*arbol)=aux->izquierda;
            }
            else
                moverIzquierda(&aux);

            free(aux);
        }
    }
}

int altura(Nodo *arbol){
    if(arbol==NULL)
        return 0;
    else
        return maximo(altura(arbol->izquierda)+1,altura(arbol->derecha)+1);
}

#endif
