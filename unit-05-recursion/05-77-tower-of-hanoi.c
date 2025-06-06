#include <stdio.h>

// this is "tree recursion" as there are two recursive calls
// in the TOH function.
// complexity is O(2^n).

void TOH(int n, int A, int B, int C) {
  // from tower = A
  // "using" tower = B
  // destination ("to") tower = C

  if(n>0){
    TOH(n-1, A, C, B);
    printf("Move a disk from tower %d to tower %d\n", A, C);
    TOH(n-1, B, A, C);
  }
}
  
int main() {
  // first parameter is the number of disks
  // second parameter is from tower
  // third parameter is "using" tower
  // fourth parameter is "to" (destination) tower

  int numberOfDisks;
  printf("How many disks? ");
  scanf("%d", &numberOfDisks);

  // you can actually change the parameters to move disks
  // to different towers!
  TOH(numberOfDisks, 1, 2, 3);

  return 0;
}
