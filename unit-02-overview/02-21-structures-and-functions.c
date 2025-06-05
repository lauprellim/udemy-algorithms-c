#include<stdio.h>
#include<stdlib.h>

struct Rectangle {
  int length;
  int breadth;
};

// call by address
void init(struct Rectangle *r, int l, int b) {
  r->length=l;
  r->breadth=b;
}

// this is call by value
int area(struct Rectangle r) {
  return r.length*r.breadth;
}

// this is call by address
void changeLength(struct Rectangle *r, int l) {
  r->length=l;
}


int main() {
  struct Rectangle r;
  init(&r, 10, 5);
  printf("Area of 10, 5: %d\n", area(r));
  changeLength(&r, 20);
  area(r);
  printf("Area of 20, 5: %d\n", area(r));
  return 0;
}
