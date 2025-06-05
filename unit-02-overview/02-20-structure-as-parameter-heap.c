#include<stdio.h>
#include<stdlib.h>

struct Rectangle {
  int length;
  int breadth;
};

struct Rectangle *fun() {
  struct Rectangle *p;
  // in c++ you can simply do this:
  // p = new Rectangle;
  p=(struct Rectangle *)malloc(sizeof(struct Rectangle));
  p->length = 15;
  p->breadth = 7;
  return p;
}

int main() {
  // don't have to pass any parameters
  // creating an object and returning its address
  struct Rectangle *ptr = fun();
  printf("Length: %d\nBreadth: %d\n", ptr->length, ptr->breadth);
  return 0;
}
