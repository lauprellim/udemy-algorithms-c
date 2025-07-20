/*
  In chaining you make every element of the hash array into
  a pointer to a linked list.
  Let's say I have 100 elements, so n=100
  and an array of size 10 to store them so size = 10
  the LOADING FACTOR (lambda) is n / size,so the LF
  is 10. Each location in the array has about 10 keys.

  Ideally the hash function should ensure an EVEN DISTRIBUTION
  of data across the keys of the hash array. Otherwise
  too many collisions will occur. Of course the linked
  list can take care of the collisions, but you want
  to avoid them anyway.
  
  So the time in case of successful search is:
  t = 1 + (lambda/2)

  Time in case of unsuccessful search (max time):
  t = 1 + lambda.
  
  We can also use linear probing, quadratic probing or
  rehasing (resizing of array) to make hashing a workable
  method.
  
 */

#include<stdio.h>
#include"chains.h"

// the hash code -- very simple...
int hash(int key){
  return key % 10;
}

void Insert(struct Node *H[], int key){
  int index = hash(key);
  SortedInsert(&H[index], key);
}

/*
void Display(struct Node *p, int n){
  // outer loop prints out array
  int i;
  for(i = 0; i<n; i++){
    if(p){
      printf("%d ", p->data);
      p=p->next;
    }
    else printf("/ \n");
  }
}
*/

int main(){
  // HT = "hash table"...
  struct Node *HT[10];
  struct Node *temp;
  int i;

  // initialize
  for(i=0; i<10; i++) HT[i] = NULL;

  Insert(HT, 12);
  Insert(HT, 22);
  Insert(HT, 42);

  // send index and key
  temp = Search(HT[hash(22)], 22);

  // Display(HT, 10);
  
  printf("Found: %d\n", temp->data);
  
  return 0;
}
