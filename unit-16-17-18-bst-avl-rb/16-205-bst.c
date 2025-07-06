#include<stdio.h>
#include<stdlib.h>

struct Node{
  struct Node *lchild;
  int data;
  struct Node *rchild;
}*root = NULL;

void Insert(int key){
  struct Node *t = root;
  // trailing pointer
  struct Node *r;
  // pointer to create a new node
  struct Node *p;

  // if root is null, this is root node.
  // insert root node here
  if(root == NULL) {
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    // don't forget to point root on p!
    root = p;
    return;
  }
  
  // if this is not a leaf -- remember to move trailing pointer
  while(t != NULL) {
    r = t;
    if(key < t->data) t = t->lchild;
    else if(key > t->data) t = t->rchild;
    else return;
  }
  
  // t will be null, r will be pointing upon last node
  // this new node will have lchild and rchild null pointers.
  p = (struct Node *)malloc(sizeof(struct Node));
  p->data = key;
  p->lchild = p->rchild = NULL;
  
  // link this new node with tree
  if(key < r->data) r->lchild = p;
  else r->rchild = p; 
}

// recursive insert
struct Node * RInsert(struct Node *p, int key){
  struct Node *t;
  // this creates a node
  if(!p){
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->lchild = t->rchild = NULL;
    return t;
  }
  if(key < p->data) p->lchild = RInsert(p->lchild, key);
  else if(key > p->data) p->rchild = RInsert(p->rchild, key);
  return p;
}

// inorder traversal
void Inorder(struct Node *p){
  if(p) {
    Inorder(p->lchild);
    printf("%d ", p->data);
    Inorder(p->rchild);
  }
}

// search function -- iterative version
struct Node * Search(struct Node *p, int key){
  // this is to ensure search works on tree generated
  // through recursive insertion
  struct Node *t = p;
  while(t){
    if(key == t->data) return t;
    else if(key < t->data ) t = t->lchild;
    else t = t->rchild;
  }
  // key is NOT found:
  return NULL;
}

int main() {
  // this will take result from search
  struct Node *temp;

  Insert(10);
  Insert(5);
  Insert(20);
  Insert(8);
  Insert(30);

  /*
  struct Node *root = NULL;
  root = RInsert(root, 10);
  RInsert(root, 5);
  RInsert(root, 20);
  RInsert(root, 8);
  RInsert(root, 30);
  */
  
  printf("Inorder (sorted) traversal -> ");
  Inorder(root);
  printf("\n");

  printf("Root pointer data: %d\n", root->data);

  // this will only work on iteratively inserted tree.
  temp = Search(root, 20);
  if(temp) printf("Element %d is found.\n", temp->data);
  else printf("Element is not found...\n");

  
  
  return 0;
}
