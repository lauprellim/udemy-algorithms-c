#include<stdio.h>

// comparing strings
// just move a pointer through both strings...

int getLength(char *arr) {
  int i;
  for ( i = 0; arr[i] != '\0'; i++) {}
  return i;
}

int compareString(char *arr1, char *arr2) {
  int i, length;
  length = getLength(arr1);
  for ( i = 0; i < length; i++) if( arr1[i] != arr2[i] ) return 0;
  return 1;
}

void swap(char *arr1, int i, int j) {
  int t;
  t = arr1[i];
  arr[i] = arr[j];
  arr[j] = t;  
}

void reverseString(char *arr1) {
  int i, j;
  j = getLength(arr1);
  for (i=0; arr[i] != '\0'; i++, j--) swap(arr1, i, j);
}



int main() {

  char A[] = "Painter";
  char B[] = "Painting";

  char C[] = "Hello";
  char D[] = "Hello";

  char E[] = "madam";
  
  int same1 = compareString(A, B);
  int same2 = compareString(C, D);

  printf("Result of checking string %s and %s: %d\n", A, B, same1);
  printf("Result of checking string %s and %s: %d\n", C, D, same2);


  
  return 0;
}
