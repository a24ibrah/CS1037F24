#include <stdio.h>
#include <stdlib.h>

typedef struct TNODE {
    int data;                 // Holds the data of the node
    struct TNODE* left;       // Pointer to the left child
    struct TNODE* right;      // Pointer to the right child
} TNODE;

// Define queue node
typedef struct QueueNode {
    TNODE* treeNode;
    struct QueueNode* next;
} QueueNode;

// Define queue
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Queue operations
void enqueue(Queue* q, TNODE* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (q->rear) q->rear->next = newNode;
    q->rear = newNode;
    if (!q->front) q->front = newNode;
}

TNODE* dequeue(Queue* q) {
    if (!q->front) return NULL;
    QueueNode* temp = q->front;
    TNODE* node = temp->treeNode;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return node;
}

// BFS search function
TNODE* bfsSearch(TNODE* root, int key) {
    if (!root) return NULL;

    Queue q = { NULL, NULL };
    enqueue(&q, root);

    while (q.front) {
        TNODE* node = dequeue(&q);

        if (node->data == key)
            return node;

        if (node->left) enqueue(&q, node->left);
        if (node->right) enqueue(&q, node->right);
    }
    return NULL;
}

// Helper function to create a new tree node
TNODE* createNode(int data) {
    TNODE* newNode = (TNODE*)malloc(sizeof(TNODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Main function to demonstrate the BFS search
int main() {
    // Creating a simple binary tree
    TNODE* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Example tree structure:
    //        1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7

    int key = 5; // Node value to search for
    TNODE* result = bfsSearch(root, key);

    if (result) {
        printf("Node with data %d found.\n", result->data);
    } else {
        printf("Node with data %d not found.\n", key);
    }

    // Free allocated memory (in a real scenario, you would need to free the entire tree)
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
