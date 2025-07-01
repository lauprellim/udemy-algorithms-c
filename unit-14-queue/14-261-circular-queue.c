/*
  Circular queue
  Leave an empty element so front and rear counter are not equal
  (full condition is that f = r.)

  Use modular operator to get this to work.
  rear pointer is initially 0 and so is front (NOT -1 as before).
  rear moves to the right while elements are inserted
  front moves to the right as elements are popped
  when rear reaches the end of the array, it goes back to the beginning
  (as long as there is space!)

  Fixed an error in the example code, in the display() function...
  
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
  // front and rear are intialized to 0
  q->front = q->rear = 0;
  q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct queue *q, int x){
  // check if queue is full
  if( ( q->rear + 1 ) % q->size == q->front ) printf("Queue is full...\n");
  else {
    // move index postion of array Q to the right
    q->rear = ( q->rear + 1 ) % q->size;
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
    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front];
  }
  return x;
}

void display(struct queue q){
  // was
  // int i = q.front + 1;
  int i = ( q.front + 1 ) % q.size;

  do {
    printf("%d ", q.Q[i]);
    i = (i+1) % q.size;
  }while(i != (q.rear+1) % q.size);

  printf("\n");
}

int main() {
  struct queue q;

  create(&q, 5);

  printf("Queue is only size 5!\n");
  
  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);

  display(q);

  printf("Dequeued value %d \n",dequeue(&q));
  display(q);

  printf("Dequeued value %d \n",dequeue(&q));
  display(q);

  enqueue(&q, 40);
  display(q);
  enqueue(&q, 50);
  display(q);
  enqueue(&q, 60);
  display(q);
  
  printf("Dequeued value %d \n",dequeue(&q));
  display(q);

  printf("Dequeued value %d \n",dequeue(&q));
  display(q);

  printf("Dequeued value %d \n",dequeue(&q));
  display(q);

  return 0;
}
