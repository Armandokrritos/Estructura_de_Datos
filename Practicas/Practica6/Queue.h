#include <stdio.h>
#include <stdbool.h>

#define N 10

typedef int QueueEntry;

typedef struct queue {
    QueueEntry queue[N];
    int rear = 0;//-1
    int front = 0;
    int size = 0; //r-f+1
} Queue;

void enqueue(QueueEntry queue) {
    int t;

    if (reat < N) {
        printf("Ingrese valor: \n");
        scanf("%d", &t);
        queue[rear] = t;
        rear++;
    } else {
        printf("Cola llena\n")
    }
}

QueueEntry delete(QueueEntry queue) {
    int i = queue[front];
    printf("%d se elimina", queue[front]);
    queue[front] = 0;
    front++;
    return i;
}

void display(QueueEntry queue) {
    int i;
    for (int i = 0; i < rear; i++) {
        printf("\n%d", queue[i]);
    }
    
}

bool emptyQueue(QueueEntry queue) {

}

bool fullQueue(QueueEntry queue) {
    if (q.rear < N) {

    }
}





