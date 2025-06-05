#include <stdio.h>

int main() {
    int a = 10;
    int *p;
    p = &a;

    printf("%s %d\n", "data variable a = ", a);
    printf("%s %d\n", "ampersand a = ", &a);
    printf("%s %d\n", "p = ", p);
    printf("%s %d\n", "pointer p = ", *p);

}