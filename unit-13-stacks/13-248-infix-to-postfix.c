/* implementation of stack using a linked list
   Then we use the stack to convert expression using infix notation
   (without parenthesis...) to postfix notation.
 */

#include<stdio.h>
#include<stdlib.h>
// to use strlen()
#include<string.h>

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

// helps with precedence of operators
int precedence(char x){
  if(x == '+' || x == '-') return 1;
  else if(x == '*' || x == '/') return 2;
  return 0;
}

int isOperand(char x){
  if(x == '+' || x == '-' || x == '*' || x == '/') return 0;
  else return 1;
}

char * inToPost(char *infix){
  int i=0, j=0;
  char *postfix;
  int len = strlen(infix); // should take long type
  // make the string one char longer for null termination
  // make it one char longer again to accomodate base stack symbol ('#')
  postfix = (char *)malloc((len+2)*sizeof(char));

  // use a while loop becuase we may need to dwell on a character
  // twice, in order to pop more than one element out of the stack.
  // A for loop would always increment 1.
  while(infix[i]!='\0'){
    if(isOperand(infix[i])) postfix[j++] = infix[i++];
    else {
      // check precedence
      if(precedence(infix[i]) > precedence(top->data)) push(infix[i++]);
      else postfix[j++] = pop();
    }
  }
  // we are out of the while loop now
  while (top != NULL) postfix[j++] = pop();
  postfix[j] = '\0';
  return postfix;
}



int main(){
  // take infix expression
  char *infix = "a+b*c-d/e";
  // so that stack is not empty
  push('#');
  // this wll be returned by the function
  char *postfix = inToPost(infix);

  
  printf("Infix notation: %s converts to postfix notation: %s\n", infix, postfix);
  
  
  return 0;
}
