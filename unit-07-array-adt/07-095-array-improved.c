/*
Asks for an array size, length, and elements.
Then prints those elements.

No check to see if size > length; this could cause memory allocation
problems!
*/

#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;    /* capacity */
    int length;  /* number of used elements */
};

void display(const struct Array *arr)
{
    printf("Elements are:\n");
    for (int i = 0; i < arr->length; i++) {
        printf("%d ", arr->A[i]);
    }
    printf("\n\n");
}

int main(void)
{
    struct Array arr = {0};
    int n = 0;

    printf("Enter size of an array: ");
    if (scanf("%d", &arr.size) != 1 || arr.size <= 0) {
        fprintf(stderr, "Error: invalid array size.\n");
        return 1;
    }

    arr.A = malloc((size_t)arr.size * sizeof *arr.A);
    if (arr.A == NULL) {
        fprintf(stderr, "Error: malloc failed.\n");
        return 1;
    }

    arr.length = 0;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > arr.size) {
        fprintf(stderr, "Error: number of elements must be between 0 and %d.\n", arr.size);
        free(arr.A);
        return 1;
    }

    printf("Enter all elements: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr.A[i]) != 1) {
            fprintf(stderr, "Error: invalid integer input.\n");
            free(arr.A);
            return 1;
        }
    }
    arr.length = n;

    display(&arr);

    free(arr.A);
    return 0;
}
