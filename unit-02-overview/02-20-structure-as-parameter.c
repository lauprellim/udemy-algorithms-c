#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
  int length;
  int breadth;
};

// call by value only changes LOCAL variables in struct
void fun_value(struct Rectangle r) {
  r.length = 20;
  r.breadth = 10;
  printf("Call by Value Results:\n");
  printf("Length (fun): %d\nBreadth (fun): %d\n", r.length, r.breadth);
}

// call by address changes global variables in struct
void fun_address(struct Rectangle *p) {
  p->length = 40;
  p->breadth = 149;
  printf("Call by Address Results:\n");
  printf("Length (fun): %d\nBreadth (fun): %d\n", p->length, p->breadth);
}

int main() {
  struct Rectangle r={10,5};
  fun_value(r);
	   
  printf("Length (main): %d \nBreadth (main): %d\n", r.length, r.breadth);

  fun_address(&r);

  printf("Length (main): %d \nBreadth (main): %d\n", r.length, r.breadth);
  
  return 0;
}
