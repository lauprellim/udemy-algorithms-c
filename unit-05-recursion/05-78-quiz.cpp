#include<iostream>
using namespace std;

int q3(int &x, int c) {
  c--;
  if(c==0) return 1;
  x++;
  return q3(x,c)*x;
}

int main() {
  // question 3
  // this will recurse until x = 9;
  // but x is passed by reference, so when the chain of returns is triggered,
  // it will be first 1 * 9, then 9 * 9, then 9^3, then 9^4
  // (because we recursed four times);
  // and the return value will be 9^4 which is 6561.
  int p = 5;
  printf("Question 3: return value of p is: %d\n", q3(p,p));

  return 0;
}
