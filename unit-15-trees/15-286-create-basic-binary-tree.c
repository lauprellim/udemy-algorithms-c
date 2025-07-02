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
    printf("Enter left child: ");
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
    printf("Enter right child: ");
    scanf("%d", &x);
    if(x != -1){
      t = struct Node *)malloc(sizeof(struct Node));
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

int main(){
  
  treeCreate();
  preorder(root);
  
  return 0;
}
