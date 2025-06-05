#include<stdio.h>

// tree recursion is a kind of recursion that calls itself more
// than one time.

static int numberOfCalls = 0;

void fun(int n) {
  numberOfCalls++;
  if (n>0) {
    printf("%d ",n);
    fun(n-1);
    fun(n-1);
  }
}

int main() {
  fun(4);
  printf("\n");
  printf("Number of Calls: %d\n",numberOfCalls);
  return 0;
}
