#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int a = 10; // consumes 4 bytes
    int *p; // * is typically used at declaration and dereferencing
    p = &a;
    // *p = &a; // will not work
    cout<<"variable a = "<<a<<endl;
    printf("star p = %d\n",*p);  // this is dereferencing
    printf("plain p = %d\n",p);
    printf("Ampersand a = %d\n",&a);
}