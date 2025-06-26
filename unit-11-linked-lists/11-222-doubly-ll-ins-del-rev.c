#include<stdio.h>
#include<stdlib.h>

struct Node {
  struct Node *prev;
  int data;
  struct Node *next;
}*first = NULL;

void create(int A[], int n) {
  struct Node *t, *last;
  int i;

  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = A[0];
  first->prev = first->next = NULL;
  last = first;

  // create the rest of the nodes
  for(i = 1; i<n; i++) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = last->next;
    t->prev = last;
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

int length(struct Node *p) {
  int len=0;
  while(p){
    len++;
    p = p->next;
  }
  return len;
}

void insert(struct Node *p, int index, int x){
  struct Node *t;
  int i;

  // check if index is value
  if(index < 0 || index > length(p)) return;

  // if the new node is before first node:
  if(index == 0) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->prev = NULL;
    t->next = first;
    first->prev = t;
    first = t;
  }
  else {
    // node is inserted at any other position
    for(i=0; i<index-1; i++) p = p->next;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    // need to do four things to set links:
    t->prev = p;
    t->next = p->next;
    // if t's next node is there (i.e., it is not null):
    if(p->next) p->next->prev = t;
    p->next = t;
  }
}

int delete(struct Node *p, int index){
  int x = -1, i;

  // check
  if(index < 1 || index > length(p)) return -1;

  // delete first node
  if(index == 1){
    first = first->next;
    if(first) first->prev = NULL;
    x = p->data;
    free(p);
  }
  else {
    for(i=0; i<index-1; i++) p = p->next;
    // modify node structure
    p->prev->next = p->next;
    // if there IS a next node...
    if(p->next) p->next->prev = p->prev;
    x = p->data;
    free(p);
  }
  return x;
}

/* To reverse the doubly ll, all you need to do
   is swap the pointers next and prev!
   You also have to make sure that first is pointing
   on the correct node. This is easy to do, just check
   if p->next == NULL.
*/

void reverse(struct Node *p){
  struct Node *t;

  while(p){
    // swap pointers in each node
    t = p->next;
    p->next = p->prev;
    p->prev = t;
    // advance to the next node
    p = p->prev;
    // is this the last node?
    if(p != NULL && p->next == NULL) first = p;
  }
}



// ----------------------------------------

int main() {
  int A[] = {3, 9, 12, 15, 18, 21};
  create(A, 6);
  printf("Length is: %d\n", length(first));
  display(first);

  insert(first, 2, 99);
  printf("Inserting 99 at node 2: \n");
  display(first);

  insert(first, 0, 98);
  printf("Inserting 98 at node 0: \n");
  display(first);

  printf("Deleting first node. Data is: %d\n", delete(first, 1));
  display(first);

  printf("Deleting seventh node (last node). Data is: %d\n", delete(first, 7));
  display(first);

  printf("Deleting third node. Data is: %d\n", delete(first, 3));
  display(first);

  printf("Reversing the ll.\n");
  reverse(first);
  display(first);
  return 0;
}
