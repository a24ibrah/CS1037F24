
int main() {
    int x = 10;         // Declare an integer variable 'x' and initialize it to 10.
    int *ptr = &x;      // Declare a pointer 'ptr' that points to the memory address of 'x'.

    int y = *ptr;       // Dereference 'ptr' to get the value of 'x' and assign it to 'y'.
    *ptr = 50;          // Modify the value at the memory location pointed to by 'ptr' (which is 'x') to 50.

    return 0;
}

