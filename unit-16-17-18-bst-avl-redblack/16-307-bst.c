/* Binary search tree
   with insertion and deletion functions
*/

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
struct Node *RInsert(struct Node *p, int key){
  struct Node *t;
  // this creates a node if we reach a null pointer (a leaf)
  if(!p){
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->lchild = t->rchild = NULL;
    return t;
  }
  if(key < p->data) p->lchild = RInsert(p->lchild, key);
  else if(key > p->data) p->rchild = RInsert(p->rchild, key);
  // if the key is equal to an existing element, just return p as well
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


int Height(struct Node *p) {
  int x, y;
  if(p == NULL) return 0;
  x = Height(p->lchild);
  y = Height(p->rchild);
  return x>y ? x+1 : y+1;
}

// find inorder predecessor: important --
// return rightmost child of left subtree
struct Node * InPre(struct Node *p){
  while(p && p->rchild != NULL) p = p->rchild;
  return p;
}

// find inorder successor
// find leftmost child of right subtree
struct Node * InSucc(struct Node *p){
  while(p && p->lchild != NULL) p = p->lchild;
  return p;
}

// Interesting to note that the functions Height(), InPre() and InSucc()
// must go BEFORE this function in the code or else the compiler gets
// extremely grumpy!
// This is going to be root --v
struct Node * Delete(struct Node *p, int key){
  struct Node *q;

  if(p == NULL) return NULL;
  // if p is a leaf node
  if(p->lchild == NULL && p->rchild == NULL) {
    // if p is a root node
    if(p == root) root = NULL;
    free(p);
    return NULL;
  }
  
  // this is search process
  if(key < p->data) p->lchild = Delete(p->lchild, key);
  else if(key > p->data) p->rchild = Delete(p->rchild, key);
  /* key is found, we have to delete the key
     we can delete the key and replace it with inorder predecessor or inorder successor
     best would be by looking at high of left or right side tree. If they are equal, delete
     from either side. If left hand side is larger, delete from it...etc.
  */
  else {
    if(Height(p->lchild) > Height(p->rchild)){
      // delete from left side -- this is very subtle
      q = InPre(p->lchild);
      p->data = q->data;
      p->lchild = Delete(p->lchild, q->data);
    }
    // otherwise delete from right side
    else {
      q = InSucc(p->rchild);
      p->data = q->data;
      p->rchild = Delete(p->rchild, q->data);
    }
  }
  return p;
}


int main() {
  // this will take result from search
  struct Node *temp;

  /* insert using iterative function
  Insert(10);
  Insert(5);
  Insert(20);
  Insert(8);
  Insert(30);
  */
  
  /* insert using recursive function
  root = RInsert(root, 10);
  RInsert(root, 5);
  RInsert(root, 20);
  RInsert(root, 8);
  RInsert(root, 30);
  RInsert(root, 1);
  RInsert(root, 16);
  */
  root = RInsert(root, 50);
  RInsert(root, 10);
  RInsert(root, 40);
  RInsert(root, 2);
  RInsert(root, 30);
  
  printf("Inorder (sorted) traversal -> ");
  Inorder(root);
  printf("\n");

  printf("Root pointer data: %d\n", root->data);

  Delete(root, 50);

  printf("Inorder (sorted) traversal -> ");
  Inorder(root);
  printf("\n");

  printf("Root pointer data: %d\n", root->data);

  /*
  temp = Search(root, 20);
  if(temp) printf("Element %d is found.\n", temp->data);
  else printf("Element is not found...\n");

  // delete an element
  printf("Deleting element 8.\n");
  Delete(root, 8);

  printf("Inorder (sorted) traversal -> ");
  Inorder(root);
  printf("\n");

  printf("Root is %d.\n", root->data);
  
  // delete root element
  printf("Deleting root element 10.\n");
  Delete(root, 10);

  printf("Inorder (sorted) traversal -> ");
  Inorder(root);
  printf("\n");

  printf("Root is %d.\n", root->data);
  */
  
  return 0;
}
