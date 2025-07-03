#include<iostream>
using namespace std;
#ifdef queue-cpp.h
#define queue-cpp.h

class Node {
public:
  Node *lchild;
  int data;
  Node *rchild;
};

class Queue {
private:
  int front;
  int rear;
  int size;
  // In C this was int *Q. Now it is Node **Q as it was already a pointer.
  // Queue pointer stores ADDRESSES of a tree.
  Node **Q;
public:
  // parameterized and non-parameterized constructors
  // Queue stores the addresses of the tree.
  Queue(){ front = rear = -1; size = 10; Q = new Node*[size]; }
  Queue(int size){ front = rear = -1; this->size = size; Q = new Node*[this->size]; }
  void enqueue(Node* x);
  Node* dequeue();
  int isEmpty() { return front == rear; }
  void display();  
};

void Queue::enqueue(Node *x){
  if(rear == size - 1) cout<<"Queue is full...\n"<<endl;
  else {
    rear++;
    Q[rear] = x;
  }
}

Node* Queue::dequeue() {
  Node* x = NULL;
  if(front == rear) cout<<"Queue is empty...\n"<<endl;
  else{
    x = Q[front+1];
    front++;
  }
  return x;
}

void Queue::display(){
  for(int i = front+1; i<=rear; i++) cout<<Q[i]<<" ";
  cout<<endl;
}

#endif /* queue-cpp.cpp */
