#include<stdio.h>


void pp(int *n) {
  printf("Inside pp function where n is passed as *n.\n");
  printf("Dereferenced value of *n is %d\n", *n);
  printf("&n (just n) is %p\n", n);
  printf("\n");
}

void pa(int *A, int x) {
  int i;
  for ( i = 0; i < x; i++) {
    printf("Array value %d is %d\n", i, A[i]);
  }
  printf("\n");
}

void ma(int *A, int x) {
  A[x] = 99;
  pa(A, 5);  
}

int main() {
  int n;
  n = 50;

  int A[5] = {0,10,20,30,40};
  
  printf("value of n = %d\n", n);
  printf("memory address of n = %p\n", &n);
  printf("\n");
  pp(&n);
  
  // print array
  pa(A, 5);

  // modify array
  ma(A, 4);

  return 0;
}
