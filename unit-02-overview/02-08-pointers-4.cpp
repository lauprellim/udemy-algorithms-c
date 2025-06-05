#include<iostream>
using namespace std;

int main() {
    int *p;
    p = new int[5];

    p[0]=10; p[1]=15; p[2]=13; p[3]=12; p[4]=128;

    for(int i=0; i<5; i++) {
        cout<<p[i]<<" ";
    }
    delete [] p;    // when dynamically allocating memory, release it when you're done
    return 0;
}