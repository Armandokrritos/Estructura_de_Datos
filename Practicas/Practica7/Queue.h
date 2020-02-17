#include <stdio.h>
#include <stdlib.h>

typedef int QueueEntry;

typedef struct node {
    QueueEntry data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue() {
    Node *front = NULL;
    Node *rear = NULL;
}


void enqueue(QueueEntry x) {
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next=temp;
    rear=temp;
}

void deque() {
    Node *temp = front;
    if (front == NULL) {
        printf("La cola esta vacia\n");
        return;
    }
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    free(temp);
}

QueueEntry font() {
    if (front == NULL) {
        printf("La cola esta vacia/n");
        return;
    }
    return front->data;
}

void print() {
    Node *temp = front;

    while (temp != NULL) {
        printf("%d", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
