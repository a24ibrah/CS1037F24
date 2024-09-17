#include <stdio.h>

int main() {
    // Declare an array of integers
    int arr[5] = {10, 20, 30, 40, 50};
    
    // Declare a pointer to an integer
    int *ptr;

    // Initialize the pointer to point to the first element of the array
    ptr = arr;

    // Use pointer to access and manipulate array elements
    for(int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, *(ptr + i));
    }

    return 0;
}

