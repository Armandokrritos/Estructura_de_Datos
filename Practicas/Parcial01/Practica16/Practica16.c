#include "Lista.h"
#include <stdbool.h>
#include<time.h>

int main(){
    Node * vuelos;
    bool flag = true;
    int aux;
    Ingresar(vuelos);
    while(flag){
        printf("Menú\n");
        printf("Ingresar Vuelos...1\n");
        printf("Checar Vuelos...2\n");
        printf("Imprimir itinerario...3\n");
        printf("Salir...0\n");
        scanf("&i", &aux);
        switch (aux){
            case 1:
                Ingresar(vuelos);
                break;
            case 2: 
                Check(vuelos);
                break;
            case 3: 
                displayALL(vuelos);
                break;
            case 0:
                flag = false;
                break;
            default:
                flag = false;
                break;
        }
    }

    return 0;
}

void Ingresar(Node * temp){
    bool flag = true;
    char Destino[255];
    char Compañia[255];
    int pasajeros;
    tiempo salida;
    printf("Ingrese vuelos\n");
    while (flag)
    {
        printf("Destino: ");
        scanf("%s", Destino);
        printf("Compañia: ");
        scanf("%s", Compañia);
        printf("Numero de Pasajeros: ");
        scanf("%i", pasajeros);
        printf("Hora de salida(HH:MM:SS):");
        scanf("%i", salida.tm_hour);
        scanf("%i", salida.tm_min);
        scanf("%i", salida.tm_sec);
        insert(temp, Destino, Compañia, pasajeros, salida);
        printf("Vuelo Ingresado Correctamente, si desea regresar al menu presione *\n");
        if(scanf("%c") == '*')
            flag = false;
    }
}

void Check(Node * vuelos){
    
}