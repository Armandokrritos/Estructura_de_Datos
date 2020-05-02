#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    int nivel; 
    int info;
    struct nodo * izq; 
    struct nodo * der;
}Nodo;
 
Nodo * raiz = NULL;

void Insertar(int);
void Eliminar(int);
void Padre(int);
void Hermano(int);
void Hijo_Izq(int);
void Hijo_Der(int);

void Insertar(int dato){
    Nodo* nuevo;
    int nivel = 0;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = dato;
    nuevo->der = NULL; 
    nuevo->izq = NULL;
    if(raiz == NULL){
        nuevo->nivel = 1;
        raiz = nuevo;
    }else{
        Nodo * anterior, * head;
        anterior = NULL;
        head = raiz;
        while (head != NULL)
        {
            nivel++;
            anterior = head;
            if(dato <= head->info){
                head = head->izq;
            }else{
                head = head->der;
            }
        }
        nuevo ->nivel = nivel;
        if(dato <= anterior->info){
            anterior->izq = nuevo;
        }else{
            anterior->der = nuevo;
        }
    }
}

void Eliminar(int dato){
    Nodo * anterior, * head;
    anterior = NULL;
    head = raiz;
    int i = 0;
    while (head != NULL)
    {
        if(head->info == dato){
            i = head->nivel;
            break;
        }
        anterior = head;
        if(dato < head->info){
            head = head->izq;
        }else{
            head = head->der;
        }
    }
    if(i != 0){
        if(i == 1){
            printf("No se puede eliminar por que el elemento es la raiz\n");
        }else{
            if(dato < anterior->info){
                anterior = head->izq;
            }else{
                anterior = head->der;
            }
            free(head);
        }
    }else{
        printf("No se encontro el elemento\n");
    }
}

void Padre(int dato){
    Nodo * anterior, * head;
    anterior = NULL;
    head = raiz;
    int i = 0;
    while (head != NULL)
    {
        if(head->info == dato){
            i = head->nivel;
            break;
        }
        anterior = head;
        if(dato < head->info){
            head = head->izq;
        }else{
            head = head->der;
        }
    }
    if (i == 0){
        printf("No se encuentra el elemento\n");
    }else{
        if(anterior != NULL){
            printf("El elemento padre es: %i\n", anterior->info);
        }else{
            printf("El elemento es la raiz\n");
        }
    }
}

void Hermano(int dato){
    Nodo * anterior, * head;
    anterior = NULL;
    head = raiz;
    int i = 0;
    while (head != NULL)
    {
        if(head->info == dato){
            i = head->nivel;
            break;
        }
        anterior = head;
        if(dato < head->info){
            head = head->izq;
        }else{
            head = head->der;
        }
    }
    if (i == 0){
        printf("No se encuentra el elemento\m");
    }else{
        if(anterior != NULL){
            if(dato < anterior->info){
                if(anterior->der == NULL){
                    printf("El elemento no tiene ningun hermano\n");
                }else{
                    printf("Su hermano es: %i\n", anterior->der->info);
                }
            }else{
                if(anterior->izq == NULL){
                    printf("El elemento no tiene ningun hermano\n");
                }else{
                    printf("Su hermano es: %i\n", anterior->izq->info);
                }
            }
        }else{
            printf("El elemento es la raiz\n");
        }
    }
}

void Hijo_Izq(int dato){
    Nodo * head;
    head = raiz;
    int i = 0;
    while (head != NULL)
    {
        if(head->info == dato){
            i = head->nivel;
            break;
        }
        if(dato < head->info){
            head = head->izq;
        }else{
            head = head->der;
        }
    }
    if(i == 0){
        printf("No se encuentra el elemento\n");
    }else{
        if(head->izq == NULL){
            printf("No tiene hijo del lado izquierdo\n");
        }else{
            printf("Hijo Izquierdo: %i\n", head->izq->info);
        }
    }
}

void Hijo_Der(int dato){
    Nodo * head;
    head = raiz;
    int i = 0;
    while (head != NULL)
    {
        if(head->info == dato){
            i = head->nivel;
            break;
        }
        if(dato < head->info){
            head = head->izq;
        }else{
            head = head->der;
        }
    }
    if(i == 0){
        printf("No se encuentra el elemento\n");
    }else{
        if(head->der == NULL){
            printf("No tiene hijo del lado derecho\n");
        }else{
            printf("Hijo Derecho: %i\n", head->der->info);
        }
    }
}