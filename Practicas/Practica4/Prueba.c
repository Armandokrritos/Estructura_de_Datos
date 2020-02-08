#include "Stack.h"
#include <stdio.h>

#define StackEntry char

bool ejecutar(int, Stack *);
int menu();

int main() {
    bool flag = true;
    Stack s;
    createStack(&s);

    do {
        flag = ejecutar(menu(), &s);
    } while(flag);

}

int menu() {
    int opc;

    printf("\n\nMenu\n");
    printf("1. Ingresar nuevo Dato\n");
    printf("2. Borrar Elemento\n");
    printf("3. Revisar si esta Vacia\n");
    printf("4. Ver ultimo Elemento\n");
    printf("5. Imprimir Stack\n");
    printf("0. Salir\n");
    printf("\nEntrada: ");
    scanf("%i", &opc);

    return opc;
}

bool ejecutar(int opc, Stack *s) {
    char c;
    printf("\n\n");

    switch (opc){
        case 0:
            return false; 
        case 1:
            printf("\tIngrese dato: ");
            scanf("%c", &c);
            push(c, s);
            printf("Se ingreso el dato correctamente en la pila\n");
            break;

        case 2:
            pop(&c, s);
            printf("Se elimino %c de la pila.", c);
            break;

        case 3:
            if (stackEmpty(s))
                printf("La pila esta vacia\n");
            else
                printf("La pila esta NO esta vacia\n");
        
            break;

        case 4:
            c = ' ';
            stackTop(&c, s);

            if(c != ' ') 
                printf("Este es el ultimo elemento del stack: %c", c);
            
            break;

        case 5:
            printStack(s);
            break;

        default:
            printf("Opcion no valida, trata de nuevo\n");
    }

    return true;
}
