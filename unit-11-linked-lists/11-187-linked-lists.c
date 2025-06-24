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

// linear search on a linked list
// will return a pointer on the found element
// we will also do "move-to-front" operation.
struct Node * linearSearch(struct Node *p, int key) {
  // this is the tail pointer; initialize to null
  struct Node *q = NULL;
  
  while(p){
    // if the element is found
    if(key == p->data) {
      // make this found element the FIRST element of the ll
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    // move q pointer up to p pointer
    q = p;
    // go to the next element
    p = p->next;
  }
  // if the element is not found
  return NULL;
}

// now do a linear search recursively...
struct Node * linearSearchRec(struct Node *p, int key){
  if(p==NULL) return NULL;
  if(key == p->data) return p;
  return linearSearchRec(p->next, key);
}

// insert a node. index is the index point, x is the data
void insert(struct Node *p, int index, int x){
  // check if index is valid; if it is less than 0 or greater
  // than the length of the ll, it is invalid
  if(index < 0 || index > count(p)) return;

  // we can insert a new node. first create a new node
  struct Node *t;
  int i; // iterator for counting below
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;

  // if index is 0, insert it at the front of the ll
  if(index == 0) {
    // this new node's pointer should be the firs
    t->next = first;
    first = t;
  }
  else {
    // move pointer p to the entry point
    for(i=0; i<index-1; i++) p = p->next;
    // make t's next pointer the pointer of the current element
    t->next = p->next;
    // make p's pointer t
    p->next = t;
  }
}

/*------------------------------------*/

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

  printf("\n");

  printf("Iterative search on 99:\n");
  struct Node *temp;
  temp = linearSearch(first,99);
  if(temp) printf("Key %d is found.\n", temp->data);
  else printf("Key not found...\n");
  
  printf("Recursive search on 12:\n");
  temp = linearSearchRec(first, 12);
  if(temp) printf("Key %d is found.\n", temp->data);
  else printf("Key not found...\n");  

  printf("Iterative search on 12:\n");
  temp = linearSearch(first, 12);
  if(temp) printf("Key %d is found.\n", temp->data);
  display(temp);

  printf("Iterative search on 15:\n");
  temp = linearSearch(first, 15);
  if(temp) printf("Key %d is found.\n", temp->data);
  display(temp);

  // insertion
  printf("\n");
  insert(first, 0, 99);
  display(first);
  insert(first, 4, 999);
  display(first);
  
  return 0;
}
