#include <stdio.h>
#include <stdlib.h>

struct Array {
  int A[10];
  int size;     // the total size of the array
  int length;   // the number of elements used in the array
};

// display all the elements of the array
void display(struct Array arr)
{
  int i;
  printf("Elements are: [ ");
  for(i=0; i<arr.length; i++) printf("%d ", arr.A[i]);
  printf("]\n");
}

// call by address type, it will modify arr. x is value to insert
void append(struct Array *arr, int x) {
  if (arr->length < arr->size) arr->A[arr->length++] = x;
}

void insert(struct Array *arr, int index, int x) {
  // check if index is valid or not
  int i;
  if(index >= 0 && index <= arr->length) {
    // move all the elements AFTER the desired insertion index
    for (i = arr->length; i > index; i--) arr->A[i] = arr->A[i-1];
    // insert the new element into the array
    arr->A[index] = x;
    // increment the length of the array
    arr->length++;
  }
}

int main() {
  // directly set the parameters
  struct Array arr = {{1,2,3,4,5}, 10, 5};

  display(arr);
  append(&arr, 99);
  display(arr);
  insert(&arr, 3, 999);
  display(arr);
  
  return 0;
}
