// implements hash table with linear probing
#include<stdio.h>
#define SIZE 10

int hash(int key){
  return key%SIZE;
}

int probe(int H[], int key){
  int index = hash(key);
  int i=0;
  // just find the next available free space in the hash array
  // for quadratic program use index*i instead of index+i.
  while(H[(index+i)%SIZE]!=0) i++;
  return(index+i)%SIZE;
}

void Insert(int H[], int key){
  int index = hash(key);
  // if that index is occupied, find another index
  if(H[index]!=0) index = probe(H, key);
  H[index] = key;
}

int Search(int H[], int key){
  int index = hash(key);
  // check if key value is available
  int i=0;
  // for quadratic program change this to index*i.
  while(H[(index+i)%SIZE]!=key) i++;
  return (index+i)%SIZE;
}


void Initialize(int H[]){
  for(int i=0; i<SIZE; i++) H[i] = 0;
}
  
int main(){
  int HT[10];
  Initialize(HT);
  
  Insert(HT, 12);
  Insert(HT, 25);
  Insert(HT, 35);
  Insert(HT, 26);

  for(int i = 0; i<SIZE; i++) printf("Value %d is at index %d.\n", HT[i], i);

  printf("\n");
  printf("Key found at %d.\n", Search(HT, 35));
  
  return 0;
}
