/* implements a stack using an array which
   is dynamically allocated at runtime.
   peek() position 1 is always top of stack: top-position+1.
*/

#include<stdio.h>
#include<stdlib.h>

struct stack{
  int size;
  int top;
  int *s;
};

void create(struct stack *st){
  printf("Enter size of stack: ");
  scanf("%d", &st->size);
  // -1 means the stack is empty
  st->top = -1;
  st->s = (int *)malloc(st->size*sizeof(int));
}

void display(struct stack st){
  int i;
  printf("TOP -> ");
  for(i=st.top; i>=0; i--) printf("%d ", st.s[i]);
  printf("\n");
}

void push(struct stack *st, int x){
  // check if there is space in stack
  if(st->top == st->size-1) printf("Stack overflow.\n");
  else {
    st->top++;
    st->s[st->top] = x;
  }
}

int pop(struct stack *st){
  int x = -1;
  // check if stack is empty
  if(st->top == -1) printf("Stack underflow.\n");
  else{
    // get the desired value, decrement top pointer
    x = st->s[st->top--];
  }
  return x;
}

int peek(struct stack st, int index){
  int x = -1;
  // is index valid?
  if(st.top - index + 1 < 0) {
    printf("Invalid index. \n");
    return -1;
  }
  else {
    x = st.s[st.top - index + 1];
    return x;
  }
}

int isEmpty(struct stack st){
  if(st.top -- -1) return 1;
  return 0;
}

int isFull(struct stack st){
  return st.top == st.size - 1;
}

int stackTop(struct stack st){
  // returns topmost element in stack
  if(!isEmpty(st)) return st.s[st.top];
  return -1;
}
  
int main() {
  struct stack st;
  create(&st);

  push(&st, 10);
  push(&st, 20);
  push(&st, 30);
  push(&st, 40);
  push(&st, 50);
  
  printf("Popping value %d \n", pop(&st));
  // printf("Popping value %d \n", pop(&st));

  printf("Peeking value 2: %d \n", peek(st, 2));
  
  display(st);

  return 0;
}
