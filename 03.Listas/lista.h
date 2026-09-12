#ifndef _Lista_H_
#define _Lista_H_
#include <stdlib.h>
#include <stdio.h>

/*INICIO                                      FINAL
    ↓                                          ↓
    first → [1] → [2] → [3] → [último] → NULL
*/

typedef struct _Nodo{
    int valor;
    struct _Nodo* previo;
}Nodo;


Nodo* management(int v){   //Manejo de memoria
    Nodo* nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor=v;
    nuevo->previo = NULL;
    return nuevo;
}

//Mostrar lista
void show(Nodo* lista){
    if (lista==NULL){
        printf("Fila vacia\n");
    }else{
        while (lista != NULL){  // Recorre hasta antes de llegar al NULL, "a la derecha"
            printf("%d,  ", lista->valor);
            lista = lista->previo;
        }printf("\n");
    }
}

// Tamaño de la lista
int size_l(Nodo* first){
    int l = 0;
    if (first != NULL){
        while (first != NULL){
            l++;
            first = first->previo;
        }
    }
    return l;
}

// Insertar al Inicio (Push para pilas)
Nodo* InsertarInicio(Nodo* top, int valor){
    Nodo* nuevo;
    nuevo = management(valor);

    if (top != NULL){
        nuevo->previo = top;   //Enlaza el nodo creado al primer elemento (izquierda)
    }
    return nuevo;
}

// Insertar al Final (add para filas)
Nodo* InsertarFinal(Nodo* first, int valor){
    Nodo *nuevo, *aux;
    nuevo = management(valor);

    if (first == NULL){ //Si la fila está vacía simplemente se agrega
        first = nuevo;
    }else{
        aux = first; // Se copia la fila a aux
        while (aux->previo != NULL){  //Se recorre hasta que se encuentra el elementa antes del NULL
            aux = aux->previo;
        }aux->previo = nuevo;  // Se enlaza el nodo creado al auxiliar, por lo tanto, el nodo creado apunta a NULL
    }
    return first;
}

// Insertar en una posición
Nodo* InsertarPosicion(Nodo *list, int index, int value){
    Nodo *nuevo, *aux;
    int i, size = size_l(list);

    if(list == NULL){
        printf("No se puede insertar");
        return list;
    }else{
        aux = list;  //Apunta al primer elemento de la lista (index = 0)
        if ((index<0) || (index>size)){
            printf("No se puede insertar");
        }else{
            if (index == 0){
                return InsertarInicio(list, value);}
            if (index == size){
                return InsertarFinal(list, value);}
            for (i = 0; i < (index-1); i++){
                aux = aux->previo;
            }
            nuevo = management(value);  //Se crea un Nodo con valor val
            nuevo->previo = aux->previo;
            aux->previo = nuevo;
        }
    }return list;
}

//Eliminar al inicio (pop - Top o First)
Nodo* EliminarInicio(Nodo* list){
    Nodo* aux = list;   //Referencia del nodo a borrar
    if (list != NULL){
        list = list->previo;
        free(aux);
    }
    else printf("Lista vacía.");
    return list;
}

//Eliminar al Final (Elemento más proximo a NULL)
Nodo* EliminarFinal(Nodo* list) {
    Nodo *aux = list;  // aux copia la dirección de memoria de list
    Nodo *anterior = NULL;

    if (list == NULL) { // Lista vacía
        printf("Lista vacía, no se puede eliminar\n");
        return NULL;}

    while (aux->previo != NULL) { // Recorre hasta el penúltimo nodo
        anterior = aux;
        aux = aux->previo;
    }anterior->previo = NULL;
    free(aux);

    return list;
}

Nodo* EliminarPosicion(Nodo* list, int index){
    Nodo *aux, *anterior;
    int i, size = size_l(list);

    if(list == NULL){
        printf("No se puede eliminar");
        return list;
    }else{
        aux = list;  //Apunta al primer elemento de la lista (index = 0)
        if ((index<0) || (index>size-1)){
            printf("No se puede insertar");
        }else{
            if (index == 0){
                return EliminarInicio(list);}
            if (index == size-1){
                return EliminarFinal(list);}
            for (i = 0; i < index; i++){  // Se desplaza hasta encontrar el nodo a eliminar
                anterior = aux;
                aux = aux->previo;
            }anterior->previo = aux->previo;
            free(aux);
        }
    }return list;
}

#endif