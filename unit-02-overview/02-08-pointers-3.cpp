#include <stdio.h>
#include<stdlib.h>
using namespace std;

int main() {
    int *p;
    p = (int *)malloc(5*sizeof(int));

    p[0]=10; p[1]=15; p[2]=13; p[3]=12; p[4]=128;

    for(int i=0; i<5; i++) {
        printf("%d  ",p[i]);
    }
    free(p);
    return 0;
}