#include<stdio.h>

int fun(int n) {
    if(n>100) {
        printf("%d ",n);
        return n-10;
    }
    else {
        printf("\n    %d ",n);
        return fun(fun(n+11));
    }
}

int main() {
    int r;
    r=fun(95);
    printf("        %d ",r);
    return 0;
}