#include <stdio.h>

int factorial(int n) {
    if(n == 0) return 1;
    else return factorial(n-1)*n;
}

int main() {
    // don't use a negative number here unless
    // you make condition above n<=0
    int r;
    r = factorial(5);
    printf("%d ",r);
    return 0;
}