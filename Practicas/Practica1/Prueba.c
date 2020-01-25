#include "Fraccion.h"
#include <stdio.h>
#include <stdbool.h>

int menu();

int main(int argc, char const *argv[]) {

    while (true) {
        if (menu() == 0)
            break;
    }

    return 0;
}

int menu() {
    int opc;
    fraccion a, b;
    printf("Escoge operacion\n");
    printf("0) Salir\n");
    printf("1) Obtener numerador\n");
    printf("2) Obtener denominador\n");
    printf("3) Obtener suma\n");
    printf("4) Obtener resta\n");
    printf("5) Obtener multiplicacion\n");
    printf("6) Obtener division\n");
    printf("7) Simplificar\n");

    scanf("%d", &opc);

    switch (opc) {
        case 1:
            printf("Ingrasa el numerador: ");
            scanf("%d", &a.numerador);
            printf("Ingrasa el denominador: ");
            scanf("%d", &a.denominador);
            numerador(a);
            break;
        case 2:
            printf("Ingrasa el numerador: ");
            scanf("%d", &a.numerador);
            printf("Ingrasa el denominador: ");
            scanf("%d", &a.denominador);
            denominador(a);
            break;
        case 3:
            printf("Ingrasa el numerador1: ");
            scanf("%d", &a.numerador);
            printf("Ingrasa el denominador1: ");
            scanf("%d", &a.denominador);
            printf("Ingrasa el numerador2: ");
            scanf("%d", &b.numerador);
            printf("Ingrasa el denominador2: ");
            scanf("%d", &b.denominador);
            imprimeFraccion(sumar
                (a, b));
            break;
        case 4:
            printf("Ingrasa el numerador1: ");
            scanf("%d", &a.numerador);
            printf("Ingrasa el denominador1: ");
            scanf("%d", &a.denominador);
            printf("Ingrasa el numerador2: ");
            scanf("%d", &b.numerador);
            printf("Ingrasa el denominador2: ");
            scanf("%d", &b.denominador);
            imprimeFraccion(restar(a, b));
            break;
        case 5:
            printf("Ingrasa el numerador1: ");
            scanf("%d", &a.numerador);
            printf("Ingrasa el denominador1: ");
            scanf("%d", &a.denominador);
            printf("Ingrasa el numerador2: ");
            scanf("%d", &b.numerador);
            printf("Ingrasa el denominador2: ");
            scanf("%d", &b.denominador);
            imprimeFraccion(multiplicar(a, b));
            break;
        case 6:
            printf("Ingrasa el numerador1: ");
            scanf("%d", &a.numerador);
            printf("Ingrasa el denominador1: ");
            scanf("%d", &a.denominador);
            printf("Ingrasa el numerador2: ");
            scanf("%d", &b.numerador);
            printf("Ingrasa el denominador2: ");
            scanf("%d", &b.denominador);
            imprimeFraccion(dividir(a, b));
            break;
        case 7:
            printf("Ingrasa el numerador1: ");
            scanf("%d", &a.numerador);
            printf("Ingrasa el denominador1: ");
            scanf("%d", &a.denominador);
            imprimeFraccion(simplificar(a));
            break;
        default:
            return 0;

    }
    return 1;
}
