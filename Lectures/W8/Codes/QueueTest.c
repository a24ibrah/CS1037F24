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
    // Test case 1: Basic functionality
    Queue *q = createQueue(5);
    printf("Enqueue elements 10, 20, 30, 40, 50\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printf("Dequeue elements:\n");
    printf("%d\n", dequeue(q));  // Expected: 10
    printf("%d\n", dequeue(q));  // Expected: 20
    printf("%d\n", dequeue(q));  // Expected: 30
    printf("%d\n", dequeue(q));  // Expected: 40
    printf("%d\n", dequeue(q));  // Expected: 50

    // Test case 2: Edge case - dequeue from an empty queue
    printf("Attempt to dequeue from empty queue:\n");
    printf("%d\n", dequeue(q));  // Expected: Queue Underflow

    // Test case 3: Peek on an empty queue
    printf("Attempt to peek on empty queue:\n");
    printf("%d\n", peek(q));     // Expected: Queue Underflow

    // Test case 4: Fill queue to its capacity and try enqueue on full queue
    printf("Enqueue elements to fill queue:\n");
    enqueue(q, 100);
    enqueue(q, 200);
    enqueue(q, 300);
    enqueue(q, 400);
    enqueue(q, 500);
    
    printf("Attempt to enqueue into full queue:\n");
    enqueue(q, 600);             // Expected: Queue Overflow

    // Test case 5: Dequeue all elements to empty the queue
    printf("Dequeue elements to empty queue:\n");
    printf("%d\n", dequeue(q));  // Expected: 100
    printf("%d\n", dequeue(q));  // Expected: 200
    printf("%d\n", dequeue(q));  // Expected: 300
    printf("%d\n", dequeue(q));  // Expected: 400
    printf("%d\n", dequeue(q));  // Expected: 500

    // Test case 6: Enqueue and dequeue to check front and rear update correctly
    printf("Enqueue 700, 800 after emptying the queue:\n");
    enqueue(q, 700);
    enqueue(q, 800);

    printf("Peek front element: %d\n", peek(q));  // Expected: 700
    printf("Dequeue element: %d\n", dequeue(q));  // Expected: 700
    printf("Peek front element after dequeue: %d\n", peek(q));  // Expected: 800

    freeQueue(q);
    return 0;
}
