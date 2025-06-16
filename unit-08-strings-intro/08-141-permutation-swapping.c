#include<stdio.h>

// permute a string using swapping
// we will have two pointers l and h, and increment them
// as well as a counter i

void swap(char s[], int a, int b){
  int t = s[a];
  s[a] = s[b];
  s[b] = t;
}

void perm(char s[], int l, int h) {
  int i;

  if (l == h) {
    printf("Permuted string: %s\n", s);
  } else {
  
    for( i = l; i <= h; i++ ) {
      swap(s, l, i);
      perm(s, l+1, h);
      swap(s, l, i);
    }
  }
}

int main() {
  char s[] = "ABC";
  // first parameter is the array; second is l, third is h
  perm(s,0,2);    
  return 0;
}
