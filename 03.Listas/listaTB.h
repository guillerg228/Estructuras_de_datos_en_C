#ifndef _ListaTransacciones_H_
#define _ListaTransacciones_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _Nodo{
    int numCuenta;
    int monto;
    char tipo;
    char nomCliente[30];
    struct _Nodo* previo;
    struct _Nodo* siguiente;
}Nodo;

Nodo* management(int numCuenta, int monto, char tipo, char nomCliente[]){   //Crea un nodo
    Nodo* nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->numCuenta = numCuenta;
    nuevo->monto = monto;
    nuevo->tipo = tipo;
    strcpy(nuevo->nomCliente, nomCliente);
    
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
//Mostrar lista desde la izquierda
void show_i(Nodo* lista){
    if (lista==NULL){
        printf("Fila vacia\n");
    }else{
        int i = 0;
        while (lista != NULL){  // Recorre hasta antes de llegar al NULL, "a la derecha"
            printf("\n%d) Cuenta: %d, Monto: %d, Tipo: %c, Cliente:  %s",i, lista->numCuenta, lista->monto, lista->tipo, lista->nomCliente);
            lista = lista->siguiente;
            i++;
        }printf("\n");
    }
}

//Mostrar lista desde la derecha
void show_d(Nodo* list) {
    int i = size_l(list) - 1;
    if (list == NULL) {
        printf("Lista vacía\n");
        return;
    }
    while (list->siguiente != NULL) {  // Llegamos hasta el último nodo
        list = list->siguiente;
    }
    while (list != NULL) {  // Recorre hacia la izquierda
        printf("\n%d) Cuenta: %d, Monto: %d, Tipo: %c, Cliente: %s",i, list->numCuenta, list->monto, list->tipo, list->nomCliente);
        list = list->previo;
        i--;
    }
    printf("\n");
}

Nodo* InsertarInicioDE(Nodo* list, int numCuenta, int monto, char tipo, char nomCliente[]){
    Nodo* nuevo = management(numCuenta, monto, tipo, nomCliente);
    
    nuevo->previo = NULL;    // El valor previo al nodo creado es NULL
    nuevo->siguiente = list; // Se enlaza el nodo creado a la lista
    
    if (list != NULL){   // Si la lista no está vacía
        list->previo = nuevo;  // Se enlaza el previo del primer elemento de la lista al nuevo nodo
    }return nuevo;
}

Nodo* InsertarFinalDE(Nodo* list, int numCuenta, int monto, char tipo, char nomCliente[]){
    Nodo *aux, *nuevo = management(numCuenta, monto, tipo, nomCliente);
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


Nodo* InsertarPosicionDE(Nodo *list, int index, int numCuenta, int monto, char tipo, char nomCliente[]){
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
                return InsertarInicioDE(list, numCuenta, monto, tipo, nomCliente);}
            if (index == tamanio){
                return InsertarFinalDE(list, numCuenta, monto, tipo, nomCliente);}
            for (i = 0; i < (index); i++){
                aux = aux->siguiente;
            }nuevo = management(numCuenta, monto, tipo, nomCliente);  //Se crea un Nodo con valor val
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

Nodo* opciones(Nodo* list, char o){
    int nc, mnt, i;
    char t;
    char nom[30];
    switch (o){
    case 'a': // Insertar al inicio
        printf("Ingrese el numero de cuenta: ");
        scanf("%d", &nc);
        printf("Ingrese el monto: ");
        scanf("%d", &mnt);
        printf("Ingrese deposito o retiro(d/r): ");
        scanf(" %c", &t);
        printf("Ingrese el nombre del usuario: ");
        gets(nom); getchar();
        list = InsertarInicioDE(list, nc, mnt, t, nom);
        printf("\n   Se ha insertado el nodo del inicio. \n"); system("pause");
        break;
    case 'b': // Insertar en posición
        printf("Ingrese el numero de cuenta: ");
        scanf("%d", &nc);
        printf("Ingrese el monto: ");
        scanf("%d", &mnt);
        printf("Ingrese deposito o retiro(d/r): ");
        scanf(" %c", &t);
        printf("Ingrese el nombre del usuario: ");
        gets(nom); getchar();
        printf("Ingrese el indice en el que desea insertar: ");
        scanf("%d", &i);
        list = InsertarPosicionDE(list, i, nc, mnt, t, nom);
        printf("\n   Se ha insertado el nodo del indice %d. \n", i); system("pause");
        break;
    case 'c': // Insertar al final
        printf("Ingrese el numero de cuenta: ");
        scanf("%d", &nc);
        printf("Ingrese el monto: ");
        scanf("%d", &mnt);
        printf("Ingrese deposito o retiro(d/r): ");
        scanf(" %c", &t);
        printf("Ingrese el nombre del usuario: ");
        gets(nom); getchar();
        list = InsertarFinalDE(list, nc, mnt, t, nom);
        printf("\n   Se ha insertado el nodo del final. \n"); system("pause");
        break;
    case 'd':  //Eliminar en el inicio
        EliminarInicioDE(list); printf("\n   Se ha eliminado el nodo del inicio. \n");
        system("pause");
        break;
    case 'e':  // Eliminar en una posicion
        printf("Ingrese el indice en el que desea eliminar: ");
        scanf("%d", &i);
        EliminarPosicionDE(list, i);printf("\n   Se ha eliminado el nodo del indice %d. \n", i);
        system("pause");
        break;
    case 'f':  // Eliminar en el final
        EliminarFinalDE(list);printf("\n   Se ha eliminado el nodo del final. \n");
        system("pause");
        break;
    case 'g':  //Mostrar desde la izquierda
        show_i(list); printf("\n");
        system("pause");
        break;
    case 'h':  //Mostrar desde la derecha
        show_d(list); printf("\n");
        system("pause");
        break;
    case 'i':  // Longitud
        printf("\nNumero de nodos: %d\n", size_l(list));
        system("pause");
        break;
    case 'j':
        break;
    default:
        printf("\nOpcion invalida. "); printf("\n");
        system("pause");
        break;
    }getchar(); return list;
}

#endif