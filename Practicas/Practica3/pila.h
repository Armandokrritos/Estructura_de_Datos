#define MAXSTACK 10
#include<stdio.h>
#include<stdbool.h>

typedef char StackEntry;

typedef struct stack{
    int top;
    StackEntry entry[MAXSTACK];
}stack;

int StackEmpty(stack *);
int StackFull(stack *);
void CreateStack(stack *);
void StackTop(StackEntry *,  stack *);
void Push(StackEntry, stack *);
void Pop(StackEntry *, stack *);
void printStack(stack *);

int StackEmpty(stack *s){
    return s-> top <= 0;
}

int StackFull(stack *s){
    return s->top>=MAXSTACK;
}

void CreateStack(stack *s){
    s->top = 0;
}

void StackTop(StackEntry *item,  stack *s){
    Pop(item, s);
    Push(*item, s);
}

void Push(StackEntry item, stack *s){
    if(StackFull(s)){
        printf("Error, la pila esta llena");
    }else{
        s->entry[s->top++] = item;
    }
}

void Pop(StackEntry *item, stack *s){
    if(StackEmpty(s)){
        printf("Error, la pila esta vacia");
    }else{
        *item = s->entry[--s->top];
    }
}
