#ifndef _Fila_H_
#define _Fila_H_
#include <stdio.h>
#include <stdlib.h>

// FIFO
/* Aquí eliminamos                Aquí agregamos
    ↓                              ↓
    first → [1] → [2] → [3] → [último] → NULL
*/

typedef struct _NodoF{
    int valor;
    struct _NodoF* previo;
}NodoF;

//Manejo de memoria
NodoF* managementF(int v){
    NodoF* nuevo;
    nuevo = (NodoF*)malloc(sizeof(NodoF));
    nuevo->valor=v;
    nuevo->previo = NULL;
    return nuevo;
}

//Insertar Elementos -> Se inserta al final, es decir, a lado del NULL
NodoF* add(NodoF *first, int v){  
    NodoF *nuevo, *aux;
    nuevo = managementF(v);

    if (first == NULL){
        first = nuevo;
    }else{
        aux = first;
        while (aux->previo != NULL){
            aux = aux->previo;
        }aux->previo = nuevo;  //Nuevo->previo = NULL
    }
    return first;
}

//Eliminar al primer elemento (First)
NodoF* del(NodoF *first){
    NodoF* aux = first;   //Referencia del nodo a borrar
    if (first != NULL){
        first = first->previo;
        free(aux);
    }
    return first;
}

//Mostrar la fila
void show(NodoF* first){
    if (first==NULL){
        printf("Fila vacia\n");
    }else{
        while (first != NULL){
            printf("%d,  ", first->valor);
            first = first->previo;
        }printf("\n");
    }
}

//Tamaño de la cola
int size_c(NodoF* first){
    int l = 0;
    if (first != NULL){
        while (first != NULL){
            l++;
            first = first->previo;
        }
    }
    return l;
}

//Sumatoria
int summatoria(NodoF *first){
    int sumatoria = 0;
    if (first==NULL){
        return 0;
    }while (first != NULL){
        sumatoria += first->valor;
        first = first->previo;
    }return sumatoria;
}

//Multiplex
void MUX(NodoF **filaPrincipal  ,NodoF **filaVIP, NodoF **filaNormal){
    if (*filaPrincipal == NULL) return;  // Si la fila está vacía automáticamente sale del programa para evitar errores.
    
    int numRand = 1+rand()%(100);   // Se generan números aleatorios en un rango de 1 a 100.
    if (numRand%2 == 0){  //Para la fila VIP, si el número aleatorio es múltiplo de dos, se agrega.
        *filaVIP = add(*filaVIP, (*filaPrincipal)->valor);
        *filaPrincipal = del(*filaPrincipal);
    }else{   // Si el número aleatorio generado no es múltiplo de 2 se agrega a la fila normal
        *filaNormal = add(*filaNormal, (*filaPrincipal)->valor);
        *filaPrincipal = del(*filaPrincipal);
    }
}


NodoF* union_filas(NodoF* first1, NodoF* first2){
    NodoF* first3=NULL;
    
    if (first1 != NULL && first2 !=NULL){
        while (first1 != NULL){   //Mientras first1 no esté vacía
            while (first1->valor >= first2->valor){   //Minstras el fisrt1 sea mayor o igual al del first2
                first3 = add(first3, first2->valor);  //Se añade a first3 el valor de first2
                first2 = first2->previo;    //se actualiza first2
            }first3 = add(first3, first1->valor); 
            //Si se llega a este punto, el programa no encontró numeros menores a first1
            first1 = first1->previo; //Se actualiza first1
        }while (first2!=NULL){
            first3 = add(first3, first2->valor);
            first2 = first2->previo;
        }    
    }return first3;
}

NodoF* reversaF(NodoF *first){
    NodoF* copia = NULL;
    while (first != NULL){
        copia = add(copia, first->valor);
        first = first ->previo;
    }
    return copia;
}

int capicuaF(NodoF* top, NodoF* top1){
    int s = 0;

    if (top == NULL){   //si regresa 0 la pila no tiene valores a coparar
        return s;
    }else{
        while (top != NULL){
            if (top->valor == top1->valor){   
                top = del(top);
                top1 = del(top1);
            }else{
                return 1;  //Si regresa 1 significa que no es capicua
            }
        }
    }
    return 2;  //Si regresa 2 significa que terminó exitosamente, por lo tanto es capicua
}


#endif
