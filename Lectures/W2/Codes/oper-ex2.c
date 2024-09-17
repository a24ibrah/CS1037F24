#include <stdio.h>

int main() {
    unsigned int a = 6, b = 3;  // 6 = 110, 3 = 011

    //signed int: Used when negative numbers are needed.
    //unsigned int: Used when only non-negative numbers are needed
    //the default is signed int

    printf("a & b: %d\n", a & b);  // AND
    printf("a | b: %d\n", a | b);  // OR
    printf("a ^ b: %d\n", a ^ b);  // XOR
    printf("~a: %d\n", ~a);        // NOT
    printf("a << 1: %d\n", a << 1);  // Shift left
    printf("a >> 1: %d\n", a >> 1);  // Shift right

    return 0;
}


