/* implementation of stack using a linked list
   this also checks to see if parenthesis are matching
   in a character string.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
  char data;
  struct Node *next;
  // though not recommended,
  // as before make global variable top pointer
}*top = NULL;

void push(char x){
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

char pop(){
  struct Node *t;
  char x = -1;
  
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

// returns true or false depending on whether parenthesis are balanced
int isBalanced(char *expr){
  int i;

  for(i=0; expr[i] != '\0'; i++){
    display();
    if(expr[i] == '(') push(expr[i]);
    else if(expr[i] == ')'){
      // check if stack is empty
      if(top == NULL) return 0;
      pop();
    }
  }
  // check if stack is empty
  if(top == NULL) return 1;
  else return 0;
}


int main(){

  // char *expr1 = "((a+b)*(c-d))";
  // char *expr2 = "(((a+b)*(c-d))";
  char *expr3 = "((a+b)*(c-d)))";
  
  // printf("Is expr1 %s balanced? -> %d\n", expr1, isBalanced(expr1));
  // printf("Is expr2 %s balanced? -> %d\n", expr2, isBalanced(expr2));
  printf("Is expr3 %s balanced? -> %d\n", expr3, isBalanced(expr3));

  return 0;
}
