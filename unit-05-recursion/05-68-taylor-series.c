#include <stdio.h>

// approximate e^x using Taylor series 
// this is a bit ineffecient as it requires O(n^2) multiplications
// we can reduce the time complexity to O(n) using Horner's Rule,
// but that is a task for the next algorithm!

// int x = the power of e
// int n = the number of terms we want
double e(int x, int n) {
  // p = power; f = factorial (for the denominator of each term)
  // r stores the result
  static double p=1, f=1;
  double r;
  
  if(n==0) return 1;
  // and here's the recursive call...
  // which is HEAD recursion
  r = e(x, n-1);
  p = p*x;
  f = f*n;
  return r + p/f;
  
}
  
int main() {
  // we want 10 terms
  // the first parameter is the power we want e to,
  // the second parameter is the number of terms, which
  // corresponds to the number of times the recursive
  // call is made.
  printf("Approximate value of e is: %lf \n", e(1,10));
  return 0;
}
