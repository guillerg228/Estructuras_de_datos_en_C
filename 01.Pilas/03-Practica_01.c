// Indicar si una expresión está balaceada respecto a simbolos de agrupacion
#include "pila.h"
#include <string.h>

int main(){
    Nodo *top = NULL;
    char c;

    FILE *f;
    f = fopen("Balanceo.bin", "rb");
    if(f == NULL) exit(1);

    int balanceada = 1; // Variable bandera para poder salir del while
    while ((c = fgetc(f)) != EOF){
        
        if (c=='(' ||c=='[' || c=='{') top = push(top, c);
        
        else if (c==')' || c==']' || c=='}'){
            if (top == NULL) { balanceada = 0; printf("\nExpresion no balanceada :(");break; } //Si la pila está vacía y aparece un simbolo de cierre: exprecion balanceada
            if (c == ')' && top->valor == '(') top = pop(top);    //Checamos que los signos de cierre y apertura coincidan para depues eliminar
            else if (c == ']' && top->valor == '[') top = pop(top);
            else if (c == '}' && top->valor == '{') top = pop(top);
            else { balanceada = 0; break; }
        }
    }
    if(balanceada == 1 && top == NULL) printf("\nExpresion balanceada :) "); 
    fclose(f);
    return 0;
}


/*
    Caracter   |   Valor ASCII
---------------------------------
        (      |       40
        )      |       41
        [      |       91
        ]      |       93
        {      |       123
        }      |       125
*/