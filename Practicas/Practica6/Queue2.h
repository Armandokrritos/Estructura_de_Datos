#include <stdio.h>

#define int QueueEntry;

int queue[N];
int front = -1;
int rear = -1;

void insert() {
    int num;
    printf("Ingrese dato:\n");
    scanf("%d", &num);

    if (front == 0 && rear == N-1) {
        printf("Cola llena\n");
    } else {
        if (front == -1 && rear == -1) {
            front = rear = 0;
            queue[rear] = num;
        }
    } else if (rear == N-1 && front != 0) {
        rear = 0;
        queue[rear] = num;
    } else {
        rear++;
        queue[rear] = num;
    }
}