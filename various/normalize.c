/*
This program will normalize an array of integers in place.

Be sure to compile using -lm to ensure the math library is linked.
gcc normalize.c -o normalize -lm

Given:
  - an array of ints
  - its length

Provide:
  - minimum and maximum values in the array
  - linearly scale every element so that:
    - the minimum becomes 0
    - the maximum becomes 100
  - modify the array in place using pointers, not array indexing.

Assume:
  - the array has at least 2 elements
  - max != min

Example:
  - Input array = { 10, 20, 30, 40 }
    - output should be: { 0, 33, 66, 100 }

 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>


struct Array {
  int *A;
  int size;
};

void display(const struct Array *arr) {
  printf("Elements of array length %d are: { ", arr->size);
  for (int i = 0; i < arr->size; i++) printf("%d ", arr->A[i]);
  printf("}\n");
}

void normalize(struct Array *arr) {
  // minmax scan
  int min = INT_MAX;
  int max = INT_MIN;

  // get min and max
  for(int i=0; i < arr->size; i++) {
    if( arr->A[i] > max ) max = arr->A[i];
    if( arr->A[i] < min ) min = arr->A[i];
  }
  
  printf("Maximum integer: %d\nMinimum integer: %d\n", max, min);

  // start array at 0
  if(min != 0) {
    for(int i=0; i < arr->size; i++) {
      arr->A[i] = arr->A[i] - min;
    }
    printf("Array needs to start at 0. New array:\n");
    display(arr);
  }

  int arrayWidth = max - min;
  double scaleFactor = 100 / (double)arrayWidth;

  // step through the array a second time
  for(int i=0; i < arr->size; i++) {
    arr->A[i] = (int)round( (double)arr->A[i] * scaleFactor);
  }

  printf("Array is now scaled from 0 to 100.\n");
  display(arr);  
}


int main() {
  struct Array arr = {0};
  arr.size = 0;

  printf("Enter size of your array: ");
  if(scanf("%d", &arr.size) != 1 || arr.size <= 0 ) {
    fprintf(stderr, "Error: invalid array size.\n");
    return 1;
  }

  arr.A = malloc((size_t)arr.size * sizeof *arr.A);
  if(arr.A == NULL) {
    fprintf(stderr, "Error: memory allocation failed.\n");
    return 1;
  }

  printf("Enter all your elements: ");
  for(int i = 0; i < arr.size; i++) {
    if(scanf("%d", &arr.A[i]) != 1) {
      fprintf(stderr, "Error: invalid integer input.\n");
      free(arr.A);
      return 1;
    }
  }

  display(&arr);
  normalize(&arr);
  free(arr.A);
  
  return 0;
}
