#include "listaTB.h" // Simulacion de transacciones bancarias

int main(){
    Nodo* list =NULL;

    list = InsertarInicioDE(list, 55555, 1200, 'd', "Guillermo Guerrero");
    list = InsertarInicioDE(list, 77777, 1800, 'r', "Jaime Mauzan");
    list = InsertarInicioDE(list, 99999, 2100, 'd', "Juan Perez");
    list = InsertarInicioDE(list, 66666, 8002, 'd', "Pedro Hernandez");
    char opcion;
    do{
        system("cls");
        printf("\n ============================== Menu Transacciones Bancarias ============================== ");
        printf("\n\n    -> Insertar:\t    -> Eliminar:\t    -> Mostrar desde:\t    -> Longitud: i)\n");
        printf("\ta)Inicio\t\td)Inicio\t\tg)Inicio\t    -> Salir: j)\n\tb)Posicion\t\te)Posicion\t\th)Final\n\tc)Final\t\t\tf)Final");
        printf("\n\n Ingresa la opcion deseada: ");
        scanf("%c", &opcion);
        opciones(list, opcion);
    } while (opcion != 'j');
    
}