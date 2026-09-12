#include "ABB.h"

int main() {
    Nodo *arbol = NULL;
    int opcion, valor;
    
    printf("\n========================================");
    printf("\n   PRUEBA DE ARBOL BINARIO DE BUSQUEDA");
    printf("\n========================================\n");
    
    do {
        printf("\n\n--- MENU ---");
        printf("\n1. Insertar valor");
        printf("\n2. Mostrar arbol (Preorden)");
        printf("\n3. Borrar valor");
        printf("\n4. Calcular altura");
        printf("\n5. Insertar valores de prueba");
        printf("\n0. Salir");
        printf("\n\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                printf("\nIngrese el valor a insertar: ");
                scanf("%d", &valor);
                arbol = insertar(arbol, valor);
                printf("\n\tValor %d insertado correctamente.", valor);
                break;
                
            case 2:
                if (arbol == NULL) {
                    printf("\n\tEl arbol esta vacio.");
                } else {
                    printf("\n\tRecorrido Preorden:");
                    preorder(arbol);
                }
                break;
                
            case 3:
                if (arbol == NULL) {
                    printf("\n\tEl arbol esta vacio.");
                } else {
                    printf("\nIngrese el valor a borrar: ");
                    scanf("%d", &valor);
                    borrarNodo(&arbol, valor);
                    printf("\n\tOperacion de borrado ejecutada.");
                }
                break;
                
            case 4:
                printf("\n\tAltura del arbol: %d", altura(arbol));
                break;
                
            case 5:
                printf("\n\tInsertando valores de prueba: 50, 30, 70, 20, 40, 60, 80");
                arbol = insertar(arbol, 50);
                arbol = insertar(arbol, 30);
                arbol = insertar(arbol, 70);
                arbol = insertar(arbol, 20);
                arbol = insertar(arbol, 40);
                arbol = insertar(arbol, 60);
                arbol = insertar(arbol, 80);
                printf("\n\tValores insertados correctamente.");
                printf("\n\tRecorrido Preorden:");
                preorder(arbol);
                break;
                
            case 0:
                printf("\n\tSaliendo del programa...\n\n");
                break;
                
            default:
                printf("\n\tOpcion invalida. Intente de nuevo.");
        }
        
    } while(opcion != 0);
    
    return 0;
}