#include<stdio.h>
#include<stdlib.h>

void populate(int *A, int n) {
  for(int i = 0; i<n; i++) {
    A[i] = i*3;
  }
}

// try * instead of []?
int * fun(int n) {
  int *p;
  // allocate an array of size n (times the size of int)
  p=(int *)malloc(n*sizeof(int));
  return p;
}

int main() {
  int *A;
  // this will return an array
  A=fun(5);

  populate(A,5);

  printf("Array contents: ");
  for(int i=0; i<5; i++) {
    printf("%d ",A[i]);
  }
  printf("\n");
}
