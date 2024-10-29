#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    int capacity;
    int *array;
} Stack;

Stack *createStack(int capacity) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->top = -1;
    s->array = (int *)malloc(s->capacity * sizeof(int));
    return s;       
}

void push(Stack *s, int data) {
    if (s->top == s->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->array[s->top] = data;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int data = s->array[s->top];
    s->top--;
    return data;
}

int peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->array[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == s->capacity - 1;
}   

void freeStack(Stack *s) {
    free(s->array);
    free(s);
}

int main() {
    Stack *s = createStack(5);
    
    // Test Case 1: Basic functionality
    printf("Pushing elements: 10, 20, 30, 40, 50\n");
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);

    printf("Popping elements:\n");
    printf("%d\n", pop(s));  // Expected: 50
    printf("%d\n", pop(s));  // Expected: 40
    printf("%d\n", pop(s));  // Expected: 30
    printf("%d\n", pop(s));  // Expected: 20
    printf("%d\n", pop(s));  // Expected: 10

    // Test Case 2: Edge case - Pop from empty stack
    printf("Attempting to pop from an empty stack:\n");
    printf("%d\n", pop(s));  // Expected: Stack Underflow

    // Test Case 3: Peek on an empty stack
    printf("Attempting to peek on an empty stack:\n");
    printf("%d\n", peek(s));  // Expected: Stack Underflow

    // Test Case 4: Fill the stack to capacity and test overflow
    printf("Pushing elements to fill the stack to capacity:\n");
    push(s, 100);
    push(s, 200);
    push(s, 300);
    push(s, 400);
    push(s, 500);

    printf("Attempting to push into a full stack:\n");
    push(s, 600);  // Expected: Stack Overflow

    // Test Case 5: Check isEmpty and isFull
    printf("Checking if the stack is full: %d\n", isFull(s));  // Expected: 1 (true)
    printf("Popping all elements to empty the stack\n");
    while (!isEmpty(s)) {
        printf("Popped: %d\n", pop(s));
    }
    printf("Checking if the stack is empty: %d\n", isEmpty(s));  // Expected: 1 (true)

    // Test Case 6: Peek and push after clearing the stack
    printf("Attempting to peek on an empty stack:\n");
    printf("%d\n", peek(s));  // Expected: Stack Underflow

    printf("Pushing elements: 700, 800 after clearing the stack:\n");
    push(s, 700);
    push(s, 800);

    printf("Peek top element: %d\n", peek(s));  // Expected: 800
    printf("Popping element: %d\n", pop(s));    // Expected: 800
    printf("Peek top element after pop: %d\n", peek(s));  // Expected: 700

    freeStack(s);
    return 0;
}
