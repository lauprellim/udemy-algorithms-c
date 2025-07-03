#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#include "queue-cpp.h"

class Tree{
  // the "dummy" functions below allow us to make root private.
private:
  Node *root;
  
public:
  // constructors
  Tree() { root = NULL; }

  // takes no parameter because root is available inside tree itself
  void CreateTree();
  // non-parameterized, overloaded function so that root can be private.
  // a "dummy" function
  void Preorder() { Preorder(root); }
  void Preorder(Node *p);
  void Inorder() { Inorder(root); }
  void Inorder(Node *p);
  void Postorder() { Postorder(root); }
  void Postorder(Node *p);
  void Levelorder() { Levelorder(root); }
  void Levelorder(Node *p);
  int Height() { return Height(root); }
  int Height(Node *p);
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

  while(!q.isEmpty()) {
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
    Postorder(p->lchild);
    Postorder(p->rchild);
    printf("%d ", p->data);
  }
}

void Tree::Levelorder(struct Node *root) {
  Queue q(100);

  printf("%d ", root->data);
  q.enqueue(root);

  while(!q.isEmpty()) {
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

int Tree::Height(struct Node *root) {
  int x=0, y=0;
  if(root == 0) return 0;
  x = Height(root->lchild);
  y = Height(root->rchild);
  if( x > y ) return x+1;
  else return y+1;
}

int main(){
  Tree t;
  t.CreateTree();
  // since root is public, I can do this:
  cout<<"Preorder -> ";
  t.Preorder();
  // if root is public, you have to do this:
  // t.Preorder(t.root);
  cout<<endl;

  cout<<"Inorder -> ";
  t.Inorder();
  cout<<endl;

  cout<<"Postorder -> ";
  t.Postorder();
  cout<<endl;
  
  cout<<"Levelorder -> ";
  t.Levelorder();
  cout<<endl;

  cout<<"Height -> ";
  int h = t.Height();
  cout<<h<<endl;
  return 0;
}
