#include<stdio.h>

void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

// this makes the sort adaptive, so if the array is already
// sorted, it only makes one pass.
void Bubble(int A[], int n){
  int i,j, flag = 0;
  for(i=0; i<n-1; i++){
    // it is j<n-i-1 because each pass needs to sort
    // one FEWER elements, as for k passes, k elements
    // are sorted.
    for(j=0; j<n-i-1; j++){
      if(A[j] > A[j+1]) {
	swap(&A[j], &A[j+1]);
	flag=1;
      }
    }
    // flag will be 0 if no sorting was done, i.e., the
    // array was already sorted.
    if(flag == 0) break;
  }
}

// ------------------------------------------------

int main(){
  int A[]={3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
  int i;
  
  printf("Original array -> ");
  for(i=0; i<10; i++) printf("%d ", A[i]);
  printf("\n");
  
  Bubble(A, 10);

  printf("Bubble sort ->    ");
  for(i=0; i<10; i++) printf("%d ", A[i]);
  printf("\n");

  return 0;
}
