/* Breadth first search of a graph.
    Tried using std::queue.emplace() but needed to replace it with push()...

    Almost all verticies will be pushed onto the queue, so this is
    O(n^2) time as we have to scan through the entire array representation
    of the graph.

    If we use adjacency list, we might be able to improve it to O(n).
    The adjacency list is better for sparse graphs.
*/

#include <iostream>
#include <queue>
using namespace std;

void BFS(int vtx, int A[][8], int n){
    // we need two arrays -- the Q (queue) and the visited array.
    // initialize visited array to all 0s.
    // we are using the STL for queue, probably a good idea here.
    queue<int> Q;
    int visited[8]={0};

    // Initial
    cout << vtx << ", " << flush;  // Visit vertex
    // mark this node as visited (i.e. change it from 0 to 1)
    visited[vtx] = 1;
    Q.push(vtx);

    // Explore -- loop
    while (!Q.empty()){
        // take the first vertex from the front of the queue.
        int u = Q.front();
        Q.pop();
        // explore all of u's adjacent vertices
        for (int v=1; v<=n; v++){
            if (A[u][v] == 1 && visited[v] == 0){
                // adjacent vertex and not visited
                // visit vertex
                cout << v << ", " << flush;
                // mark this node as visited in the visited array
                visited[v] = 1;
                // push it on the queue so we can visit its neighbors
                Q.push(v);
            }
        }
    }
    cout << endl;
}

int main (){

    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};

    cout << "Entry point is vertex: 1 -> " << flush;
    BFS(1, A, 8);

    cout << "Entry point is vertex: 4 -> " << flush;
    BFS(4, A, 8);

    return 0;
}
