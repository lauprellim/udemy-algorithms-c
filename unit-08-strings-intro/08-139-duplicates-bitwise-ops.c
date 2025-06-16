// left shift
// OR ("merging")
// AND ("masking")

#include<stdio.h>

int main() {
  // need 26 bits (one for each letter in the lower-case alphabet
  // we will use long int (32 bits)
  // the bits are kind of like a "hash table". We'll use the lowest
  // 26 bits
  // ASCII 97 = "a".

  char A[] = "somekindofstringinlowercase";
  long int H = 0;
  int i, x;

  printf("String is %s.\n", A);
  
  for ( i=0; A[i]!='\0'; i++) {
    x = 1;
    // left shift the 1 by however many places is the ascii code
    x = x << (A[i] - 97);
    // check if the bit is already on; if it is, that letter is already there
    // use AND & bitwise operation
    if ( ( x & H ) > 0 ) printf("%c is duplicate.\n", A[i]);
    // otherwise set that bit on -- merge it to H using OR bitwise operation
    else H = x | H;
  }
  return 0;
}
