#include <iostream>
using namespace std;

int main() {
  int n;
  cout<<"Enter size: ";
  cin>>n;
  int A[n];
  A[0]=2;

  // this a foreach loop
  for(int x:A) {
    cout<<x<<" ";
  }

  cout<<endl;
  // size is 20
  cout<<sizeof(A)<<endl;
  cout<<A[8]<<endl;
  printf("%d\n",A[9]);

  return 0;
}
