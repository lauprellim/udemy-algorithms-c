#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;
};

class linkedList{
private:
  Node *first;
public:
  // constructor, initialization of empty ll
  linkedList() { first = NULL; }
  // make the link list from an array of elements that gets passed
  linkedList(int A[], int n);
  // destroy
  ~linkedList();

  void display();
  void insert(int index, int x);
  int deleteNode(int index);
  int length();
};

linkedList::linkedList(int A[], int n) {
  Node *last, *t;
  int i = 0;

  // get the first node done
  first = new Node;
  first->data = A[0];
  first->next = NULL;
  last = first;

  // loop through the passed-in array to add remaining elements
  for(i = 1; i < n; i++) {
    t = new Node;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

linkedList::~linkedList(){
  Node *p = first;
  while(first){
    first = first->next;
    delete p;
    p = first;
  }
}

void linkedList::display(){
  Node *p = first;
  while(p){
    cout<<p->data<<" ";
    p = p->next;
  }
}

int linkedList::length(){
  Node *p = first;
  int len = 0;
  while(p){
    len++;
    p = p->next;
  }
  return len;
}

void linkedList::insert(int index, int x){
  Node *t, *p = first;
  // check if index is OK...
  if(index < 0 || index > length()) return;

  t = new Node;
  t->data = x;
  t->next = NULL;

  if(index == 0) first = t;
  else {
    for(int i = 0; i < index-1; i++) p = p->next;
    t->next = p->next;
    p->next = t;
  }
}

int linkedList::deleteNode(int index){
  Node *p, *q = NULL;
  int x = -1;

  if(index < 1 || index > length()) return -1;
  if(index == 1) {
    p = first;
    first = first->next;
    x = p->data;
    delete p;
  }
  else {
    p = first;
    for(int i=0; i < index-1; i++) {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    delete p;
  }
  return x;
}

int main() {
  int A[] = {1, 2, 3, 7, 8, 9};
  linkedList l(A, 6);

  cout<<"Linked list is: ";
  l.display();
  cout<<endl;

  cout<<"Deleting element 1.";
  l.deleteNode(1);
  cout<<endl;

  cout<<"Length: ";
  cout<<l.length();
  cout<<" elements."<<endl;

  cout<<"Inserted value 99 at index 3.";
  l.insert(3, 99);
  cout<<endl;

  cout<<"Linked list is: ";
  l.display();
  cout<<endl;
  
  return 0;
}
