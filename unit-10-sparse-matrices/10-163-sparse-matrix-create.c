// program for representing and populating a sparse
// matrix using coordinate system

#include<stdio.h>
#include<stdlib.h>

// represents non-zero element
struct Element {
  int i, j, x;
};

// struct for represeting the matrix
struct Sparse {
  int m, n, num;
  struct Element *ele;
};

// takes a sparse struct by reference, because it has to
// modify the struct
void create(struct Sparse *s) {
  int i;
  
  // get input from keyboard
  printf("Enter 2 ints -- dimensions of sparse matrix (m x n): ");
  scanf("%d%d", &s->m, &s->n);
  printf("\nEnter number of non-zero elements: ");
  scanf("%d", &s->num);
  // create an array of size num. don't forget to typecast it,
  // because malloc returns void pointer 
  s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));
  printf("\nEnter three ints -- all non-zero elements (i,j,ele): ");
  // loop for reading elements
  for (i = 0; i< s->num; i++) scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
}

// call by value, not going to modify the matrix
// again use dot, not arrow to access members of the struct
void display(struct Sparse s) {
  int i, j, k=0;
  // need two for loops to display a matrix...
  for(i = 0; i < s.m; i++){
    for(j = 0; j < s.n; j++) {
      // display a nonzero element if i and j are matching 
      if(i == s.ele[k].i && j == s.ele[k].j)
	// don't forget to move to the next element of the matrix,
	// if the elements are matching!
	printf("%d ", s.ele[k++].x);
      else
	// otherwise this element will be a zero
	printf("0 ");
    }
    // end of matrix row
    printf("\n");
  }

}

int main() {
  struct Sparse s;
  // send s to create function
  create(&s);
  // display s
  display(s);
  
  return 0;
}
