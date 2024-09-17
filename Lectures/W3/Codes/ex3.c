#include<stdio.h>
int main() {
  int x = 6;
  printf("Value of x is %d\n", x);
  printf("Runtime memory address of x in Hex is %p\n", &x);
  printf("Runtime memory address of x in decimal is %lu\n", &x);
  printf("Value stored at address %lu is %d\n", &x, *(&x));
  return 0;
}
