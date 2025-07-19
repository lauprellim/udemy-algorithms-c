/* this code takes care of the linked lists we need
   when coding a chained hash table.
*/
// #ifndef chains.h
// #define chains.h

// you do need this here, I think...
// ...or in main .c file?
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

void SortedInsert(struct Node **H, int x){
  struct Node *t, *q=NULL, *p = *H;

  t=(struct Node*)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;

  // if list is empty create first element
  if(*H == NULL) *H=t;
  else {
    // move p index through the linked list
    while(p && p->data<x){
      q=p;
      p=p->next;
    }
    // if we insert at the beginning of the ll
    // --- the ll which is an element in the array,
    // so POINTER!
    if(p == *H){
      t->next = *H;
      *H = t;
    }
    // if we insert anywhere else in the ll
    else {
      t->next = q->next;
      q->next = t;
    }
  }
}

struct Node *Search(struct Node *p, int key){
  while(p!=NULL){
    if(key == p->data) return p;
    p = p->next;
  }
   return NULL;

}

// #endif /* chains.h */
