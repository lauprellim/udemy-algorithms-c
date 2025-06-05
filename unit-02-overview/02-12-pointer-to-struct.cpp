#include<iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    Rectangle r={10,5};
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;

    Rectangle *p=&r;
    // dot operator cannot be used. use arrow instead!
    cout<<p->length<<endl;
    cout<<p->breadth<<endl;

    return 0;
}