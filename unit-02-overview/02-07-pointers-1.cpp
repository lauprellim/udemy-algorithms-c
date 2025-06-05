#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *p;
    p = &a;
    cout<<"data variable a = "<<a<<endl;
    cout<<"address variable a = "<<p<<endl;

    return 0;
}