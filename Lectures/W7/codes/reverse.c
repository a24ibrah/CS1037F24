// Function to reverse the linked list
struct Node* reverseLinkedList(struct Node* head) {
    struct Node* prevNode = NULL;
    struct Node* nextNode = NULL;
    struct Node* current = head;
    
    while (current != NULL) {
        // Store the next node
        nextNode = current->next;
        // Reverse the link
        current->next = prevNode;
        // Move prevNode and current one step forward
        prevNode = current;
        current = nextNode;
    }
    // Return the new head (prevNode)
    return prevNode;
}
