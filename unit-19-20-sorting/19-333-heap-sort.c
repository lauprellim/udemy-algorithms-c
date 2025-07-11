#include<stdio.h>
#include<stdlib.h>

void Insert(int A[], int n){
  int i = n, temp;
  temp = A[i];

  // swap element until it reaches root or until it finds
  // its correct place
  while(i>1 && temp>A[i/2]){
    A[i] = A[i/2];
    // move to parent
    i = i/2;    
  }
  A[i] = temp;
}

int Delete(int A[], int n){
  // n is size of heap
  int x, i, j, temp, val;
  // this is the deleted value:
  val = A[1];
  // we always delete the root (greatest data element)
  x = A[1];
  // last element is placed as root -- that is, rightmost leaf node
  A[1] = A[n];
  // move deleted value to the end of the array -- this will be sorted
  A[n] = val;
  // j pointsy to left child of i
  i = 1; j = i*2;

  // size of unsorted array is reduced by 1
  while(j < n-1){
    // if right child is greater than left child:
    // point on right child
    if(A[j+1] > A[j]) j = j+1;
    // interchange elements
    if(A[i] < A[j]) {
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
      i = j;
      j = 2*j; // move to left child
    }
    else break;
  }
  return val;
}


int main() {
  // 0 is a kind of null location
  // int H[] = {0, 2, 5, 8, 9, 4, 10, 7};
  int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
  int i;
  
  printf("Original order -> ");
  for(i=1; i<=7; i++) printf("%d ", H[i]);
  printf("\n");
  
  for(i = 2; i<=7; i++) Insert(H, i);
    
  printf("After going into heap: -> ");
  // root node is first, its children are second and third
  for(i=1; i<=7; i++) printf("%d ", H[i]);
  printf("\n");

  printf("Deleting all elements and sorting array/heap...\n");
  // printf("Deleted value is %d\n", Delete(H, 7));

  // delete all the elements one by one
  for(i=7; i>1; i--) Delete(H, i);
  
  printf("New heap -> ");
  for(i=1; i<=7; i++) printf("%d ", H[i]);
  printf("\n");
  
  return 0;
}
