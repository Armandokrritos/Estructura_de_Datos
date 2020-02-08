#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char StackEntry;

typedef struct node_t {
    StackEntry entry;
    struct node *next;
} Node;

typedef struct stack_t {
    Node *top;
} Stack;

void createNode(StackEntry, Node*);
void createStack(Stack *);
bool stackEmpty(Stack *);
void push(StackEntry, Stack *);
void pop(StackEntry *, Stack *); 
void stackTop(StackEntry *,  Stack *);
void printStack(Stack *s); 

void createNode(StackEntry item, Node *np) {
    np = (Node *) malloc(sizeof(Node));

    if (np == NULL) {
        printf("Error, no se puede asignar memoria\n");
    } else {
        np->entry = item;
        np->next = NULL;
    }
}

void createStack(Stack *s) {
    s = (Stack *) malloc(sizeof(Stack));
    s->top = NULL;
}

bool stackEmpty(Stack *s) {
    return (s->top == NULL);
}

void push(StackEntry item, Stack *s) {
    Node *np; 
    createNode(item, np);

    if (np == NULL) {
        printf("Error, se intonto agarrar un nodo que no existe\n");
    } else {
        np->next = s->top;
        s->top = np;
    }
}

void pop(StackEntry *item, Stack *s) {
    if(stackEmpty(s)) {
        printf("Error, la pila esta vacia");
    } else {
        *item = s->top->entry;
        Node *np = s->top;
        s->top = s->top->next;
        free(np);
    }
}

void stackTop(StackEntry *item,  Stack *s) {
    if (stackEmpty(s)) {
        printf("Error, la pila esta vacia\n");
    } else {
        *item = s->top->entry;
    }
}

void printStack(Stack *s) {
    if (!stackEmpty(s)) {
        Node *tmp = s->top; 

        while(tmp->next != NULL) {
            printf("[%c]->", s->top->entry);
            tmp = tmp->next;
        }
        printf("NULL\n");
    } else {
        printf("[ ]\n");
    }
    
}
   


