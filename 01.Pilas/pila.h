#ifndef _Pila_H_
#define _Pila_H_
#include <stdio.h>
#include <stdlib.h>

// LIFO
/* Aquí agregamos y eliminamos                                     
    ↓
    top → [3] → [2] → [1] → NULL
*/

typedef struct _NodoP{
    int valor;
    struct _NodoP* previo;
}NodoP;

NodoP* managementP(int v){   //Crea el nodo con el valor v
    NodoP* nuevo;
    nuevo = (NodoP*)malloc(sizeof(NodoP));
    nuevo->valor=v;
    nuevo->previo = NULL;
    return nuevo;
}

//Cuando pasamos por valor el Nodo* se copia la dirección de memoria
NodoP* push(NodoP *top, int v){  //Agregar Elementos
    NodoP* nuevo;
    nuevo = managementP(v);

    if (top != NULL){
        nuevo->previo = top;
    }
    return nuevo;
}

NodoP* pop(NodoP *top){
    NodoP* aux = top;   //Referencia del nodo a borrar
    if (top != NULL){
        top = top->previo;
        free(aux);
    }
    return top;
}

void showP(NodoP* top){  //No se modifica la pila original
    if (top==NULL){
        printf("Pila vacia\n");
    }else{
        while (top != NULL){
            printf("%d,  ", top->valor);
            top = top->previo;
        }printf("\n");
    }
}

int size_p(NodoP* top){  //No se modifica la pila original
    int l = 0;
    if (top != NULL){
        while (top != NULL){
            l++;
            top = top->previo;
        }
    }
    return l;
}






NodoP* reversa(NodoP *top){
    NodoP* copia = NULL;
    while (top != NULL){
        copia = push(copia, top->valor);
        top = top ->previo;
    }
    return copia;
}

int capicua(NodoP* top, NodoP* top1){
    int s = 0;

    if (top == NULL){   //si regresa 0 la pila no tiene valores a coparar
        return s;
    }else{
        while (top != NULL){
            if (top->valor == top1->valor){   
                top = pop(top);
                top1 = pop(top1);
            }else{
                return 1;  //Si regresa 1 significa que no es capicua
            }
        }
    }
    return 2;  //Si regresa 2 significa que terminó exitosamente, por lo tanto es capicua
}
#endif
