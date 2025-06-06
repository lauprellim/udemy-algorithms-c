#include<stdio.h>

int f(int n) {
  static int i = 1;
  if (n>=5) return n;
  // printf("n equals %d\n",n);
  n = n+i;
  i++;
  return f(n);
}

void foo(int n, int sum) {
  int k=0, j=0;
  if(n==0) return;
  k=n%10;
  j=n/10;
  sum = sum+k;
  foo(j,sum);
  printf("Partial sum: %d\n",k);
}

int q3(int &x, int c) {
  int c = c - 1;
  if(c==0) return 1;
  int x = x + 1;
  return q3(x,c)*x;
}

int main() {
  // question 1
  printf("Question 1: The value f(1) returns is: %d\n\n", f(1));

  // question 2
  int a = 2048, sum = 0;
  foo(a, sum);
  printf("Question 2: Sum is %d\n\n", sum);

  // question 3
  int p = 5;
  printf("Question 3: return value of p is: %d\n", q3(&p,p));

  return 0;
}
