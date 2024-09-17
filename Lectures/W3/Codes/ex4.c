int x = 10;  // declares x and initializes it with value 10
int *p;      // declares p as an int type pointer
p = &x;      // assigns the address of x to p
int b = *p;  // dereferences p, assigns the value to b (b = 10)
b = b + 10;  // increases b's value by 10 (b = 20)
*p = b;      // stores b's value in the memory location pointed by p (x now equals 20)
