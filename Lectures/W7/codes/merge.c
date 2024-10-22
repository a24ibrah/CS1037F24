// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    // If one of the lists is empty, return the other list
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    // Create a dummy node to help build the new list
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->data = 0; // This value won't be used
    struct Node* current = dummy;

    // Traverse both lists and merge them in sorted order
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    // If there are remaining nodes in either list, append them
    if (head1 != NULL) {
        current->next = head1;
    } else if (head2 != NULL) {
        current->next = head2;
    }

    // The merged list starts at dummy->next, as dummy was just a helper node
    struct Node* mergedHead = dummy->next;
    free(dummy); // Free the dummy node
    return mergedHead;
}
