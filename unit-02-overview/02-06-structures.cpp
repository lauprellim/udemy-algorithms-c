#include <stdio.h>
#include <iostream>
using namespace std;

struct Rectangle {
    int length; // 4 bytes
    int breadth; // 4 bytes
    char x; // uses only 1 byte but allocates 4 bytes
};

int main() {
    struct Rectangle r1={10,5};
    // this will print 8, because int is 4 bytes. Could also use %d
    printf("%lu\n", sizeof(r1));
    cout<<r1.length<<" "<<r1.breadth<<endl;
    r1.length=15;
    r1.breadth=10;
    cout<<r1.length<<" "<<r1.breadth<<endl;
    printf("Color %s, Integer %d, Float %3.2f\n\n", "red", 123456, 3.14);
    return 0;
}