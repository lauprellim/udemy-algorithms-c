#include <stdio.h>

// for both of these functions, x is the power of e desired
// and n is the number of terms in the Taylor series desired.
// This method reduces the number of calculations from O(n^2)
// to O(n) using Horner's rule.

double eLoop(double x, double n) {
  double s = 1;
  for(;n>0; n--) {
    s = 1 + (x/n) * s;
  }
  return s;
}

double eRecursive(double x, double n) {
  // use TAIL recursion here...
  static double s=1;
  if (n==0) return s;
  s = 1 + (x/n) * s;
  return eRecursive(x,n-1);
}

int main() {
  printf("Value of e using loop method: %lf\n", eLoop(1, 10));
  printf("value of e using recursive method: %lf\n", eRecursive(1,10));
  
  return 0;
}
