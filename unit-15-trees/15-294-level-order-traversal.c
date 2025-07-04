/* Creates basic binary tree using linked list
   each node has pointers for left and right children.
   Using queue to keep track of memory addresses.

   This version includes both recursive AND iterative
   tree traversals (preorder, inorderm, postorder). The
   iterative traversals use a stack to store the
   addresses of each node that is traversed. The
   recursive traversals don't need an extra stack, of
   course!
*/

#include<stdio.h>
#include<stdlib.h>
// our custom circular queue include
#include"queue-c.h"
#include"stack-c.h"

// global variable
struct Node *root = NULL;

void treeCreate(){
  struct Node *p, *t;
  int x;
  struct Queue q;
  create(&q, 100);
  printf("Enter root value: ");
  scanf("%d", &x);
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = x;
  root->lchild = root->rchild = NULL;
  enqueue(&q, root);

  while(!isEmpty(q)) {
    p = dequeue(&q);
    printf("Enter left child of %d: ", p->data);
    scanf("%d", &x);
    if(x != -1) {
      // create a node
      t = (struct Node *)malloc(sizeof(struct Node));
      t->data = x;
      // insert as leaf node
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      enqueue(&q, t);
    }
    printf("Enter right child of %d: ", p->data);
    scanf("%d", &x);
    if(x != -1){
      t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->lchild = t->rchild = NULL;
    p->rchild = t;
    enqueue(&q, t);
    }
  }
}

// --------------------
// RECURSIVE TRAVERSALS
// --------------------

// preorder traversal
void preorder(struct Node *p){
  if(p) {
    printf("%d ", p->data);
    preorder(p->lchild);
    preorder(p->rchild);
  }
}

// inorder traversal
void inorder(struct Node *p){
  if(p) {
    inorder(p->lchild);
    printf("%d ", p->data);
    inorder(p->rchild);
  }
}

// postorder traversal
void postorder(struct Node *p){
  if(p) {
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d ", p->data);
  }
}

// --------------------
// ITERATIVE TRAVERSALS
// --------------------

void IPreorder(struct Node *p) {
  struct Stack stk;
  Stackcreate(&stk, 100);
  while(p || !isEmptyStack(stk)){
    if(p) {
      // printf goes right away, as we traverse left branch
      printf("%d ", p->data);
      push(&stk, p);
      p = p->lchild;
    }
    // when p becomes null (reaches a leaf node,)
    // go back to the last traversed node and start
    // traversing the right side.
    else {
      p = pop(&stk);
      p = p->rchild;
    }
  }
}

void IInorder(struct Node *p) {
  struct Stack stk;
  Stackcreate(&stk, 100);
  while(p || !isEmptyStack(stk)){
    if(p) {
      push(&stk, p);
      p = p->lchild;
    }
    else {
      p = pop(&stk);
      // here we printf before going to right child
      printf("%d ", p->data);
      p = p->rchild;
    }
  }
}

/*
// Post order is a littie more subtle!
// There are a couple of errors. Can long store a memory address?

void IPostorder(struct Node *p) {
  struct Stack stk;
  // extra variable for storing negative or positive address below
  long int temp;
  Stackcreate(&stk, 100);
  while(p || !isEmptyStack(stk)){
    if(p) {
      push(&stk, p);
      // here we printf before going to right child
      printf("%d ", p->data);
      p = p->lchild;
    }
    else {
      // this is the key difference -- you have to push the value
      // onto the stack ONCE AGAIN! When we push the second time,
      // push NEGATIVE address...addresses can't be negative,
      // positive address means go to right child, negative address
      // means print.
      temp = pop(&stk);
      // check if positive or negative
      if(temp > 0) {
	push(&stk, -temp);
	temp = ((Node *)temp)->rchild;
      }
      else {
	printf("%d ", ((Node *)temp)->data);
	temp = NULL;
      }
    }
  }
}
*/


// in a way, this is sort of like the reverse of populating the tree!
void LevelOrder(struct Node *root){
  struct Queue q;
  create(&q, 100);

  printf("%d ", root->data);
  enqueue(&q, root);

  while(!isEmpty(q)) {
    root = dequeue(&q);
    if(root->lchild) {
      printf("%d ",root->lchild->data);
      enqueue(&q, root->lchild);
    }
    if(root->rchild) {
      printf("%d ",root->rchild->data);
      enqueue(&q, root->rchild);
    }
  }
}


int main(){
  printf("Enter values of elements in a binary tree. Enter -1 to indicate leaf node.\n");
  treeCreate();
  
  printf("Iterative preorder traversal -> ");
  IPreorder(root);
  printf("\n");
  
  printf("Iterative inorder traversal -> ");
  IInorder(root);
  printf("\n");

  /*
  printf("Iterative postorder traversal -> ");
  IPostorder(root);
  printf("\n");
  */

  printf("Level order traversal -> ");
  LevelOrder(root);
  printf("\n");
  
  return 0;
}
