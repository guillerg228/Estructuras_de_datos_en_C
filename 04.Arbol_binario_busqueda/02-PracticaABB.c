#include "ABB-Estante.h"

void mostrarMenuRecorridos() {
    system("cls");
    printf("\n  --- RECORRIDOS DEL ARBOL ---");
    printf("\n  1. Inorden (Izquierda-Raiz-Derecha)");
    printf("\n  2. Preorden (Raiz-Izquierda-Derecha)");
    printf("\n  3. Postorden (Izquierda-Derecha-Raiz)");
    printf("\n  0. Volver al menu principal");
    printf("\n\n  Seleccione tipo de recorrido: ");
}

void menuRecorridos(Libro *estante) {
    int opcionRecorrido;
    
    if (estante == NULL) {
        printf("\n\tEl estante esta vacio. No hay nada que mostrar.");
        return;
    }
    
    do {
        mostrarMenuRecorridos();
        scanf("%d", &opcionRecorrido);
        getchar();
        
        switch(opcionRecorrido) {
            case 1:
                printf("\n\n\t=== RECORRIDO INORDEN ===");
                printf("\n\t(Libros ordenados de mas antiguo a mas reciente)");
                inorden(estante);
                break;
                
            case 2:
                printf("\n\n\t=== RECORRIDO PREORDEN ===");
                printf("\n\t(Raiz-Izquierda-Derecha)");
                preorden(estante);
                break;
                
            case 3:
                printf("\n\n\t=== RECORRIDO POSTORDEN ===");
                printf("\n\t(Izquierda-Derecha-Raiz)");
                postorden(estante);
                break;
                
            case 0:
                printf("\n\tVolviendo al menu principal...");
                break;
                
            default:
                printf("\n\tOpcion invalida. Intente de nuevo.");
        }
        
        if (opcionRecorrido >= 1 && opcionRecorrido <= 3) {
            printf("\n");
            system("pause");
        }
        
    } while(opcionRecorrido != 0);
}

void cargarLibrosPrueba(Libro **estante) {
    *estante = insertarLibro(*estante, "Don Quijote de la Mancha", "Miguel de Cervantes", 1605);
    *estante = insertarLibro(*estante, "Cien anios de soledad", "Gabriel Garcia Marquez", 1967);
    *estante = insertarLibro(*estante, "El amor en los tiempos del colera", "Gabriel Garcia Marquez", 1985);
    *estante = insertarLibro(*estante, "La sombra del viento", "Carlos Ruiz Zafon", 2001);
    *estante = insertarLibro(*estante, "Rayuela", "Julio Cortazar", 1963);
    *estante = insertarLibro(*estante, "Ficciones", "Jorge Luis Borges", 1944);
    *estante = insertarLibro(*estante, "1984", "George Orwell", 1949);
    *estante = insertarLibro(*estante, "El principito", "Antoine de Saint-Exupery", 1943);
}

int main() {
    Libro *estante = NULL;
    int opcion, anio, anio_ing;
    char titulo[100], autor[100];

    cargarLibrosPrueba(&estante);
    
    printf("\n=============================================");
    printf("\n   SISTEMA DE GESTION DE ESTANTE BIBLIOTECA");
    printf("\n=============================================\n");
    
    do {
        system("cls");
        printf("\n\n========== MENU PRINCIPAL ==========");
        printf("\n1.  Agregar libro");
        printf("\n2.  Mostrar libros (recorridos)");
        printf("\n3.  Buscar libro por anio");
        printf("\n4.  Eliminar libro por anio");
        printf("\n5.  Mostrar altura del arbol");
        printf("\n6.  Contar total de libros");
        printf("\n0.  Salir");
        printf("\n====================================");
        printf("\n\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();
        
        switch(opcion) {
            case 1:
                printf("\n--- AGREGAR NUEVO LIBRO ---");
                printf("\nIngrese el titulo del libro: ");
                fgets(titulo, 100, stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                
                printf("Ingrese el autor: ");
                fgets(autor, 100, stdin);
                autor[strcspn(autor, "\n")] = 0;
                
                printf("Ingrese el anio de publicacion: ");
                scanf("%d", &anio);
                getchar();
                
                estante = insertarLibro(estante, titulo, autor, anio);
                printf("\n\tLibro agregado al estante.\n");
                system("pause");
                break;
                
            case 2:
                menuRecorridos(estante);
                system("cls");
                break;
                
            case 3:
                if (estante == NULL) {
                    printf("\n\tEl estante esta vacio.");
                } else {
                    printf("\n--- BUSCAR LIBRO ---");
                    printf("\nIngrese el anio del libro a buscar: ");
                    scanf("%d", &anio_ing);
                    getchar();
                    
                    Libro *encontrado = buscarLibro(estante, anio_ing);
                    if(encontrado != NULL){
                        printf("\n\t*** LIBRO ENCONTRADO ***");
                        mostrarLibro(encontrado);
                        printf("\n");
                        system("pause");
                    } else {
                        printf("\n\tLibro del anio %d no encontrado.\n", anio_ing);
                        system("pause");
                    }
                }
                break;
                
            case 4:
                if (estante == NULL) {
                    printf("\n\tEl estante esta vacio.\n");
                    system("pause");
                } else {
                    printf("\n--- ELIMINAR LIBRO ---");
                    printf("\nIngrese el anio del libro a eliminar: ");
                    scanf("%d", &anio_ing);
                    getchar();
                    eliminarLibro(&estante, anio_ing);
                    printf("\n");
                    system("pause");
                }
                break;
                
            case 5:
                printf("\n\t Altura del arbol: %d\n", altura(estante));
                system("pause");
                break;
                
            case 6:
                printf("\n\t Total de libros en el estante: %d\n", contarLibros(estante));
                system("pause");
                break;
                
            case 0:
                printf("\n\t Cerrando sistema de biblioteca...\n");
                printf("\t   Hasta pronto!\n\n");
                break;
                
            default:
                printf("\n\t Opcion invalida. Intente de nuevo.");
        }
        
    } while(opcion != 0);
    
    return 0;
}