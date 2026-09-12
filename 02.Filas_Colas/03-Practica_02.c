
#include <stdio.h>
#include <time.h>
#include "fila.h"

int main(){

    srand(time(NULL));

    Nodo* firstPrincipal = NULL;
    Nodo* firstVip = NULL;
    Nodo* firstNormal = NULL;
    FILE *archivoDatos;

//Lectura del archivo.
    int nLeido;
    archivoDatos = fopen("fila.bin", "rb");
    if(archivoDatos == NULL) exit(1);
    
    int basura; fread(&basura, sizeof(int), 1, archivoDatos); // lee el primer entero y lo guarda en basura

    while (fread(&nLeido, sizeof(int), 1, archivoDatos) == 1){
        firstPrincipal = add(firstPrincipal, nLeido);
    }fclose(archivoDatos);


    while (firstPrincipal!=NULL){  // Mientras la fila principal no esté vacía.
        MUX(&firstPrincipal, &firstVip, &firstNormal);   // Se invoca a la función MUX para determinar en que fila se agrega el número.
    }
    
    printf("\nFila VIP: ");
    show(firstVip);
    printf("\nFila Normal: ");
    show(firstNormal);
    printf("\n");

    printf("-----> Tama%co de la fila VIP: %d", 164, size_c(firstVip));
    printf("\n |---> Sumatoria fila VIP: %d", summatoria(firstVip));
    printf("\n\n-----> Tama%co de la fila normal: %d", 164, size_c(firstNormal));
    printf("\n |---> Sumatoria fila normal: %d", summatoria(firstNormal));
}
