#include<stdio.h>

int q1(int n) {
  static int i = 1;
  if (n>=5) return n;
  // printf("n equals %d\n",n);
  n = n+i;
  i++;
  return q1(n);
}

void q2(int n, int sum) {
  int k=0, j=0;
  if(n==0) return;
  k=n%10;
  j=n/10;
  sum = sum+k;
  q2(j,sum);
  printf("Partial sum: %d\n",k);
}

int q4(int n) {
  int x=1, k;
  if(n==1) return x;
  for(k=1; k<n; ++k) x = x + q4(k) * q4(n-k);
  return x;
}

void q5(int n) {
  // in the questions, this function is called count().
  static int d=1;
  printf("%d ", n);
  printf("%d ", d);
  d++;
  if(n>1) q5(n-1);
  printf("%d ", d);
}

int main() {
  // question 1
  printf("Question 1: The value q1(1) returns is: %d\n\n", q1(1));

  // question 2
  int a = 2048, sum = 0;
  q2(a, sum);
  printf("Question 2: Sum is %d\n\n", sum);

  // question 3 has to be done in c++ because the function
  // is pass by reference using &.

  // question 4
  printf("Question 4: return value of q4(5) is: %d\n\n", q4(5));
  
  // question 5
  printf("Question 5: q5(3) produces: \n");
  q5(3);
  printf("\n\n");
  
  return 0;
}
