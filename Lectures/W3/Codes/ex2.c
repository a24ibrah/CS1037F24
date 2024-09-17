#include <stdio.h>

int main() {
    int x = 10;         // Declare a variable
    int *ptr = &x;      // Declare a pointer and store the address of 'x'

    // Display the value of 'x' and the address stored in the pointer
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", &x);
    
    // Display the address stored in the pointer and the value it points to
    printf("Pointer ptr holds the address: %p\n", ptr);
    printf("Value pointed by ptr: %d\n", *ptr);

    return 0;
}
