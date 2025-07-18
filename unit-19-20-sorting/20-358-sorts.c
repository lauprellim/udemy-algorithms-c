#include<stdio.h>
#include<stdint.h> // for INT_MAX

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

/* Insertion sort is quite inefficient (O(n^2) comparisons
   and O(n^2) swaps if list is sorted in REVERSE) but it is
   adaptive and stable. It's better to work on a linked list
   rather than an array because then you reduce the
   number of swaps. It's simple to code, obviously. But every
   time you insert a new element, you potentially have to move
   the ENTIRE array...very time consuming! In order to make
   insertion sort adaptive you don't need an extra flag as in
   bubble sort.
 */

void Insertion(int A[], int n){
  int i, j, x;

  // assume first element of the array is already sorted
  for(i=1; i<n; i++) {
    j = i-1;
    x = A[i];
    // shift elements. If j == -1 we are to the left of the array
    while(j > -1 && A[j] > x) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = x;
  }
}

/* Selection sort is also inefficient (O(n^2)) comparisons,
   but only O(n) swaps). Three pointers are used here. You do
   get the smallest (or greatest) element in one pass though!
   You get k smallest elements in k passes, so intermediate results
   of selection sort are useful. 
   You select a position, and find the element for that position.
   This is not adaptive, so if the array is already sorted, we
   still need n^2 time to sort it. It is also not stable -- because
   of the way swaps happen, duplicates can be reordered.
   But this is such a simple piece of code!
*/

void SelectionSort(int A[], int n){
  int i,j,k;

  // outer loop is for the passes
  for(i=0; i<n-1; i++){
    // inner loop is for the j, k pointers in each pass
    for(j=k=i; j<n; j++) if(A[j] < A[k]) k = j;
    swap(&A[i], &A[k]);
  }
}

// Quick sort...
int partition(int A[], int l, int h){
  int pivot=A[l];
  int j;
  int i=l; j=h;
  do{
    // move pivots
    do{i++;}while(A[i]<=pivot);
    do{j--;}while(A[j]>pivot);

    if(i<j) swap(&A[i],&A[j]);
  }while(i<j);
  swap(&A[l],&A[j]);
  return j;
}

void QuickSort(int A[], int l, int h){
  int j;
  if(l<h){
    j = partition(A, l, h);
    QuickSort(A, l,  j);
    QuickSort(A, j+1, h);
  }
}

// Merge sort needs a merging function and a func to call that merge.
// There will be both iterative and recursive versions! This is a
// "two-wave" merge sort, so we are merging two lists together at
// a time.
// The iterative version is quite complicated but really usefulful
// to understand the recursive version.

void Merge(int A[], int l,  int mid, int h){
  // counters and aux array arbitrarily set to size 100
  int i=l, j=mid+1, k=l;
  int B[100];

  while(i<=mid && j<= h){
    if(A[i] < A[j]) B[k++] = A[i++];
    else B[k++] = A[j++];  
  }
  // copy remaining elements. as before only one of these for loops
  // will execute
  for(;i<=mid;i++) B[k++] = A[i];
  for(;j<=h;j++) B[k++] = A[j];

  // copy all the elements from the aux array to the original array
  for(int i=l; i<=h; i++) A[i] = B[i];
}

// iterative merge sort
void IMergeSort(int A[], int n){
  int p, l, h, mid, i;

  // first loop is for passes, note the parameters
  for(p=2; p<=n; p=p*2) {
    // for merging all the lists in a single pass
    for(i=0; i+p-1<n; i=i+p){
      l=i;
      h=i+p-1;
      mid=(l+h)/2;
      Merge(A, l, mid, h);
    }
    /*
    if(n-i>p/2){
      l=i;
      h=i+p-1;
      mid=(l+h)/2;
      Merge(A, l, mid, n-1);
    }
    */
  }
  // This line picks up the elements that remain if the array to be
  // sorted has a length that is NOT a power of 2.
  // if the array to be sorted is greater than x^2 in length:
  // ...if there are 8 elements the indecies should be 0-7, hence
  // the p/2-1...
  if(p/2 < n) Merge(A, 0, p/2-1, n-1);
}

// The recursive version is shockingly simple. Tracing the recursive
// calls is fascinating. Merging is done n(log(n)) times (avg time).
// Merging is done in POSTORDER, as the recursive calls are all in
// the form of a complete binary tree.
// Space requirement is greater as we need auxilliary array B for
// merging. Size of the stack is log n, as this is recursive.
void RMergeSort(int A[], int l, int h){
  if(l<h) {
    int mid = (l+h)/2;
    // descend to the left side of the array
    RMergeSort(A, l, mid);
    RMergeSort(A, mid+1, h);
    Merge(A, l, mid, h);
  }
}

// ------------------------------------------------

int main(){
  // use INT_MAX for quicksort
  int A[]={3, 7, 9, 10, 6, 5, 12, 4, 11, 2, INT32_MAX}, n = 11;
  int i;
  
  printf("Original array -> ");
  for(i=0; i<n; i++) printf("%d ", A[i]);
  printf("\n");

  RMergeSort(A, 0, n-1);
  // IMergeSort(A, n-1);
  
  // send index
  // QuickSort(A, 0, n-1);
  
  // SelectionSort(A, n);
  // Insertion(A, n);
  // Bubble(A, 10);

  printf("Sorted         -> ");

  for(i=0; i<n; i++) printf("%d ", A[i]);
  printf("\n");
  
  return 0;
}
