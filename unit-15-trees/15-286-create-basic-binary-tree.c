/* Creates basic binary tree using linked list --
   each node has pointers for left and right children.
   Using queue to keep track of memory addresses.
*/

#include<stdio.h>
#include<stdlib.h>
// our custom circular queue include
#include"queue.h"

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

int main(){
  printf("Enter values of elements in a binary tree. Enter -1 to indicate leaf node.\n");
  treeCreate();
  
  printf("Preorder traversal -> ");
  preorder(root);
  printf("\n");
  
  printf("Inorder traversal -> ");
  inorder(root);
  printf("\n");
  
  printf("Postorder traversal -> ");
  postorder(root);
  printf("\n");
  
  return 0;
}
