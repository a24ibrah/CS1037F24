#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

// Function to get the height of a node
int height(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Utility function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node
AVLNode* createNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}

// Right rotate subtree rooted with y
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    
    // Perform rotation
    x->right = y;
    y->left = T2;
    
    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    // Return new root
    return x;
}

// Left rotate subtree rooted with x
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    
    // Perform rotation
    y->left = x;
    x->right = T2;
    
    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    // Return new root
    return y;
}

// Get the balance factor of a node
int getBalance(AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Insert a node in the AVL tree and balance the tree
AVLNode* insert(AVLNode* node, int key) {
    // Perform the normal BST insertion
    if (node == NULL)
        return createNode(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in AVL Tree
        return node;
    
    // Update the height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));
    
    // Get the balance factor of this ancestor node to check if it became unbalanced
    int balance = getBalance(node);
    
    // If this node becomes unbalanced, then there are 4 cases
    
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    
    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    // Return the (unchanged) node pointer
    return node;
}

// Utility function to print pre-order traversal of the tree
void preOrder(AVLNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    AVLNode* root = NULL;
    
    // Insert nodes into the AVL tree
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 5); // This will trigger rotations
    
    // Print the pre-order traversal of the AVL tree
    printf("Pre-order traversal of the AVL tree is:\n");
    preOrder(root);
    
    return 0;
}
