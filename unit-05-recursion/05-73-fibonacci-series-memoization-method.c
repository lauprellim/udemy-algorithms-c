#include <stdio.h>

// this is the very inefficient method that uses O(2^n) time
int rfib(int n) {
  if(n<=1) return n;
  return rfib(n-2)+rfib(n-1);
}

// initialize array for memoization method. This will store
// something like "partial solutions". All elements of the
// array will be initialized to -1.
int F[10];

// memoization method -- store solutions in an array,
// look up those values. This can calculate fibonacci
// series in O(n) time.
// For some reason this is not executing correctly on the
// command line, but it does run in Visual Studio...
int mfib(int n) {
  if(n<=1) {
    F[n]=n;
    return n;
  }
  else {
    if (F[n-2] == -1) F[n-2] = mfib(n-2);
    if (F[n-1] == -1) F[n-1] = mfib(n-1);
    F[n] = F[n-2] + F[n-1];
    return F[n-2] + F[n-1];
  }
}

int main() {
  // fill array with -1 ("we don't know the value at this index")
  int i;
  for (i=0; i<10; i++) F[i]=-1;
  printf("Fib(9) equals %d.\n", mfib(9));
  return 0;
}
