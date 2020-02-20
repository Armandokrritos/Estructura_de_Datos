#include "Stack.h"
#include<string.h>
#include <stdio.h>
#include <stdbool.h>

void PedirString(Stack *s){
    char String[10];
    scanf("%s", String);
    push(String, s);
}

void estudiantes(char * x [], char * y[], char*string[] ){


}

int main(){
    Stack * Nombre = createStack();
    Stack * Promedio = createStack();
    Stack * Aux = createStack();

    //Primer Alumno
    printf("Ingrese el primer alumno");
    PedirString(Nombre); 
    printf("%s", stackTop(Nombre));

    return 0;
}