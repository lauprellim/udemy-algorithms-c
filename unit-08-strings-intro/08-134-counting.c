#include<stdio.h>

int main() {
  char A[] = "How are you?";

  int i, vcount=0;

  for(i = 0; A[i] != '\0'; i++)
    if(A[i]=='a' || A[i]=='e' || A[i]=='i' || A[i]=='o' || A[i]=='u') vcount++;

  printf("There are %d lower-case vowels in string %s .\n", vcount, A);

  return 0;
}
