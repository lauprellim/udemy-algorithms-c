#include<stdio.h>

void swap_pass_by_value(int x, int y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
}

void swap_pass_by_address(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int main() {
  int a,b;
  a=10;
  b=20;
  swap_pass_by_value(a,b);
  printf("Results of pass by value: a = %d, b = %d\n",a,b);

  swap_pass_by_address(&a, &b);
  printf("Results of pass by address: a = %d, b = %d\n",a,b);

  // call by reference only available in C++
  
  return 0;
}
