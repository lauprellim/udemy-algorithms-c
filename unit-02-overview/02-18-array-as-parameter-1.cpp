#include <iostream>
using namespace std;

// I can use square brackets...
// void fun(int A[], int n) {

// or *...
void fun(int *A, int n) {
  // this returns 2, which is NOT the size of the array
  // rather 8 / 4, which is the size of the POINTER
  // 8 is the size of the pointer, and 4 is the size of an integer
  // All of this is to say that arrays are always passed by address,
  // arrays are NOT passed by value.
  cout<<"Size of array A: "<<sizeof(A)/sizeof(int)<<endl;

  // foreach loop will not work on a pointer:
  // for(int a:A)
  // cout<<a<<" "<<endl;

  // I can change elements of the array because it's being passed as a pointer:
  A[0] = 15;

  cout<<"Displaying array contents using for loop inside fun(): "<<endl;
  for(int i=0; i<n;i++) {
    cout<<A[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  int A[]={2,4,6,8,10};
  // n is the number of elements in the array
  int n=5;

  fun(A, n);
  cout<<"Actual size of Array A: "<<sizeof(A)/sizeof(int)<<endl;
  
  for(int x:A) {
    cout<<x<<" ";
  }

  cout<<endl;
  
  return 0;
}
