/*
  Implementation of queue using an array and two pointers
  front and rear.
  .
  Condition for empty queue is front == rear pointer, so for
  dequeue, front moves one element to the right and THEN deletes.
 */

#include<stdio.h>
#include<stdlib.h>

struct queue{
  int size;
  int front;
  int rear;
  int *Q;
};

// initialize the queue
void create(struct queue *q, int size){
  q->size = size;
  q->front = q->rear = -1;
  q->Q = (int *)malloc(q->size * sizeof(int));
}


void enqueue(struct queue *q, int x){
  // check if queue is full
  if(q->rear == q->size - 1) printf("Queue is full...\n");
  else {
    // move index postion of array Q to the right
    q->rear++;
    q->Q[q->rear] = x;
  }
}

int dequeue(struct queue *q){
  int x = -1;
  // check if there are elements or not in the queue
  // if front and rear are equal, queue is empty
  if(q->front == q->rear) printf("Queue is empty...\n");
  else {
    // move front pointer one position to the right
    q->front++;
    x = q->Q[q->front];
  }
  return x;
}

void display(struct queue q){
  int i;
  for(i = q.front+1; i<=q.rear; i++) printf("%d ", q.Q[i]);
  printf("\n");
}

int main() {
  struct queue q;

  create(&q, 5);

  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  
  display(q);

  printf("Dequeued value %d \n",dequeue(&q));

  display(q);
  
  // printf("Enter size: ");
  // scanf("%d", &q.size);

  // initialize
  // q.Q = (int *)malloc(q.size * sizeof(int));
  // q.front = q.rear = -1;
  return 0;
}
