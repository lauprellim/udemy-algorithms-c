#include<stdio.h>

// medical is an anagram of decimal. We will check only lower-case alphabetical characters
// to see if one string is an analgram of another.
// medical decimal
// verbose observe

int main() {

  // here is the string we will count...
  char A[] = "medical";
  char B[] = "decimal";

  // char A[] = "aabcdefghij";
  // char B[] = "jighfedcapq";
  
  // we should check to see if the strings are the same length...
  
  int H[26] = {0};
  int i;

  // increment the element in this hash table if that character exists in 1st string
  for ( i = 0; A[i] != '\0'; i++ ) H[A[i]-97]+=1;
  // scan through second string, DECREMENT that element in the string if the char exists
  for ( i = 0; B[i] != '\0'; i++ ) {
    H[B[i]-97]-=1;
    if(H[B[i]-97] < 0) {
      printf("Strings %s and %s are NOT anagrams.\n", A, B);
      break;
    }
  }

  if (B[i] == '\0') printf("Strings %s and %s ARE anagrams.\n", A, B);
  return 0;
}
