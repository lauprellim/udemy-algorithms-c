/* AVL tree with LL, RR, LR and RL rotations!
   Also has deletion
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
  printf("Performing LL rotation.\n");
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

struct Node * RRRotation(struct Node *p){
  printf("Performing RR rotation.\n");
  struct Node *pl = p->rchild;
  struct Node *plr = pl->lchild;

  pl->lchild = p;
  p->rchild = plr;

  // recalculate height
  p->height = NodeHeight(p);
  pl->height = NodeHeight(pl);

  if(root == p) root = pl;
  return pl;
}

// we need three nodes: p, pl, and plr
// p  - "top" node
// pl - "middle" node
// plr - "bottom" node
struct Node * LRRotation(struct Node *p){
  printf("Performing LR rotation.\n");
  struct Node *pl = p->lchild;
  struct Node *plr = pl->rchild;

  // need four changes
  pl->rchild = plr->lchild;
  p->lchild = plr->rchild;
  plr->lchild = pl;
  plr->rchild = p;

  pl->height = NodeHeight(pl);
  p->height = NodeHeight(p);
  plr->height = NodeHeight(plr);

  // new root?
  if(root == p) root = plr;
  return plr;
}

struct Node * RLRotation(struct Node *p){
  printf("Performing RL rotation.\n");
  struct Node *pl = p->rchild;
  struct Node *plr = pl->lchild;

  // need four changes
  pl->lchild = plr->rchild;
  p->rchild = plr->lchild;
  plr->rchild = pl;
  plr->lchild = p;

  pl->height = NodeHeight(pl);
  p->height = NodeHeight(p);
  plr->height = NodeHeight(plr);

  // new root?
  if(root == p) root = plr;
  return plr;
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

/* there are 6 rotations for deletion
   L1, L-1, L0; R1, R-1, R0
   if you remove something from right side, tree can become impalanced on left side...
   for right-side deletions:
   L1 means LL; L-1 means LR; L0 means L1 *or* L-1.
*/
struct Node * Delete(struct Node *p, int key) {
  if(!p) return NULL;

  if(p->lchild == NULL && p->rchild == NULL) {
    if(p == root) root = NULL;
    free(p);
    return NULL;
  }

  if( key < p->data) p->lchild = Delete(p->lchild, key);
  else if (key > p->data) p->rchild = Delete(p->rchild,key);
  else {
    struct Node *q;
    if(NodeHeight(p->lchild) > NodeHeight(p->rchild)){
      q = InPre(p->lchild);
      p->data = q->data;
      p->lchild = Delete(p->lchild, q->data);
    } else {
      q = InSucc(p->rchild);
      p->data = q->data;
      p->rchild = Delete(p->rchild, q->data);
    }
  }

  // update height
  p->height = NodeHeight(p);

  // balance factor and rotation
  if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) return LLRotation(p); // L1 rotation
  else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) return LRRotation(p); // L-1 rotation
  else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) return RRRotation(p); // R-1 rotation
  else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) return RLRotation(p); // R1 rotation
  else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0) return LLRotation(p); // L0 rotation
  else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0) return RRRotation(p); // R0 rotation

  return p;
}

// traversals
void Inorder(struct Node *p){
  if(p) {
    Inorder(p->lchild);
    printf("%d ",p->data);
    Inorder(p->rchild);
  }
}

void Postorder(struct Node *p){
  if(p) {
    Postorder(p->lchild);
    Postorder(p->rchild);
    printf("%d ",p->data);
  }
}

int main() {

  root = RInsert(root, 10);
  printf("Inorder -> "); Inorder(root); printf("\n");
  printf("Postorder -> "); Postorder(root); printf("\n\n");

  RInsert(root, 20);
  printf("Inorder -> "); Inorder(root); printf("\n");
  printf("Postorder -> "); Postorder(root); printf("\n\n");

  RInsert(root, 30);
  printf("Inorder -> "); Inorder(root); printf("\n");
  printf("Postorder -> "); Postorder(root); printf("\n\n");

  RInsert(root, 25);
  printf("Inorder -> "); Inorder(root); printf("\n");
  printf("Postorder -> "); Postorder(root); printf("\n\n");

  RInsert(root, 28);
  printf("Inorder -> "); Inorder(root); printf("\n");
  printf("Postorder -> "); Postorder(root); printf("\n\n");
  
  RInsert(root, 27);
  printf("Inorder -> "); Inorder(root); printf("\n");
  printf("Postorder -> "); Postorder(root); printf("\n\n");
  
  RInsert(root, 5);  
  printf("Inorder -> "); Inorder(root); printf("\n");
  printf("Postorder -> "); Postorder(root); printf("\n");
  
  return 0;
}
