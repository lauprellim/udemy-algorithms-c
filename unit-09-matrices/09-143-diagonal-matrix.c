// shortcuts for storing diagonal matrix

#include<stdio.h>

struct matrix {
  int A[10];
  int n;
};

void set(struct matrix *m, int i, int j, int x) {
  // going to modify so take pointer
  if(i == j) m->A[i-1] = x;
}

int get(struct matrix m, int i, int j) {
  if(i == j) return m.A[i-1];
  else return 0;
}

void display(struct matrix m) {
  int i, j;
  for(i = 0; i < m.n; i++ ) {
    for( j=0; j < m.n; j++ ) {
      if( i == j) printf ("%d ",m.A[i-1]);
      else printf("0 ");
    }
    printf("\n");
  }
}

int main() {
  struct matrix m;
  m.n = 4;

  set(&m, 1, 1, 5);
  set(&m, 2, 2, 8);
  set(&m, 3, 3, 9);
  set(&m, 4, 4, 6);
  display(m);

  printf("\n");
  printf("Getting value at 2, 2: %d\n", get(m, 2, 2));
  
  return 0;
}
