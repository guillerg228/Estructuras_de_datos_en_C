#include "pila.h"
#include "fila.h"

NodoF* union_pilas(NodoP* top1, NodoP* top2, NodoF* first);

int main(){

    NodoP* pila1 = NULL;
    NodoP* pila2 = NULL;
    NodoF* fila = NULL;

    FILE *datos1, *datos2, *filOrd;

    datos1 = fopen("Pila1.txt", "r");
    if(datos1 == NULL) exit(1);
    datos2 = fopen("Pila2.txt", "r");
    if(datos2 == NULL) exit(1);

    int aux=0;
    while (fscanf(datos1, "%d", &aux) == 1){
        pila1 = push(pila1, aux);
    }showP(pila1);
    while (fscanf(datos2, "%d", &aux) == 1){
        pila2 = push(pila2, aux);
    }showP(pila2);

    fclose(datos1);
    fclose(datos2);

    fila = union_pilas(pila1, pila2, fila);
    show(fila);

    filOrd = fopen("ResultadoExamen.txt", "w");
    while (fila != NULL){
        fprintf(filOrd, "\n%d", fila->valor);
        fila = fila->previo;
    }
    fclose(filOrd);
    
    

}

NodoF* union_pilas(NodoP* top1, NodoP* top2, NodoF* first) { //Fuincion para juntar pilas
    top1 = reversa(top1);  // Para hacer que ambas pilas se encuentren ordenadas ascendentemente

    while (top1 != NULL && top2 != NULL) {  //mientras las pilas no estén vacías
        if (top1->valor >= top2->valor) {
            first = add(first, top2->valor);
            top2 = top2->previo;
        } else {
            first = add(first, top1->valor);
            top1 = top1->previo;  //actualiza el elemento en el que se encuentra
        }
    }

    while (top1 != NULL) { // Si aún quedan elementos en la primera pila
        first = add(first, top1->valor);
        top1 = top1->previo;
    }
    while (top2 != NULL) { // Si aún quedan elementos en la segunda pila
        first = add(first, top2->valor);
        top2 = top2->previo;
    }

    return first;
}