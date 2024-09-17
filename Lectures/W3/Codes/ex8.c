#include <stdio.h>

int main() {
  
 int *p = (int*) malloc (sizeof(int)); 
 
 *p = 3; 
 
 printf("%d", *p);
 
 p = NULL; // this causes a memory leaking

  return 0;
}

