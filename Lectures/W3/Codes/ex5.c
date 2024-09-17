#include <stdio.h>

int main() {
    int num1=2, num2= 3, sum=0, mul=0;
    int *ptr1, *ptr2, *ptr3;
    ptr1 = &num1;        // address assignment, ptr1 is pointing to num1 
    ptr2 = &num2;        // address assignment, ptr2 is pointing to num2 
    ptr3 = ptr1;         // assign ptr1 to to ptr2, ptr3 is pointing to num1 
    sum = *ptr1 + *ptr2; // dereferencing ptr1 and ptr2, the value of sum will be 5 at runtime
    mul = sum * *ptr3;
    printf("Sum: %d\n", sum);
    printf("Milt.: %d", mul); // dereferencing ptr3, the value of mul will be 10 at runtime
    }

    