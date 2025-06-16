#include<stdio.h>

// to reverse an array we can take another array and
// simply copy elements, one-by-one, into that array.

// or you can swap first with last element, second with
// second-to-last element, etc.

void swap(char *arr, int i, int j) {
  int t;
  t = arr[i];
  arr[i] = arr[j];
  arr[j] = t;
}

int main() {
  char A[] = "python is a different computer language";

  printf("Original string: %s\n", A);
  int i, j;
  for(j = 0; A[j] != '\0'; j++) { }
  printf("Length of string is %d\n", j);
  j--;

  // don't have to send &A here even though we are modifying array...
  for (i=0; i < j; i++, j--) swap(A, i, j);
  printf("New string: %s\n", A);
  return 0;
}
