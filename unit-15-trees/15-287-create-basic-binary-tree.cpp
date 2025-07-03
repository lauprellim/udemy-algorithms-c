#include<iostream>
#include "queue-cpp.h"

class Tree{
public:
  Node *root;
  // constructors
  Tree() { root = NULL; }

  // takes no parameter because root is available inside tree itself
  void createTree();
  void preOrder(Node *p);
  void inOrder(Node *p);
  void postOrder(Node *p);
  void levelOrder(Node *p);
  void height(Node *foog);
};


// this is the same as in the c program
void tree:createTree(){
  Node *p, *t;
  int x;
  Queue q(100);

  // create(&q, 100);

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











int main(){
  
  return 0;
}
