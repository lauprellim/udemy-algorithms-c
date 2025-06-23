#include<stdio.h>
#include<stdlib.h>
#include<limits.h> // this is for getting INT_MIN

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
  // this could also be while(p != NULL)
  // whether you use a loop or do this recursively,
  // time is O(n), but recursion use O(n) space.
  while(p){
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

void displayRec(struct Node *p) {
  if(p!=NULL) {
    // if you reverse the next two lines, the recursive
    // function will print the elements of the ll in reverse...
    printf("%d ", p->data);
    displayRec(p->next);
  }
  // put one blank line at end
  else printf("\n");
}

int count(struct Node *p) {
  int l = 0;
  while(p){
    l++;
    p = p->next;
  }
  return l;
}

int countRec(struct Node *p) {
  // don't do 1 + countRec(p->next)
  if(p) return countRec(p->next) + 1;
  else return 0;
}

int sum(struct Node *p){
  int s = 0;
  while(p){
    s+=p->data;
    p=p->next;
  }
  return s;
}

int sumRec(struct Node *p){
  if(!p) return 0;
  // again be sure you sum AFTER recursive call.
  return sumRec(p->next) + p->data;
}

int maximum(struct Node *p) {
  int max = INT_MIN;
  while(p) {
    if(p->data > max) max = p->data;
    p = p->next;
  }
  return max;
}

int maximumRec(struct Node *p){
  int x;
  // if we have reached the last node:
  if(p==0) return INT_MIN;
  x = maximumRec(p->next);
  /* you could do it this way...
  if(x > p->data) return x;
  else return p->data;
  */
  /* or much more fun, with ternary operator: */
  return x > p->data ? x : p->data;
}

int main() {
  int A[] = {3, 5, 7, 10, 15, 8, 12, 20};
  // create a ll using these elements
  create(A, 8);

  display(first);
  displayRec(first);

  printf("Length of linked list (iterative): %d\n", count(first));
  printf("Length of linked list (recursive): %d\n", countRec(first));
  printf("Sum of elements in ll (iterative): %d\n", sum(first));
  printf("Sum of elements in ll (recursive): %d\n", sumRec(first));
  printf("Maximum element in ll (iterative): %d\n", maximum(first));
  printf("Maximum element in ll (recursive): %d\n", maximumRec(first));
  
  return 0;
}
