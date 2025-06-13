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

int get(struct Array arr, int index) {
  // check if index is valid or not
  if (index>=0 && index<arr.length) return arr.A[index];
  return -1;
}

int set(struct Array *arr, int index, int x) {
  // check if index is valid
  if(index>=0 && index<arr->length) {
    arr->A[index] = x;
    return 1;
  }
  return -1;
}

int max(struct Array arr) {
  int max = arr.A[0];
  int i;
  for(i=1; i<arr.length; i++) if(arr.A[i]>max) max = arr.A[i];
  return max;
}

int min(struct Array arr) {
  int min = arr.A[0];
  int i;
  for(i=1; i<arr.length; i++) if(arr.A[i]<min) min = arr.A[i];
  return min;
}

int sum(struct Array arr) {
  int s=0;
  int i;
  for(i=0;i<arr.length;i++) s+=arr.A[i];
  return s;
}

float avg(struct Array arr) {
  return (float)sum(arr)/arr.length;
}

void reverse(struct Array *arr) {
  // make auxilliary array
  int *B;
  int i,j;

  B = (int *)malloc(arr->length * sizeof(int));
  // copy all the elements from A to B in reverse order
  for( i = arr->length - 1, j = 0; i >= 0; i--, j++ ) B[j] = arr->A[i];
  // copy all the elements from B to A.
  for( i = 0; i < arr->length; i++ ) arr->A[i] = B[i];
  // deallocate B
  free(B);
}

void reverse2(struct Array *arr) {
  // we have already written a swap method
  int i, j;
  for( i = 0, j = arr->length-1; i < j; i++, j--) swap(&arr->A[i],&arr->A[j]);
}

// insert element in sorted array
void insertSorted(struct Array *arr, int x) {
  // shift elements from right side of array until you find the right place
  // check if there is any free space in the array first
  if(arr->length == arr->size) return;

  int i = arr->length-1;
  // move all the larger elements over to the right one index number
  while(i >= 0 && arr->A[i] > x) {
    arr->A[i+1] = arr->A[i];
    i--;
  }
  // insert the new element
  arr->A[i+1] = x;
  // increment length of array
  arr->length++;
}

// check to see if an array is sorted, or not
int isSorted(struct Array arr) {
  int i;
  // if it is not sorted, return 0.
  for( i = 0; i < arr.length-1; i++ ) if(arr.A[i] > arr.A[i+1]) return 0;
  return 1;
}

// rearrange elements in an array, such that all negative elements are
// on the left, and all positive elements are on the right. This is a kind
// of "partial sort".
void rearrangeNegPos(struct Array *arr) {
  // i counter will start from index 0, j counter starts from last index
  // they will converge when negative numbers are on left side, and positive
  // numbers are on right side.
  int i, j;
  i = 0;
  j = arr->length-1;
  while (i < j) {
    while (arr->A[i] < 0) i++;
    while (arr->A[j] >= 0) j--;
    if (i < j) swap(&arr->A[i], &arr->A[j]);
  }
}

// merge function
// we are going to return a pointer to an array
struct Array* merge(struct Array *arrFirst, struct Array *arrSecond) {
  // don't need to pass the third array
  int i, j, k;
  i = j = k = 0;
  // we will be returning this array
  struct Array *arrMerged = (struct Array *)malloc(sizeof(struct Array));

  while ( i < arrFirst->length && j < arrSecond->length) {
    // if array 1's element is less than array 2's element,
    // then we should set array 3's element to that one.
    // and i, k shuold increment
    if(arrFirst->A[i] < arrSecond->A[j]) arrMerged->A[k++] = arrFirst->A[i++];
    // otherwise use the element from the second array.
    else arrMerged->A[k++] = arrSecond->A[j++];
  }
  // what about the remaining elements of the first or second array?
  // simply copy them to the third array, one by one
  for(; i < arrFirst->length; i++) arrMerged->A[k++] = arrFirst->A[i];
  for(; j < arrSecond->length; j++) arrMerged->A[k++] = arrSecond->A[j];
  // set arrayMerged's length and size
  arrMerged->length = arrFirst->length + arrSecond->length;
  arrMerged->size = 10;

  // since this is in heap memory, we can return
  return arrMerged;
}

// union function
// we are going to return a pointer to an array
struct Array* unionFunc(struct Array *arrFirst, struct Array *arrSecond) {
  // don't need to pass the third array
  int i, j, k;
  i = j = k = 0;
  // we will be returning this array
  struct Array *arrUnion = (struct Array *)malloc(sizeof(struct Array));

