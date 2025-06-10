#include <stdio.h>
#include <stdlib.h>

int main (){
  int x[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};

  printf("Size of an int: %d\n", sizeof(int));
  printf("Base address of 2D array: %u\n", x);
  printf("More addresses: %u %u %u\n", x+3, *(x+3), *(x+2)+3);
  printf("Some values: %d %d %d\n\n", *(*x), *(*x+3), *(*x+2)+3);
  
  return 0;
}
