#ifndef Queue_h
#define Queue_h

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
  Node **Q;
};

void create(struct Queue *q, int size){
  q->size = size;
  q->front = q->rear = 0;
  // careful here!
  q->Q = (Node **)malloc(q->size * sizeof(Node *));
}

void enqueue(struct Queue *q, Node *){
  if((q->rear + 1) % q->size == q->front) printf("Queue is full...\n");
  else{
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
  }
}

Node * dequeue(struct Queue *q){
  Node* x = NULL;
  if(q->front == q->rear) printf("Queue is empty...\n");
  else{
    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front];
  }
  return x;
}

isEmpty(struct Queue q){
  return q.front == q.rear;
}
