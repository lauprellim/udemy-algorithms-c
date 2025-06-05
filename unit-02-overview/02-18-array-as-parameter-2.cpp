#include<iostream>
using namespace std;

// this function creates the array and inits all the elements
int * fun(int size) {
  int *p;
  p=new int[size];

  for(int i=0; i<size; i++) {
    p[i] = i+1;
  }
  return p;
}

int main() {
  // there is no array created in main()
  // try changing sz...
  int *ptr, sz = 21;

  ptr = fun(sz);

  for(int i=0; i<sz; i++) {
    cout<<ptr[i]<<" ";
  }
  cout<<endl;

  
  return 0;
}
