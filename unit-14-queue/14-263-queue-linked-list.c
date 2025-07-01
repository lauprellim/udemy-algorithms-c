/* implementation of a queue using linked list
   Fixed a problem in the display func: we must
   initially point p on front or else we get some
   bad stuff!
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
}*front = NULL, *rear = NULL;

void enqueue(int x){
  // make sure there is enough space inside heap memory
  struct Node *t;
  t = (struct Node*)malloc(sizeof(struct Node));
  if(t == NULL) printf("Queue is full...\n");
  else {
    t->data = x;
    // this will be last node initially
    t->next = NULL;
    // if this IS the first node,
    if(front == NULL) front = rear = t;
    // otherwise this is NOT the first node...
    else {
      rear->next = t;
      rear = t;
    }
  }
}

int dequeue(){
  int x = -1;
  struct Node* t;
  
  if(front==NULL) printf("Queue is empty...\n");
  else {
    x = front->data;
    t = front;
    front = front->next;
    free(t);
  }
  return x;
}

void display(){
  struct Node *p;
  p = front;
  while(p){
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

int main(){
  enqueue(10);
  display();
  enqueue(20);
  display();
  enqueue(30);
  display();
  enqueue(40);
  display();
  enqueue(50);
  display();
  printf("Dequeued element is %d.\n", dequeue());
  display();
  printf("Dequeued element is %d.\n", dequeue());
  display();
  
  return 0;
}
