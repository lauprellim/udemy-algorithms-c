#include<stdio.h>

int main() {
  // in C, size of array is allocated at compile time,
  // the size cannot be a variable
  // in C++, size of array can be allocated at run time.
  
  int A[5] = {10, 15, 20, 25, 30};
  int i;

  printf("Elements of array A:\n");
  for(i=0; i<5; i++) printf("%u ", A[i]);
  // this will usually only work in C++:
  // printf("\nAddresses of those elements:\n");
  //  for(i=0; i<5; i++) printf("%u ", &A[i]);
  printf("\nElements of array A using a pointer:\n");
  for(i=0; i<5; i++) printf("%u ", *(A + i));
  printf("\n\n");
  
  return 0;
}
