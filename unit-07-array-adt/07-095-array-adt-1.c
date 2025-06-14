#include <stdio.h>
#include <stdlib.h>

struct Array {
  int *A;
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
  struct Array arr;
  int n, i;
  printf("Enter size of an array: ");
  scanf("%d", &arr.size);
  arr.A = (int *)malloc(arr.size * sizeof(int));
  arr.length = 0;

  // fill a few elements
  printf("Enter number of elements: " );
  scanf("%d", &n);

  printf("Enter all elements: ");
  for (i=0; i<n; i++) scanf("%d", &arr.A[i]);
  arr.length = n;

  display(arr);
  
  return 0;
}
