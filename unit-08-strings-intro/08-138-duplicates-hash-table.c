#include<stdio.h>

// need a hash table of size 25 as lower-case ASCII characters range
// from 97 - 122. Simply map each ASCII code onto the array index by
// subtracting 97.
// We will limit to lower-case characters only, so it doesn't get
// too complicated.

int main() {

  // here is the string we will count...
  char A[] = "howevermuchyouwanttoaddtothisstring";
  int H[26] = {0};
  int i;
  // can do it in just one line. Scan through the string
  for ( i = 0; A[i] != '\0'; i++) H[A[i]-97]+=1;

  // now scan through the hash table
  printf("Scanning string %s.\n", A);
  for (i=0; i<26; i++) {
    if(H[i] > 1) {
      printf("Character %c occurred %d times.\n", i+97, H[i]);
    }
  }
  return 0;
}
