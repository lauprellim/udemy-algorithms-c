#include <stdio.h>
#include <stdlib.h>

struct Array {
  int A[20];
  int size;
  int length;
};

// display all the elements of the array
void display(struct Array arr)
{
  int i;
  printf("Elements are:\n");
  for(i=0; i<arr.length; i++) printf("%d ", arr.A[i]);
  printf("\n\n");
}

int main() {
  // directly set the parameters
  struct Array arr = {{2,3,4,5,6}, 20, 5};

  display(arr);
  
  return 0;
}
