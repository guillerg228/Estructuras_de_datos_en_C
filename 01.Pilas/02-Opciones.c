#include "pila.h"

void casos(Nodo** top1, Nodo** top2,int r);

int main(){
    Nodo *top1=NULL, *top2=NULL;

    int r = 0;
    do{
        system("cls");
        printf("\n*** Menu de opciones ***");
        printf("\n  1.- Ingresar valor.");
        printf("\n  2.- Crear copia.");
        printf("\n  3.- Invertir.");
        printf("\n  4.- Salir.");

        printf("\n\n-> Ingrese la opcion desada a realizar en la pila: ");
        scanf("%d", &r);

        casos(&top1, &top2, r);
    } while (r != 4);
}

void casos(Nodo** top1, Nodo** top2,int r){
    int entrada = 0;
    switch (r){
    case 1:   //Entrada a pila
        printf("Ingrese el valor a agregar: ");
        scanf("%d", &entrada);
        *top1 = push(*top1, entrada);
        printf("  ---> Pila actual: ");
        show(*top1);
        break;
    case 2:   //Crea una copia de top1 en top2
        *top2 = *top1;
        printf("   *** Copia creada en top2 ***\n -> Top2: ");
        show(*top2);
        break;
    case 3:   //Invierta top1
        *top1 = reversa(*top1);
        printf("   ***Lista invertida, top1: ");
        show(*top1);
        break;
    case 4: //Salir
        break;
    default:
        printf("Opción Incorrecta.");
        break;
    }printf("\n\n");system("pause");
}
