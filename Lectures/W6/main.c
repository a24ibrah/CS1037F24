#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Define a structure to represent each task.
typedef struct node{
    char task[100];
    struct node *next;
} NODE;

// 2. Create a few tasks and link them together in a sequence.
NODE* createNode(char *task) {
    NODE *newNode = (NODE *) malloc(sizeof(NODE));
    strcpy(newNode->task, task);
    newNode->next = NULL;
    return newNode;
}

void addNode(NODE **start, char *task) {
    NODE *newNode = createNode(task);
    newNode->next = *start;
    *start = newNode;
}

// 3. Traverse the list to display the tasks in the order they need to be completed.
void printList(NODE *start) {
    NODE *current = start;
    while (current != NULL) {
        printf("%s\n", current->task);
        current = current->next;
    }
}

int main() {
    NODE *start = NULL;
    addNode(&start, "Task 1");
    addNode(&start, "Task 2");
    addNode(&start, "Task 3");
    printList(start);
    return 0;
}
