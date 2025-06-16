#include<stdio.h>
#include<string.h>

// comparing strings
// just move a pointer through both strings...

int getLength(char *arr) {
  int i;
  for ( i = 0; arr[i] != '\0'; i++) {}
  return i-1;
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
  arr1[i] = arr1[j];
  arr1[j] = t;
}

void reverseString(char *arr1) {
  int i, j;
  j = getLength(arr1);
  for (i=0; i < j; i++, j--) swap(arr1, i, j);
}

int main() {

  char A[] = "Painter";
  char B[] = "Painting";

  char C[] = "Hello";
  char D[] = "Hello";

  char C1[20];
  strcpy(C1, C);
  reverseString(C1); 
 
  char E[] = "madam";
  char E1[20];
  strcpy(E1, E);
  reverseString(E1);
  
  int same1 = compareString(A, B);
  int same2 = compareString(C, D);

  printf("Result of checking string %s and %s: %d\n", A, B, same1);
  printf("Result of checking string %s and %s: %d\n", C, D, same2);
  printf("String E = %s; string E1 = %s.\n", E, E1);

  if(compareString(E, E1) == 1) printf("String E %s is a palindrome.\n", E);

  printf("String C = %s; string C1 = %s.\n", C, C1);
  if(compareString(C, C1) == 0) printf("String C %s is NOT a palindrome.\n", C);

  return 0;
}
