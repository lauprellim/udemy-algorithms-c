#include<stdlib.h>

// tree node
struct Node{
  struct Node *lchild;
  int data;
  struct Node *rchild;
};

struct Queue{
  int size;
  int front;
  int rear;
  // going to store pointer of type Node
  struct Node **Q;
};

void create(struct Queue *q, int size){
  q->size = size;
  q->front = q->rear = 0;
  // careful here!
  q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x){
  if((q->rear + 1) % q->size == q->front) printf("Queue is full...\n");
  else{
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
  }
}

struct Node * dequeue(struct Queue *q){
  struct Node* x = NULL;
  if(q->front == q->rear) printf("Queue is empty...\n");
  else{
    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front];
  }
  return x;
}

int isEmpty(struct Queue q){
  return q.front == q.rear;
}
