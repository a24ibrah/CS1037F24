#include <stdio.h>

int main() {
    int num;
    int *ptr;
    ptr = &num;     // address assignment, ptr is pointing num
    *ptr = 2;       // num will have value 2 at runtime
    }
