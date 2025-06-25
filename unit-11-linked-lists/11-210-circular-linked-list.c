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

int main(){

  int A[] = {2, 3, 4, 6, 10};
  create(A,5);
  printf("Displaying circular linked list using do-while loop: ");
  display(head);

  printf("\nDisplaying circular linked list using recursive function: ");
  displayRec(head);

  printf("\n");
  
  return 0;
}
