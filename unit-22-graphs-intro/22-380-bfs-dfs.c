/*
  This simple graph is

         1
       /   \
     2       3
       \   /
         4
       /   \
     5       6
     
 */

#include<stdio.h>
#include "queue.h"

// needs a matrix G, starting point, dimensions of matrix
void BFS(int G[][7], int start, int n){
  // start of traversal
  int i=start, j;
  // don't need to declare this because already there are global vars
  // in queue.h
  // struct Queue q;
  // visited array. set dimension with n?
  int visited[7]={0};

  printf("%d ",i);
  visited[i] = 1;
  enqueue(i);

  // explore the rest of the vertices
  while(!isEmpty()){
    // each time, take out a vertex from the queue
    i = dequeue();
    // start exploring that vertex
    for(j=1; j<n; j++) {
      // if there is an edge AND vertex is visited
      if(G[i][j] == 1 && visited[j] == 0) {
	printf("%d ",j);
	visited[j] = 1;
	enqueue(j);
      }
    }
  }
}

void DFS(int G[][7], int start, int n){
  // this will be recursive so declare array as static
  static int visited[7]={0};
  int j;
  if(visited[start] == 0) {
    printf("%d ",start);
    // mark vertex as visited, otherwise infinite loop
    visited[start] = 1;
    // start exploring this vertex
    for(j=1; j<n; j++) if(G[start][j] == 1 && visited[j] == 0) DFS(G, j, n);
  }
}

int main(){

  int G[7][7]={{0,0,0,0,0,0,0},
               {0,0,1,1,0,0,0},
	       {0,1,0,0,1,0,0},
	       {0,1,0,0,1,0,0},
	       {0,0,1,1,0,1,1},
	       {0,0,0,0,1,0,0},
	       {0,0,0,0,1,0,0}};

  // call BFS with graph array, starting node, dimension
  printf("BFS, starting vertex is 1 -> ");
  BFS(G, 1, 7);
  printf("\n");

  printf("BFS, starting vertex is 4 -> ");
  BFS(G, 4, 7);
  printf("\n");

  printf("DFS, starting vertex is 1 -> ");
  DFS(G, 1, 7);
  printf("\n");

  printf("DFS, starting vertex is 4 -> ");
  DFS(G, 4, 7);
  printf("\n");
  
  return 0;
}
