#include <stdio.h>
#include <stdlib.h>

// Define the structure for tree nodes
typedef struct Node {
    int isExternal;       // 1 if the node is a leaf (operand), 0 if it's an operator
    double value;         // Holds the operand value if the node is external
    char operator;        // Holds the operator if the node is internal
    struct Node* left;    // Left child
    struct Node* right;   // Right child
} Node;

// Function to evaluate the expression tree
double evalExpr(Node* v) {
    if (v->isExternal) {
        return v->value;  // Return operand value if the node is external
    } else {
        double x = evalExpr(v->left);    // Evaluate the left subtree
        double y = evalExpr(v->right);   // Evaluate the right subtree
        char op = v->operator;           // Operator stored at the internal node

        // Perform the operation based on the operator
        switch (op) {
            case '+': return x + y;
            case '-': return x - y;
            case '*': return x * y;
            case '/': return x / y;
            default:
                printf("Error: Unknown operator '%c'\n", op);
                exit(1);
        }
    }
}

// Helper function to create a new node (for internal use)
Node* createNode(int isExternal, double value, char operator, Node* left, Node* right) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->isExternal = isExternal;
    newNode->value = value;
    newNode->operator = operator;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

int main() {
    // Example usage of evalExpr
    // Expression: (3 + (4 * 5))
    Node* n1 = createNode(1, 3, '\0', NULL, NULL);         // Leaf node with value 3
    Node* n2 = createNode(1, 4, '\0', NULL, NULL);         // Leaf node with value 4
    Node* n3 = createNode(1, 5, '\0', NULL, NULL);         // Leaf node with value 5
    Node* n4 = createNode(0, 0, '*', n2, n3);              // Internal node with operator *
    Node* n5 = createNode(0, 0, '+', n1, n4);              // Internal node with operator +

    int result = (int) evalExpr(n5);
    printf("Result of expression: %d\n", result);

    // Free allocated memory
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return 0;
}


