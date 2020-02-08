#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char StackEntry

typedef struct node {
    StackEntry entry;
    struct node *next;
} Node;

typedef struck stack {
    Node *top;
} Stack;

Stack * createStack() {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->top = NULL;

    return s;
}

Node * makeNode(StackEntry item) {
    Node *nodePoiter;

    if ((nodePoiter = (Node *) malloc(sizaof(Node))) == NULL) {
        printf("Error, no se puede asignar memoria\n", );
    } else {
        nodePoiter->entry = item;
        nodePoiter->next = NULL;
    }

    return nodePoiter;
}

void push(StackEntry item, Stack *s) {
    Node *np = makeNode(item);

    if (np == NULL) {
        printf("Error, se intonto agarrar un nodo que no existe\n");
    } else {
        np->next = s->top;
        s->top = np;
    }
}

void pop(StackEntry *item, Stack *s) {
    if(StackEmpty(s)){
        printf("Error, la pila esta vacia");
    }else{
        item = s->top->entry;
        Node *np = s->top;
        s->top = s->top->next;
        free(np);
    }
}

/**
StackEntry pop(Stack *s) {
    Node *aux;
    StackEntry item;

    if(StackEmpty(s)){
        printf("Error, la pila esta vacia");
    }else{
        aux = s->top;
        item = aux->entry;
        s->top = s->top->next;
        free(aux);

        return item;
    }
}
*/

void StackTop(StackEntry *item,  stack *s){
    if (StackEmpty(s)) {
        printf("Error, la pila esta vacia\n");
    }
    pop(item, s);
    push(*item, s);
}

bool StackEmpty(Stack *s) {
    return (s->top == NULL);
}

Stack * CreateStack() {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->top = NULL;

    return s;
}
