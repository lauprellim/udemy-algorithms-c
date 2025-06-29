// uses a linked list to implement a stack

#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;
};

class Stack{
private:
  Node *top;
public:
  Stack(){ top = NULL; }

  void push(int x);
  int pop();
  void display();
};

void Stack::push(int x){
  Node *t = new Node;
  // in the unlikely event that memory is full:
  if(t == NULL) cout<<"Stack is full."<<endl;
  else {
    // make node
    t->data = x;
    t->next = top;
    top = t;
  }
}

int Stack::pop(){
  int x = -1;
  if(top == NULL) cout<<"Stack is empty."<<endl;
  else{
    x = top->data;
    // temporary pointer to help delete node
    Node *t = top;
    top = top->next;
    delete t;
  }
  return x;
}

void Stack::display(){
  // temporary pointer to traverse ll
  Node *p = top;
  cout<<"Stack TOP -> ";
  while(p){
    cout<<p->data<<" ";
    p = p->next;
  }
  cout<<endl;
}

int main(){
  Stack stk;
  stk.push(10);
  stk.push(25);
  stk.push(40);
  stk.push(70);
  stk.push(125);
  
  stk.display();

  cout<<"Popping out one element."<<endl;

  stk.pop();
  stk.display();
  return 0;
}
