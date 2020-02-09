#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "Stack.h"

char intrucciones[] = "Se ejecuta asi:\n\t$./a.out 6523+8*-3+*\n\n";

char *convertidor(const char *);
bool esOperador(char);
bool esNumero(char);

int main(int argc, char const *argv[]) {
    if (argc != 2) 
        printf("%s", intrucciones);
    else
        printf("Resultado: %s\n\n", convertidor(argv[1]));

    return 0;
}

char *convertidor(const char *c) {
    Stack *s = createStack(s);
    int i = 0;
    char aux[] = " ";
    char result[] = "";

    while (c[i] != '\0') {
        if (esNumero(c[i])) {
            aux[0] = c[i];
            strcat(result, aux);
        } else if(c[i] == 40) {
            push(c[i], s);
        } else if(c[i] == 41) {
            while((aux[0] = pop(s)) != '(') {
                strcat(result, aux);
            }
        } else {
            push(c[i], s);
        }
        i++;
    }    

    return *result;
}

bool esNumero(char c) {
    if (c > 47 && c < 58)
        return true;
    
    return false;
}

bool esOperador(char op) {
    return op > 41 && op < 48 || op == 'e';
}