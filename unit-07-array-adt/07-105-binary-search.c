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
  int i;
  // check if index is valid or not
  if(index >= 0 && index <= arr->length) {
    // move all the elements AFTER the desired insertion index
    for (i = arr->length; i > index; i--) arr->A[i] = arr->A[i-1];
    // insert the new element into the array
    arr->A[index] = x;
    // increment the length of the array
    arr->length++;
  }
}

// this will return the value of the deleted element
// and update the array
int delete(struct Array *arr, int index) {
  // this is the deleted value
  int x = 0;
  int i;
  // check to see if index is valid or not
  if(index >= 0 && index < arr->length) {
    // get the value at the index to be deleted
    x = arr->A[index];
    // shift all the elements to the left
    for(i = index; i < arr->length-1; i++) arr->A[i] = arr->A[i+1];
    // decrement length of array
    arr->length--;
    return x;
  }
  return -1;
}

void swap(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

// pass by value -- we do not modidy the array at all
int linearSearch1(struct Array arr, int key) {
  int i;
  for(i = 0; i < arr.length; i++) if (key == arr.A[i]) return i;
  return -1;
}

// pass by reference -- we will swap elements
// this just moves the found element one element further towards the head
int linearSearch2(struct Array *arr, int key) {
  int i;
  for(i = 0; i < arr->length; i++) {
    if (key == arr->A[i]) {
      swap(&arr->A[i], &arr->A[i-1]);
      return i;
    }
  }
  return -1;
}

// pass by reference -- we will swap elements
// this moves the found element all the way to the head of the array
int linearSearch3(struct Array *arr, int key) {
  int i;
  for(i = 0; i < arr->length; i++) {
    if (key == arr->A[i]) {
      swap(&arr->A[i], &arr->A[0]);
      return i;
    }
  }
  return -1;
}

// binary search, iterative version
int binarySearchIt(struct Array arr, int key) {
  int l, mid, h;
  l = 0;
  h = arr.length-1;

  while(l<=h) {
    mid = ( l + h ) / 2;
    if(key == arr.A[mid]) return mid;
    else if(key < arr.A[mid]) h = mid - 1;
    else l = mid + 1;
  }
  return -1;
}

// binary search, recursive version
int binarySearchRec(int a[], int l, int h, int key) {
  int mid;
  if (l<=h) {
    mid = ( l + h ) / 2;
    if(key == a[mid]) return mid;
    else if(key < a[mid]) return binarySearchRec(a, l, mid-1, key);
    else return binarySearchRec(a, mid+1, h, key);
  }  
  return -1;
}

int main() {
  // directly set the parameters
  struct Array arr = {{1,2,3,4,5}, 10, 5};

  display(arr);
  append(&arr, 99);
  display(arr);
  insert(&arr, 3, 999);
  display(arr);
  printf("  Deleted %d\n", delete(&arr, 4));
  display(arr);
  printf("  Deleted %d\n", delete(&arr, 1));
  display(arr);
  printf("  Using LS1, found value 999 at address %d\n", linearSearch1(arr, 999));
  printf("  Using LS1, found value 15 at address %d\n", linearSearch1(arr, 15));
  printf("  Using LS2, found value 999 at address %d\n", linearSearch2(&arr, 999));
  display(arr);
  printf("  Using LS3, found value 99 at address %d\n", linearSearch3(&arr, 99));
  display(arr);

  struct Array arr1 = {{2,4,5,7,8,9,12,13}, 10, 8};

  display(arr1);

  printf("  Using binarySearchIt, found value 12 at address %d\n", binarySearchIt(arr1, 12));
  printf("  Using binarySearchIt, found value 99 at address %d\n", binarySearchIt(arr1, 99));
  printf("  Using binarySearchRec, found value 4 at address %d\n", binarySearchRec(arr1.A, 0, arr1.length, 4));
  printf("  Using binarySearchRec, found value 99 at address %d\n", binarySearchRec(arr1.A, 0, arr1.length, 99));
  
  return 0;
}
