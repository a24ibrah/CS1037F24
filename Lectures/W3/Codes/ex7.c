#include <stdio.h>

int main() {

  int x=10;
  
  // pointer pointing to an int variable
  int *px;
  
  // pointer pointing to an int pointer
  int **ppx;  
  
  // px pointing to x
  px=&x; 
  
  // ppx pointing to px
  ppx=&px;  
  
  // or *(*ppx) will print 10
  printf("%d\n", **ppx); 

  return 0;
}