#include <stdio.h>

int fib(int n) {
  // need two terms, a sum and an iterator
  int t0=0, t1=1, s=0, i;

  if (n<=1) return n;

  for(i=2; i<=n; i++) {
    s=t0+t1;
    t0=t1;
    t1=s;
  }
  
  return s;
}

int main() {
  printf("Fibonacci(12) using iterative method yields %d.\n", fib(12)); 
  return 0;
}
