#include<stdio.h>

int q1(int n) {
  // this is static, so it only gets called ONCE!
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
  // this is much more straightforward than q4. remember
  // the static variable does not change, so this returns
  // 3 1 then 2 2 then 1 3 then 4 4 4
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
  // This is an amusing thing, it will print "2 0 4 8" as the return values
  // and sum will be 0 because that 0 belongs to MAIN function, not q2().
  // sum is call by VALUE, it is not modified outside of q2()!
  int a = 2048, sum = 0;
  q2(a, sum);
  printf("Question 2: Sum is %d\n\n", sum);

  // question 3 has to be done in c++ because the function
  // is pass by reference using &.
  // So I could mix C and C++ here but prefer to compile the different
  // languages in different text files...
  
  // question 4
  // this one is pretty complex. Don't trace this as a tree. Rather
  // make a table and start by tracing smaller values. It expands to:
  // x + q4(1) * q4(4) + q4(2) * q4(3) + q4(3) * q4(2) + q4(4) * q4(1)
  // so find value of q4(1) first, then make a table.
  // when q4(1), return value is 1.
  // when q4(2), return value is x + q4(1) * q4(2-1) so for loop repeats only once.
  //      q4(2)  returns 1 + 1 * 1, which is 2.
  // when q4(3), return value is x + q4(1) * q4(3-1) + q4(2) * q4(3-2)
  //      q4(3)  returns 1 + 1 * 2 + 2 * 1
  //             = 5
  // when q4(4)  returns 1 + q4(1) * q4(3) + q4(2) * q4(2) + q4(3) * q4(1)
  //             returns 1 + 1 * 5 + 2 * 2 + 5 * 1
  //             = 15
  // when q4(5)  returns 1 + 1 * 15 + 2 * 5 + 5 * 2 + 15 * 1
  //             and the return value is 51.

  printf("Question 4: return value of q4(5) is: %d\n\n", q4(5));
  
  // question 5
  printf("Question 5: q5(3) produces: \n");
  q5(3);
  printf("\n\n");
  
  return 0;
}
