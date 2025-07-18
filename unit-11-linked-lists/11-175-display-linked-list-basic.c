#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
  // use global pointer below
}*first = NULL;

void create(int A[], int n) {
  int i;
  struct Node *t, *last;

  // create first element of the linked list
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++){
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

void display(struct Node *p) {
  while(p){
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

int main() {

  int A[] = {3, 5, 7, 10, 15};
  // create a ll using these elements
  create(A, 5);

  display(first);
  
  return 0;
}
