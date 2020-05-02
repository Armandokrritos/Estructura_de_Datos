#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Binario.h"

void main(){
    bool flag = true;
    int opc, dato;

    do{
        printf("Menu\n");
        printf("1. Ingresar Datos\n");
        printf("2. Eliminar Dato\n");
        printf("3. Padre de Dato\n");
        printf("4. Hermano de Dato\n");
        printf("5. Hijo Izquierdo\n");
        printf("6. Hijo Derecho\n");
        printf("0. Salir\n");
        scanf(" %i", &opc);
        if(opc != 0){
            printf("Ingrese dato\n");
            scanf(" %i", &dato);
        }
        switch (opc)
        {
        case 1:
            Insertar(dato);
            break;
        case 2:
            Eliminar(dato);
            break;

        case 3:
            Padre(dato);
            break;

        case 4:
            Hermano(dato);
            break;

        case 5:
            Hijo_Izq(dato);
            break;

        case 6:
            Hijo_Der(dato);
            break;

        case 0:
            flag = false;
            break;
        
        default:
            flag=false;
            break;
        }

    }while(flag);
}