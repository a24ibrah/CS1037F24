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
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    freeStack(s);
    return 0;
}