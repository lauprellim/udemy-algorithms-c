#include<stdio.h>

// nCr problem -- simply stated,
// nCr = n! / r!(n-r)!
// one can do a simple solution using fact() function
// or do it recursively using Pascal's Triangle!
// n = number of total objects in urn
// r = number of objects chosen at once
// remember that 0 <= r <= n

// straightforward factorial function
// even so these functions seem to throw a segmentation fault!

int fact(int n) {
  if(n==0) return 1;
  return fact(n-1)*n;
}

int nCr(int n, int r) {
  int numerator, denominator;
  numerator = fact(n);
  denominator = fact(r) * fact(n-r);
  // this is going to be an integer value
  return numerator/denominator;
}

// now a recursive version using Pascal's Triangle
int nCrRec(int n, int r) {
  // the edges of the triangle...
  if(n==r || r==0) return 1;
  // return the sum of the upper branches of the tree:
  return nCrRec(n-1,r-1) + nCrRec(n-1,r);
}

int main() {
  // first obtain solution using fact()
  // printf("Solution of 5C10 using nCr(): %d", nCr(5,10));
  printf("Solution of 5c10 using nCrRec(): %d", nCrRec(5,10));
  return 0;
}
