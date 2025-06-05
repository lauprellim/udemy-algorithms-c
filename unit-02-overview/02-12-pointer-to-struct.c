#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    struct Rectangle *p;
    // typecast as struct Rectangle
    p=(struct Rectangle *)malloc(sizeof(struct Rectangle));

    p->length=15;
    p->breadth=7;

    printf("length = %d\n", p->length);
    printf("breadth = %d\n", p->breadth);

    return 0;
}