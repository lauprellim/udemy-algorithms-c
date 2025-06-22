#include<stdio.h>
#include<stdlib.h>

// for each term in the polynomial
struct Term {
  // this could be float, but we'll make it int...
  int coeff;
  // exponent
  int exp;
};

// polynomial representation
struct Poly {
  int n;
  // we don't know how many terms there will be
  struct Term *terms;
};

void create(struct Poly *p) {
  int i;
  printf("Enter number of terms in your polynomial: ");
  scanf("%d", &p->n);
  p->terms = (struct Term*)malloc(p->n*sizeof(struct Term));

  printf("Enter all the terms:\n");
  for(i=0; i<p->n;i++) scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
}

void display(struct Poly p) {
  int i;
  for(i=0; i<p.n; i++) printf("%dx^%d + ", p.terms[i].coeff, p.terms[i].exp);
  printf("\n");
}

// call by reference
struct Poly *add(struct Poly *p1, struct Poly *p2) {
  int i, j, k;
  struct Poly *sum;
  sum = (struct Poly*)malloc(sizeof(struct Poly));

  // at most I need the number of terms in p1 and p2
  sum->terms = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

  i = j = k = 0;

  // compare and copy
  while( i < p1->n && j < p2->n ) {
    // if first polynomial's term is greater than second, copy the first
    if( p1->terms[i].exp > p2->terms[j].exp ) sum->terms[k++] = p1->terms[i++];
    else if( p1->terms[i].exp < p2->terms[j].exp ) sum->terms[k++] = p2->terms[j++];
    // if both coefficients are equal, sum them:
    else {
      sum->terms[k].exp = p1->terms[i].exp;
      sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
    }
  }
  // we're done with while loop
  // account for possible remaining elements
  for(; i<p1->n; i++) sum->terms[k++] = p1->terms[i];
  for(; j<p2->n; j++) sum->terms[k++] = p2->terms[j];

  sum->n = k;
  return sum;  
}

int main() {
  struct Poly p1, p2, *p3;
  create(&p1);
  create(&p2);
  p3 = add(&p1, &p2);

  printf("\nFirst polynomial:\n");
  display(p1);

  printf("\nSecond polynomial:\n");
  display(p2);

  printf("\nSum of the two polynomials:\n");
  display(*p3);
  
  return 0;
}
