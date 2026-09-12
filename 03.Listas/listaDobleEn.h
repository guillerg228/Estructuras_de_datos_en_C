#ifndef _ListaDobleEn_H_
#define _ListaDobleEn_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct _Nodo{
    int valor;
    struct _Nodo* previo;
    struct _Nodo* siguiente;
}Nodo;

Nodo* management(int v){   //Crea un nodo
    Nodo* nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor = v;
    nuevo->previo = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

int size_l(Nodo* list){   //Tamaño de la lista
    int l = 0;
    if (list != NULL){
        while (list != NULL){
            l++;
            list = list->siguiente;
        }
    }
    return l;
}

Nodo* InsertarInicioDE(Nodo* list, int valor){
    Nodo* nuevo = management(valor);
    
    nuevo->previo = NULL;    // El valor previo al nodo creado es NULL
    nuevo->siguiente = list; // Se enlaza el nodo creado a la lista
    
    if (list != NULL){   // Si la lista no está vacía
        list->previo = nuevo;  // Se enlaza el previo del primer elemento de la lista al nuevo nodo
    }return nuevo;
}

Nodo* InsertarFinalDE(Nodo* list, int valor){
    Nodo *aux, *nuevo = management(valor);
    nuevo->siguiente = NULL;    // El nodo va a estar antes del NULL

    if (list == NULL){
        nuevo->previo = NULL;  // El previo del nuevo nodo = NULL
        list = nuevo;  // Se asigna el nuevo nodo a la lista
    }else{
        aux = list;
        while (aux->siguiente != NULL){  // Se itera hasta encontrar el Nodo antes del NULL
            aux = aux->siguiente;
        }aux->siguiente =  nuevo;  // Cuando se encuentra el ultimo nodo, se enlaza al nuevo
        nuevo->previo = aux;  // También enlazamos el nodo nuevo a su nodo previo
    }
    return list;
}


Nodo* InsertarPosicionDE(Nodo *list, int index, int value){
    Nodo *nuevo, *aux;
    int i, tamanio = size_l(list);

    if(list == NULL){
        printf("No se puede insertar");
        return list;
    }else{
        aux = list;
        if ((index<0) || (index>tamanio)){
            printf("No se puede insertar");
        }else{
            if (index == 0){
                return InsertarInicioDE(list, value);}
            if (index == tamanio){
                return InsertarFinalDE(list, value);}
            for (i = 0; i < (index); i++){
                aux = aux->siguiente;
            }nuevo = management(value);  //Se crea un Nodo con valor val
            nuevo->previo = aux->previo;
            nuevo->siguiente = aux;
            aux->previo->siguiente=nuevo;
            aux->previo = nuevo;
        }
    }return list;
}


Nodo* EliminarInicioDE(Nodo* list){
    Nodo* aux = list;   //Copia la referencia de la lista a aux
    if (list != NULL){  
        list = list->siguiente; //Si la lista no está vacía fijamos el principio de la lista en el segundo elemento
        if (list != NULL){    // Si el segundo elemento es diferente de NULL lo enlazamos 
            list->previo = NULL;
        }
    }free(aux);
    return list;
}

//Eliminar al Final (Elemento más proximo a NULL)
Nodo* EliminarFinalDE(Nodo* list) {
    Nodo *aux = list;  // aux copia la dirección de memoria de list

    if (list == NULL){
        printf("Lista vacía");
        return list;
    }else if (list->siguiente == NULL){  // Si la lista solo tiene un elemento
        free(list);
        return NULL;
    }else{
        while (aux->siguiente != NULL){  // Itera hasta encontrar el elemento antes del NULL
            aux = aux->siguiente;
        }aux->previo->siguiente = NULL;
        free(aux);
    return list;
    }
}

Nodo* EliminarPosicionDE(Nodo* list, int index){
    Nodo* aux = list;
    int i, tam = size_l(list);

    if (index<0 || index >= tam){
        printf("Indice invalido");
    }else{
        if (index == 0){
            return EliminarInicioDE(list);
        }else if (index == tam-1){
            return EliminarFinalDE(list);
        }else{
            for (i = 0; i < index; i++){  //itera hasta que aux = nodo en index
                aux = aux->siguiente;
            }aux->siguiente->previo = aux->previo;
            aux->previo->siguiente = aux->siguiente;
            free(aux);
        }
    }return list;
}



#endif