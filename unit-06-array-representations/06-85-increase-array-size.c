#include<stdio.h>
#include<stdlib.h>

int main() {
  int *p, *q, i;
  p=(int *)malloc(5*sizeof(int));

  p[0]=3; p[1]=5; p[2]=7; p[3]=9; p[4]=11;

  printf("Original values in array p[5]:\n");
  for(i=0;i<5;i++) printf("%d ", p[i]);

  q=(int *)malloc(10*sizeof(int));
  for(i=0;i<5;i++) q[i] = p[i];

  printf("\nCopied values in array q[10]:\n");
  for(i=0;i<10;i++) printf("%d ", q[i]);

  printf("\n\n");

  // delete (garbage collect) p array, change pointers, delete pointer q:
  free(p);
  p=q;
  q=NULL;

  return 0;
}
