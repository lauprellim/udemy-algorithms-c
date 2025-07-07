/* AVL tree with ll
 */


#include<stdio.h>
#include<stdlib.h>

struct Node {
  struct Node *lchild;
  int data;
  // although we need only 2 bits for height factor,
  // we will use int for now
  int height;
  struct Node *rchild;
}*root = NULL;

int NodeHeight(struct Node *p){
  int hl, hr;
  // pay attention to this!
  hl = p && p->lchild ? p->lchild->height:0;
  hr = p && p->rchild ? p->rchild->height:0;
  return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(struct Node *p){
  int hl, hr;
  hl = p && p->lchild ? p->lchild->height:0;
  hr = p && p->rchild ? p->rchild->height:0;
  return hl - hr;
}

struct Node * LLRotation(struct Node *p){
  // use some pointers. you only need 2, we'll use 3.
  struct Node *pl = p->lchild;
  struct Node *plr = pl->rchild;

  pl->rchild = p;
  p->lchild = plr;

  // recalculate height
  p->height = NodeHeight(p);
  pl->height = NodeHeight(pl);

  // what if rotation was performed around root node?
  if(root == p) root = pl;

  return pl;
}

struct Node * LRRotation(struct Node *p){
  return NULL;
}

struct Node * RRRotation(struct Node *p){
  return NULL;
}

struct Node * RLRotation(struct Node *p){
  return NULL;
}


struct Node *RInsert(struct Node *p, int key){
  struct Node *t = NULL;

  // create node -- in other words, if(p == NULL):
  if(!p) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    // also set height. A single new leaf node will have height 1
    // (it should probably have height 0...)
    // try setting this to 0!
    t->height = 1;
    t->lchild = t->rchild = NULL;
    return t; 
  }
  // otherwise, traverse...
  if(key < p->data) p->lchild = RInsert(p->lchild, key);
  else if(key > p->data) p->rchild = RInsert(p->rchild, key);
  // at returning time, update height
  // we have to check left and right subtrees
  p->height = NodeHeight(p);

  // check balance factors and decide whether to perform rotation
  if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) return LLRotation(p);
  else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) return LRRotation(p);
  else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) return RRRotation(p);
  else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) return RLRotation(p);
  return p;
}



int main() {

  root = RInsert(root, 10);
  RInsert(root, 5);
  RInsert(root, 2);
  
  
  return 0;
}
