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
  int p = 5;
  int *ptr;
  ptr = &p;
  // printf("p = %d and &p = %p\n", p, &p);
  printf("Question 3: return value of p is: %d\n", q3(p,p));

  return 0;
}
