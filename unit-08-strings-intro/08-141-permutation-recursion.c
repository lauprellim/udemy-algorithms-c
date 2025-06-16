#include<stdio.h>

// Find all the permutations of a string. Use:
// state-space tree...
// backtracking...
// brute force...
// recursion...to achieve backtracking.
// ...you can of course also use loop....

  // string array
  // flag array = A, initialize everything to 0
  // result array - same size
  // use two counters, k and i.
  
void perm(char s[], int k) {
  static int A[10] = {0};
  static char result[10];
  int i;

  // check to see if we have reached the end; if so, we're at
  // a leaf of the state-space tree. print result.
  if(s[k] == '\0') {
    result[k] = '\0';
    printf("Result is %s\n", result);
  } else {
    // scan through string and print it
    for ( i = 0; s[i] != '\0'; i++) {
      // see if this character is available
      if(A[i] == 0) {
	result[k] = s[i];
        // mark this as unavailable in the "flags" array
	A[i] = 1;
	// make recursive call
	perm(s, k+1);
	// when returning, mark it is available in the flags array
	A[i] = 0;
      }
    }
  }
}

int main() {
  char s[] = "ABCD";
  printf("Permutations of string %s:\n", s);
  perm(s, 0);
  return 0;

}
