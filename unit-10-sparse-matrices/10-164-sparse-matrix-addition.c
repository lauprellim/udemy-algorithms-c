/* Program for representing and populating a sparse matrix using coordinate system
   This also now ADDS two sparse matrices by creating a
   third matrix and incrementing through. There are
   three ints for incrementing (i, j, k) and an add func.

   Here's some example output. The user inputted the first two matrices,
   the algorithm generated the sum matrix:

   First matrix: 
   1 0 0 0 0 
   0 1 0 0 0 
   0 0 1 0 0 
   0 0 0 1 0 
   0 0 0 0 1 

   Second matrix: 
   2 0 0 0 0 
   2 0 0 0 0 
   2 0 0 0 0 
   2 0 0 0 0 
   2 0 0 0 0 

   Sum matrix: 
   3 0 0 0 0 
   2 1 0 0 0 
   2 0 1 0 0 
   2 0 0 1 0 
   2 0 0 0 1
*/

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

// though this func is not going to modify the matrices,
// we'll do call by address nevertheless...
// I could have done call by value.
// Will return pointer on a sparse matrix which will be
// the sum of the two.
struct Sparse * add(struct Sparse *s1, struct Sparse *s2) {
  // declare & initialize iterators. i will iterate on s1, j iterates on s2,
  // and k will iterate on sum.
  int i,j,k;
  i=j=k=0;  
  // create a pointer to a new sparse matrix, allocate its memory
  // in heap. This will be the matrix that contains the sum.
  struct Sparse *sum;
  sum = (struct Sparse *)malloc(sizeof(struct Sparse));
  // Because the sparse matrix contains a struct ele (which will store
  // the addresses and their values,) we will initialize that to the sum of num
  // in both incoming arrays. This will be the MAXIMUM size we need,
  // we will need for sure at least HALF of this, at most ALL all of this.
  // So at most it will be the number of elements of s1 PLUS number of
  // elements of s2.
  sum->ele = (struct Element *)malloc((s1->num + s2->num)*sizeof(struct Element));

  // we should check to see if both matrixes are the same size.
  // ...?
  
  // now the loop for comparing the elements
  while( i < s1->num && j < s2->num ){
    // first compare ROW numbers
    // be careful to remember what the various i's and j's mean here!!
    // also don't forget to post-increment elements, to move the pointers
    // to the next elements.
    // if s1's i is less than s2's i -- that is, i's ROW is less than j's:
    // put that element in the summation matrix.
    if( s1->ele[i].i < s2->ele[j].i ) sum->ele[k++] = s1->ele[i++];
    // else if s2's i is greater than s1's, put that element in summation matrix.
    else if( s1->ele[i].i > s2->ele[j].i ) sum->ele[k++] = s2->ele[i++];
    // otherwise, row numbers are the same, so check column numbers.
    else {
      // now if s1's column is greater than s2's put that in sum matrix;
      if( s1->ele[i].j < s2->ele[j].j ) sum->ele[k++] = s1->ele[j];
      // otherwise, s2's column is greater than s1, so put that in sum;
      else if( s1->ele[i].j > s2->ele[j].j ) sum->ele[k++] = s2->ele[j++];
      // if we get here, it means row and column of both s1 and s2 are the same,
      // so we need to add elements. First put the entire entry into sum matrix,
      // then perform addition. Just take s1's information (we could take s2).
      else {
	sum->ele[k] = s1->ele[i];
	// don't forget to mention x:
	sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
      }
    }  
  }
  // we have exited the while loop here.
  // now one more important thing. Whichever matrix (s1 or s2) has not
  // iterated to its end, we should simply COPY all those remaining elements
  // to the sum matrix.
  for(; i < s1->num; i++) sum->ele[k++] = s1->ele[i];
  // do the same thing for s2 matrix
  for(; j < s2->num; j++) sum->ele[k++] = s2->ele[j];

  // mention dimensions of sum matrix. just take information from s1 matrix,
  // though again we could have taken s2
  sum->m = s1->m;
  sum->n = s1->n;
  // k has been tracking nonzero elements
  sum->num = k;

  return sum;
}

int main() {
  // we will add s1 and s2, and store the sum in s3.
  struct Sparse s1, s2, *s3;
  
  // send s to create function
  create(&s1);
  create(&s2);

  s3 = add(&s1, &s2);
  printf("First matrix: \n");
  display(s1);
  printf("\nSecond matrix: \n");
  display(s2);
  printf("\nSum matrix: \n");
  // send dereferences value of s3
  display(*s3);
  
  return 0;
}
