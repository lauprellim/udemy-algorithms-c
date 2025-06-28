// implementation of stack using a linked list

#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
  // though not recommended,
  // as before make global variable top pointer
}*top = NULL;

void push(int x){
  struct Node *t;
  t = (struct Node* )malloc(sizeof(struct Node));
  // in the unlikely circumstance that the heap memory is full:
  if(!t) printf("Stack is full!\n");
  else {
    t->data = x;
    t->next = top;
    top = t;   
  }
}

int pop(){
  struct Node *t;
  int x = -1;
  
  // check if stack is empty
  if(!top) printf("Stack is empty.\n");
  else {
    t = top;
    top = top->next;
    x = t->data;
    free(t);
  }
  return x;
}

void display(){
  struct Node *p;
  p = top;
  printf("TOP -> ");
  while(p){
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}


int main(){
  // top is already declared as a global variable
  push(10);
  push(20);
  push(30);
  push(40);

  display();

  printf("Popping value %d.\n", pop());

  display();
  
  return 0;
}
