
#include <stdio.h>
#include <stdlib.h>

typedef struct {
int front; 
int rear;  
int capacity;  
int *array;
} Queue;

Queue *createQueue(int capacity) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->capacity = capacity;
    q->array = (int *)malloc(q->capacity * sizeof(int));
 return q;
}


void enqueue(Queue *q, int data) {
    if (q->rear == q->capacity - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->array[q->rear] = data;
}

int dequeue(Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    int data = q->array[q->front];
    q->front++;
    return data;
}

int peek(Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->array[q->front];

}

void freeQueue(Queue *q) {
    free(q->array);
    free(q);
}   


int main() {
    Queue *q = createQueue(5);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    freeQueue(q);
    return 0;
}
