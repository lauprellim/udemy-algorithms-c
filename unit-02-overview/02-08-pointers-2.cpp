#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int A[5] = {2,4,6,8,10};
    int *p;
    p = A;  // don't have to give ampersand when you give array name to pointer
            // because name of an array A itself is the starting address of array
    // p = &A[0]; // this would also be OK
    for(int i=0; i<5; i++) {
        cout<<"Accessing directly: "<<A[i]<<" ";
        cout<<endl;
        cout<<"Accessing by pointer: "<<p[i]<<" ";
        cout<<endl;
    }
    return 0;
}