#include<iostream>
using namespace std;

int main() {
    int a = 10;
    int &r = a; // declaring a reference -- must be initialized
    r = 25; // reference doesn't consume memory. a and r are the same.
            // pointers DO consume memory.

    int b = 30;
    r = b;      // this changes a also!

    cout<<"a = "<<a<<endl<<"r = "<<r<<endl;

    return 0;
}