  // move pointers in the arrays and put an element into Union array if the two
  // values are equal.
  while ( i < arrFirst->length && j < arrSecond->length) {
    if(arrFirst->A[i] < arrSecond->A[j]) arrUnion->A[k++] = arrFirst->A[i++];
    else if(arrSecond->A[j] < arrFirst->A[i]) arrUnion->A[k++] = arrSecond->A[j++];
    else {
      arrUnion->A[k++] = arrFirst->A[i++];
      j++;
    }
  }
  // what about the remaining elements of the first or second array?
  // simply copy them to the third array, one by one
  for(; i < arrFirst->length; i++) arrUnion->A[k++] = arrFirst->A[i];
  for(; j < arrSecond->length; j++) arrUnion->A[k++] = arrSecond->A[j];
  // set arrayUnion's length and size
  arrUnion->length = k;
  arrUnion->size = 10;

  // since this is in heap memory, we can return
  return arrUnion;
}

// intersection function
// we are going to return a pointer to an array
struct Array* intersection(struct Array *arrFirst, struct Array *arrSecond) {
  int i, j, k;
  i = j = k = 0;
  // we will be returning this array
  struct Array *arrIntersection = (struct Array *)malloc(sizeof(struct Array));

  // move pointers in the arrays, check values
  while ( i < arrFirst->length && j < arrSecond->length) {
    if(arrFirst->A[i] < arrSecond->A[j]) i++;
    else if(arrSecond->A[j] < arrFirst->A[i]) j++;
    else if(arrFirst->A[i] == arrSecond->A[j]) {
      arrIntersection->A[k++] = arrFirst->A[i++];
      j++;
    }
  }
  // no need to check for remaining elements
  // set arrayIntersection's length and size
  arrIntersection->length = k;
  arrIntersection->size = 10;

  // since this is in heap memory, we can return
  return arrIntersection;
}

// difference function
struct Array* difference(struct Array *arrFirst, struct Array *arrSecond) {
  int i, j, k;
  i = j = k = 0;
  // we will be returning this array
  struct Array *arrDifference = (struct Array *)malloc(sizeof(struct Array));

  // move pointers in the arrays and put an element into Union array if the two
  // values are equal.
  while ( i < arrFirst->length && j < arrSecond->length) {
    if(arrFirst->A[i] < arrSecond->A[j]) arrDifference->A[k++] = arrFirst->A[i++];
    else if(arrSecond->A[j] < arrFirst->A[i]) j++;
    else {
      i++;
      j++;
    }
  }
  // what about the remaining elements of the first or second array?
  // simply copy them to the third array, one by one
  for(; i < arrFirst->length; i++) arrDifference->A[k++] = arrFirst->A[i];
  // set arrayUnion's length and size
  arrDifference->length = k;
  arrDifference->size = 10;

  // since this is in heap memory, we can return
  return arrDifference;
}


//----------------------------------------------------

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

  printf("  Getting element 2: %d\n", get(arr1, 2));
  printf("  Setting element 2 to 444.\n");
  set(&arr1, 2, 444);
  printf("  Getting element 2: %d\n", get(arr1, 2));  
  printf("  Sum of elements in array: %d\n", sum(arr1));
  printf("  Average of all elements: %f\n", avg(arr1));

  display(arr1);
  reverse(&arr1);
  display(arr1);
  reverse2(&arr1);
  display(arr1);

  struct Array arr2 = {{2,3,5,10,15},10,5};

  display(arr2);
  insertSorted(&arr2, 20);
  insertSorted(&arr2, -3);
  display(arr2);

  printf("  Is arr sorted? %d\n", isSorted(arr));
  printf("  Is arr1 sorted? %d\n", isSorted(arr1));
  printf("  Is arr2 sorted? %d\n", isSorted(arr2));

  struct Array arr3 = {{6,-3,8,-22, 145,-1, 1, 2, -2},10,9};
  display(arr3);
  rearrangeNegPos(&arr3);
  printf("After rearranging arr3:\n");
  display(arr3);

  // merging arrays
  printf("  We are merging these arrays.\n");
  struct Array arr4 = {{2, 6, 10, 15, 25}, 10, 5};
  struct Array arr5= {{3, 4, 7, 18, 20}, 10, 5};
  struct Array *arr6;

  arr6 = merge(&arr4, &arr5);
  display(arr4);
  display(arr5);
  display(*arr6);

  // union, intersection
  struct Array arr7 = {{2,6,10,15,25},10,5};
  struct Array arr8 = {{3,6,7,15,20},10,5};
  struct Array *arr9;

  printf("    The next few functions take these two arrays:\n");
  display(arr7);
  display(arr8);
  printf("  Finding union of these two arrays.\n");
  arr9 = unionFunc(&arr7, &arr8);
  display(*arr9);

  printf("  Finding intersection of these two arrays.\n");
  struct Array *arr10;
  arr10 = intersection(&arr7, &arr8);
  display(*arr10);

  printf("  Finding difference of these two arrays.\n");
  struct Array *arr11;
  arr11 = difference(&arr7, &arr8);
  display(*arr11);
  
  return 0;
}
