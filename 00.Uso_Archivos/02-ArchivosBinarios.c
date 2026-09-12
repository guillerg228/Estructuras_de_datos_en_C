#include <stdio.h>
#include <stdlib.h>

struct Propietario{
    char nombre[30];
    char direccion[30];
    char genero;
    char telefono[10];
};
struct Autotransporte{
    int n_llantas;
    char modelo[10];
    char placas[6];
    struct Propietario propietario;
    char color[10];
};


int main(){
    struct Autotransporte A[2];
    
    FILE *archivo;
    archivo = fopen("ArchivoBinario.bin", "wb");

    for (int i = 0; i < 2; i++){
        printf("\nNombre: "); fgets(A[i].propietario.nombre, sizeof(A[i].propietario.nombre), stdin); fflush(stdin);
        printf("Direccion: "); gets(A[i].propietario.direccion);
        printf("Genero: "); scanf("%c",&A[i].propietario.genero); fflush(stdin);
        printf("Telefono: "); gets(A[i].propietario.telefono);

        printf("Numero de llantas: "); scanf("%d", &A[i].n_llantas); fflush(stdin);
        printf("Modelo: "); gets(A[i].modelo);
        printf("Placas: "); gets(A[i].placas);
        printf("Color: "); gets(A[i].color);
    }
    
    fwrite(A, sizeof(struct Autotransporte),2,archivo);
    fclose(archivo);

    archivo = fopen("ArchivoBinario.bin", "rb");
    fread(A, sizeof(struct Autotransporte), 2, archivo);
    fclose(archivo);

    printf("\n=== Datos leidos desde ArchivoBinario.bin ===\n");
    for (int i = 0; i < 2; i++) {
        printf("\nRegistro %d\n", i + 1);
        printf("Nombre: %s\n", A[i].propietario.nombre);
        printf("Direccion: %s\n", A[i].propietario.direccion);
        printf("Genero: %c\n", A[i].propietario.genero);
        printf("Telefono: %s\n", A[i].propietario.telefono);
        printf("Numero de llantas: %d\n", A[i].n_llantas);
        printf("Modelo: %s\n", A[i].modelo);
        printf("Placas: %s\n", A[i].placas);
        printf("Color: %s\n", A[i].color);
    }
    return 0;
}