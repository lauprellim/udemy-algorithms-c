#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "queue-cpp.h"

class Tree{
public:
  Node *root;
  // constructors
  Tree() { root = NULL; }

  // takes no parameter because root is available inside tree itself
  void CreateTree();
  void Preorder(Node *p);
  void Inorder(Node *p);
  void Postorder(Node *p);
  void Levelorder(Node *p);
  void Height(Node *foog);
};


// this is the same as in the c program
void Tree::CreateTree(){
  Node *p, *t;
  int x;
  Queue q(100);

  printf("Enter root value: ");
  scanf("%d", &x);
  root = new Node;
  root->data = x;
  root->lchild = root->rchild = NULL;
  q.enqueue(root);

  while(!isEmpty()) {
    p = q.dequeue();;
    printf("Enter left child of %d: ", p->data);
    scanf("%d", &x);
    if(x != -1) {
      // create a node
      t = new Node;
      t->data = x;
      // insert as leaf node
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      q.enqueue(t);
    }
    printf("Enter right child of %d: ", p->data);
    scanf("%d", &x);
    if(x != -1){
      t = new Node;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      q.enqueue(t);
    }
  }
}

void Tree::Preorder(struct Node *p) {
  if(p) {
    printf("%d ", p->data);
    Preorder(p->lchild);
    Preorder(p->rchild);
  }
}

void Tree::Inorder(struct Node *p) {
  if(p) {
    Inorder(p->lchild);
    printf("%d ", p->data);
    Inorder(p->rchild);
  }
}

void Tree::Postorder(struct Node *p){
  if(p){
    printf("%d ", p->data);
    Postorder(p->lchild);
    Postorder(p->rchild);
  }
}

void Tree::LevelOrder(struct Node *root) {
  Queue q(100);

  printf("%d ", root->data);
  q.enqueue(root);

  while(!q.isEmpty) {
    root = q.dequeue();
    if(root->lchild) {
      printf("%d ", root->lchild->data);
      q.enqueue(root->lchild);
    }
    if(root->rchild) {
      printf("%d ",root->rchild->data);
      q.enqueue(root->rchild);
    }
  }  
}

int Tree:Height(struct Node *root) {
  int x=0; y=0;
  if(root == 0) return 0;
  x = Height(root->lchild);
  y = Height(root->rchild);
  if( x > y ) return x+1;
  else return y+1;
}

int main(){
  
  return 0;
}
