#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Stack.h"

char intrucciones[] = "Se ejecuta asi:\n\t$./a.out 6523+8*-3+*\n\n";

bool checkOperacion(const char *, int *);
bool checar(char);

int main(int argc, char const *argv[])
{
    int posicion;
     if(checkOperacion(argv[1], &posicion)){ 
        if(!stackEmpty){
            printf("La operacion esta correcta");
        }else{
            printf("La operacion esta incorrecta, sobran");
        }
    }else{
         printf("La operacion esta incorrecta en la posicion: %i", posicion);
    }

    return 0;
}

bool checkOperacion(const char *c, int *posicion)
{
    bool flag = true;
    Stack *s = createStack();
    int i = 0;

    while (c[i] != '\0')
    {
        if (checar(c[i])){
            if(c[i] == '(' || c[i] == '{' || c[i] == '['){
                push(c[i], s);
            }else if(c[i] == ')' || c[i] == '}' || c[i] == ']'){
                if(!stackEmpty(s)){
                    switch (c[i])
                    {
                    case ')':
                        if(stackTop(s) == '('){
                            pop(s);
                        }else{
                            flag = false;
                            *posicion = i;
                            break;
                        }
                        break;
                    case ']':
                        if (stackTop(s) == '[')
                        {
                            pop(s);
                        }
                        else
                        {
                            flag = false;
                            *posicion = i;
                            break;
                        }
                        break;
                    case '}':
                        if (stackTop(s) == '{')
                        {
                            pop(s);
                        }
                        else
                        {
                            flag = false;
                            *posicion = i;
                            break;
                        }
                        break;
                    }
                }else{
                    flag = false;
                    *posicion = i;
                    break;
                }
            }
        }
        i++;
    }
    return flag;
}

bool checar(char c)
{
    if (c == '(' || c == '{' || c == '[' || c == ']' || c == '}' || c == ')')
        return true;

    return false;
}
