/*  Algoritmo para uso de archivos de texto
    1. Crearlo / Abrirlo
        1.2 Comprobacion
    2. Escribir /Leer
    3. Cerrar
*/

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

struct Autotransporte A;
/*
//Escritura de archivos
    FILE *archivo1;
    char texto[100] = "Esto esta en el archivo";   //Variable que almacena texto
    archivo1 = fopen("ejemplo1.txt", "w");    //Se abre el archivo
    
    if(archivo1 == NULL) exit(1);  //Se comprueba que el archivo exista
    fprintf(archivo1, "%s", texto);   //Se escribe dentro del archivo
    fclose(archivo1);    //Se cierra el archivo


//Lectura de archivos
    char buffer[100];
    archivo1 = fopen("ejemplo1.txt", "r");

    if(archivo1 == NULL) exit(1);
    //fscanf(archivo1, "%s", buffer);
    fgets(buffer,100,archivo1);
    fclose(archivo1);
    printf("%s", buffer);
*/

    printf("\nNombre: ");
    fgets(A.propietario.nombre, sizeof(A.propietario.nombre), stdin); 
    fflush(stdin);
    //scanf("%30s",A.propietario.nombre);
    //gets(A.propietario.nombre);
    printf("Direccion: ");
    gets(A.propietario.direccion);
    printf("Genero: ");
    scanf("%c",&A.propietario.genero);
    fflush(stdin);
    printf("Telefono: ");
    gets(A.propietario.telefono);
    fflush(stdin);

    printf("Numero de llantas: ");
    scanf("%d", &A.n_llantas);
    fflush(stdin);
    printf("Modelo: ");
    gets(A.modelo);
    printf("Placas: ");
    gets(A.placas);
    printf("Color: ");
    gets(A.color);

    FILE *archivoDatos;
    archivoDatos = fopen("datos.bin", "w");
    if(archivoDatos == NULL) exit(1);

    fprintf(archivoDatos, "\n%s\n", A.propietario.nombre);
    fprintf(archivoDatos, "%s\n", A.propietario.direccion);
    fprintf(archivoDatos, "%c\n", A.propietario.genero);
    fprintf(archivoDatos, "%s\n", A.propietario.telefono);
    fprintf(archivoDatos, "%d\n", A.n_llantas);
    fprintf(archivoDatos, "%s\n", A.modelo);
    fprintf(archivoDatos, "%s\n", A.placas);
    fprintf(archivoDatos, "%s\n", A.color);
    fclose(archivoDatos);


    archivoDatos = fopen("datos.txt","r");

    fscanf(archivoDatos, "%s \n %s \n %s \n %s \n %d \n %s \n %s \n %s ",
    &A.propietario.nombre,&A.propietario.direccion,&A.propietario.genero,&A.propietario.telefono,
    &A.n_llantas, &A.modelo, &A.placas,A.color);
    
    printf("%s \n %s \n %s \n %s \n %d \n %s \n %s \n %s ",
    A.propietario.nombre,A.propietario.direccion, A.propietario.genero,A.propietario.telefono,
    A.n_llantas,A.modelo,A.placas,A.color);
    fclose(archivoDatos);

    return 0;
}