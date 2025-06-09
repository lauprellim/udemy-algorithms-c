#include<stdio.h>
#include<stdlib.h>

int main() {
  // initialize 2D arrays
  
  // first method: create array inside stack memory
  int A[3][4] = {{1,2,3,4},{2,4,6,8},{1,3,5,7}};

  // second method: create array of pointers
  int *B[3];
  // for each location in this array, create array in heap memory
  B[0] = (int *)malloc(4*sizeof(int));
  B[1] = (int *)malloc(4*sizeof(int));
  B[2] = (int *)malloc(4*sizeof(int));

  // third method: double pointer
  int **C;
  C = (int **)malloc(3*sizeof(int *));
  C[0] = (int *)malloc(4*sizeof(int));
  C[1] = (int *)malloc(4*sizeof(int));
  C[2] = (int *)malloc(4*sizeof(int));

  // print elements of 2D array A:
  int i,j;
  for(i=0; i<3; i++) {
    for(j=0; j<4; j++) printf("%d ",A[i][j]);
    printf("\n");
  }
  
  return 0;
}
