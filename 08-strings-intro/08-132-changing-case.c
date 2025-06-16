#include<stdio.h>

int main() {
  char myString[20] = "ALLCAPS";
  int i;

  printf("String started off as: %s\n", myString);
  
  for(i = 0; myString[i] != '\0'; i++)  myString[i] += 32;

  printf("String is now: %s\n", myString);
  printf("i is now: %d\n", i);
  
  return 0;
}
