#include<stdio.h>

struct Rectangle {
  int length;
  int breadth;
};

void changeLength(struct Rectangle *p, int l) {
  p->length = l;
}

void main() {
  struct Rectangle r={10,5};
  printf("Original dimensions: %d, %d\n", r.length, r.breadth);
  changeLength(&r, 20);
  printf("New dimensions: %d, %d\n", r.length, r.breadth); 
}
