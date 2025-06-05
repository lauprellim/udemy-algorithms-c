#include <stdio.h>

// inefficient way of doing this
int power1(int m, int n) {
    if(n==0) return 1;
    else return power1(m, n-1)*m;
}

// a more efficient way of doing this
int power2(int m, int n) {
    if(n==0) return 1;
    if (n%2==0) return power2(m*m,n/2);
    return m*power2(m*m,(n-1)/2);
}

int main() {
    int r = power1(2,9);
    printf("Power1 of 2,9 = %d\n", r);
    int s = power2(2,9);
    printf("Power1 of 2,9 = %d\n", s);

    return 0;
}