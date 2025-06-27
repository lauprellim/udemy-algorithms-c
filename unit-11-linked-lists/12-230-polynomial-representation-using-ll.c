#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
  int coeff;
  int exp;
  struct Node *next;
  // define the global var below
}*poly = NULL;

void create(){
  struct Node *t, *last = NULL;
  // number of terms:
  int num, i;

  printf("Enter number of terms: ");
  scanf("%d", &num);
  printf("Enter each term with coeff and exponent: \n");

  for(i=0; i<num; i++) {
    t=(struct Node *)malloc(sizeof(struct Node));
    scanf("%d%d", &t->coeff, &t->exp);
    t->next = NULL;
    // if this is the first node:
    if(poly == NULL){
      poly=last=t;
    }
    // otherwise it has to be inserted as the last node:
    else {
      last->next=t;
      last=t;
    }
  }  
}

double eval(struct Node *p, int x){
  double val;
  while(p){
    val += p->coeff * pow(x,p->exp);
    p=p->next;
  }
  return val;
}

void display(struct Node *p){
  while(p){
    printf("%dx^%d + ",p->coeff, p->exp);
    p = p->next;
  }
  printf("\n");
}

int main(){
  create();
  display(poly);

  printf("With x = 1, this polynomial evaluates to: %lf\n", eval(poly, 1));
  
  return 0;
}
