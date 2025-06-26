#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
}*head;

void create(int A[], int n){
  int i;
  struct Node *t, *last;;
  head = (struct Node *)malloc(sizeof(struct Node));
  // this is for just the first node
  head->data = A[0];
  head->next = head; // yes
  last = head;

  // insert rest of the nodes
  for(i=1; i<n; i++) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = last->next;
    last->next = t;
    last = t;
  }
}

/* as we start traversing the circular linked list,
   the first element we encounter is head. We want to
   step through the entire cll and stop when we encounter
   head a second time. So use do-while loop...
*/
void display(struct Node *h){
  do {
    printf("%d ",h->data);
    h=h->next;
  }while(h != head);
  printf("\n");
}

/* The recursive version of display() is more complicated,
   in order to replicate the behavior of the do-while loop
   we need a flag. The flag should be static so that every
   time we call the function it accesses the same var.
*/
void displayRec(struct Node *h){
  static int flag=0;
  if(h != head || flag == 0){
    flag = 1; // this will repeatedly execute...
    printf("%d ", h->data);
    displayRec(h->next);
  }
  flag = 0;
}

int length(struct Node *p) {
  int len = 0;
  do {
    len++;
    p = p->next;
  }while(p != head);
  return len;
}

/* Inserting has two cases: inserting before head or inserting
   anywhere else. We should account for the possibility that
   this is the first node inserted into an empty ll. Another
   question is what is the status of head: if we insert before
   head, should we make the new node the head?
*/
void insert(struct Node *p, int index, int x){
  struct Node *t; // temporary
  int i;

  // check if index is valid
  if(index < 0 || index > length(head)) return;
  
  if(index == 0) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    // if there is nothing in this ll yet:
    if(head == NULL){
      head = t;
      head->next = head;
    }
    // otherwise there are some nodes already in the ll
    // we have to traverse the entire ll to get to the
    // last node. Insertion will happen after this last node.
    else {
      while(p->next != head) p = p->next;
      // insert new node
      p->next = t;
      t->next = head;
      // we will make the new node the head
      head = t;
    }
  }
    // otherwise we want to insert the node in a ll that
    // already has nodes, AND not before head. This is the
    // same prodecure for inserting in a linear linked list.
  else {
    for(i=0; i<index-1; i++) p = p->next;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = p->next;
    p->next = t;
  }
}

/* Two cases for delete: deleting head node and deleting
   any other node. If you delete the head node, some other
   node has to become head. Again, this works largly like
   a linear linked list.
   As in linear ll we'll use two pointers, p and q. We'll
   move p over to the node before deletion, and then q will
   just point on the next element (which is the element we
   want to delete).
   If we want to delete the last node, we need to move head
   additionally.
   Handle single node case specially. If we want to delete
   the second node, we need to make head point on itself --
   but this is taken care of in the code.
   We should probably return the value of the deleted node too.
*/

int delete(struct Node *p, int index){
  struct Node *q;
  int i, x;

  // check if address is valud
  if(index < 0 || index > length(head)) return -1;

  // if it is head node (we are calling the address of the
  // head node as 1, not 0):
  if(index == 1) {
    while(p->next != head) p = p->next;
    x = head->data;
    // is this the last node?
    if(head == p) {
      free(head);
      head = NULL;
    }
    else {
      p->next = head->next;
      free(head);
      head = p->next;
    }
  }
  // if index is not 1, procedure is simliar to linear ll
  else {
    // notice that we're moving to the -2 position; then
    // we can pop the q pointer onto the next node. q will
    // point on the node we actually want to delete.
    for(i=0; i< index-2; i++) p = p->next;
    q = p->next;
    p->next = q->next;
    x = q->data;
    free(q);
  }
  return x;
}


// ------------------------------

int main(){

  int A[] = {2, 3, 4, 6, 10};
  create(A,5);
  printf("Displaying circular linked list using do-while loop: ");
  display(head);

  insert(head, 2, 99);
  display(head);
  
  printf("\n");
  
  insert(head, 6, 98);
  display(head);
  insert(head, 0, 97);
  display(head);

  printf("\nValue %d deleted as position 4.\n", delete(head, 4));
  display(head);
  
  printf("\nValue %d deleted at position 1.\n", delete(head, 1));
  display(head);
  
  return 0;
}
