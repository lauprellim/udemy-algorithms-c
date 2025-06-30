/* Simply prints the number of arguments received from command line
   and the arguments themselves.  
*/


#include<stdio.h>

int main(int argc, char *argv[]) {
  // print total number of args
  printf("Number of args: %d\n", argc);

  // iterate & print
  for(int i = 0; i < argc; i++) {
    printf("Arg %d: %s\n", i, argv[i]);
  }
  return 0;
}
