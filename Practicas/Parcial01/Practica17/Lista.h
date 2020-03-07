#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct tm
{
    int tm_sec;  /* seconds after the minute [0-60] */
    int tm_min;  /* minutes after the hour [0-59] */
    int tm_hour; /* hours since midnight [0-23] */
} tiempo;

typedef struct node
{
    int id;
    char destino[255];
    char compañia[255];
    int pasajeros;
    tiempo salida;
    struct node *next;
    struct node *prev;
} Node;

void insert(Node *, char destino[], char compañia[], int pasajeros, tiempo salida);
void del(Node *, int);
Node *findById(Node *, int);
void findByHour(Node *, int, int[]);
void displayALL(Node *);
void displayALLBackwards(Node *);
void display(Node *);

void insert(Node *current, char destino[], char compañia[], int pasajeros, tiempo salida)
{
    int ids = 0;
    while (current->next != NULL)
    {
        current = current->next;
        ids = current->id;
    }
    current->next = (Node *)malloc(sizeof(Node));
    (current->next)->prev = current;
    current = current->next;
    current->pasajeros = pasajeros;
    current->salida = salida;
    strcpy(current->compañia, compañia);
    strcpy(current->destino, destino);
    current->id = ids++;
    current->next = NULL;
}

void del(Node *current, int ids)
{
    while (current->next != NULL && (current->next)->id != ids)
    {
        current = current->next;
    }
    if (current->next == NULL)
    {
        printf("El elemento %d no esta en la lista \n", ids);
        return;
    }
    Node *tmp = current->next;
    if (tmp->next == NULL)
    {
        current->next = NULL;
    }
    else
    {
        current->next = tmp->next;
        (current->next)->prev = tmp->prev;
    }
    free(tmp);
    return;
}

Node *findById(Node *current, int ids)
{
    current = current->next;
    while (current != NULL)
    {
        if (current->id == ids)
            return current;
        current = current->next;
    }
    return NULL;
}

void findByHour(Node *current, tiempo salidas, int ids[])
{
    int aux=0;
    current = current->next;
    while (current != NULL)
    {
        if (current->salida.tm_hour == salidas.tm_hour && current->salida.tm_min == salidas.tm_min){
            ids[aux] = current->id;
            aux++;
        }
        current = current->next;
    }
}

void displayALL(Node *current)
{
    current = current->next;
    while (current != NULL)
    {
        printf("ID: %d\n", current->id);
        printf("Compañia: %s\n", current->compañia);
        printf("Destino: %s\n", current->destino);
        printf("Numero de Pasajeros: %d\n", current->pasajeros);
        printf("Hora de salida: %d:%d:%d\n", current->salida.tm_hour, current->salida.tm_min, current->salida.tm_sec);
        current = current->next;
    }
}

void displayALLBackwards(Node *current)
{
    Node *head = current;
    current = current->next;
    while (current != NULL)
    {
        current = current->next;
    }
    while (current != head)
    {
        printf("ID: %d\n", current->id);
        printf("Compañia: %s\n", current->compañia);
        printf("Destino: %s\n", current->destino);
        printf("Numero de Pasajeros: %d\n", current->pasajeros);
        printf("Hora de salida: %d:%d:%d\n", current->salida.tm_hour, current->salida.tm_min, current->salida.tm_sec);
        current = current->prev;
    }
}

void display(Node *current)
{
    current = current->next;
    printf("ID: %d\n", current->id);
    printf("Compañia: %s\n", current->compañia);
    printf("Destino: %s\n", current->destino);
    printf("Numero de Pasajeros: %d\n", current->pasajeros);
    printf("Hora de salida: %d:%d:%d\n", current->salida.tm_hour, current->salida.tm_min, current->salida.tm_sec);
}
