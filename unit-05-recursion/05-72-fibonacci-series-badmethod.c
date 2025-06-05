#include <stdio.h>

// this is a very inefficient way of calculating the
// fibonnaci series using excessive recursion. The time
// complexity is an astonishing O(2^n)
static int counter = 0;

int fib_bad(int n){
  if (n<=1) return n;
  counter++;
  return fib_bad(n-2) + fib_bad(n-1);
}

int main() {
  printf("The bad way of calculating fib(12) yields the value %d in %d iterations.\n", fib_bad(12), counter); 
  
  return 0;
}
