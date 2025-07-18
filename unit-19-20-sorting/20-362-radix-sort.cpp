/* Algorithm for radix sort.
   Idea here is to sort by the last digit of a base-10 number
   (otherwise known obviously as ... "decimal"). Each pass sorts
   another digit starting from the right. An aux bins array
   only has to be 10 elements long. The elements go into the
   array as a linked list -- i.e., each element of the aux array
   has a pointer to a linked list. As elements get taken out,
   they are sorted by last digit, then second-to-last, etc.
   When one cycle is complete, the aux array gets re-initialized
   with nullptr.

   Abdul wrote this clever piece of code, and I madea few small
   modifications to make it easier to read.
*/

#include<iostream>
#include<cmath>
using namespace std;

template<class T>
void Print(T& vec, int n,string s){
  cout<<s<<": ["<<flush;
  for(int i=0; i<n; i++){
    cout<<vec[i]<<flush;
    if(i<n-1) {
      cout <<", "<<flush;
    }
  }
  cout << "]" << endl;
}

int Max(int A[], int n){
  int max = -32768;
  for(int i=0; i<n; i++) if(A[i] > max) max = A[i];
  return max;
}

// linked list node
class Node {
public:
  int value;
  Node* next;
};

int countDigits(int x){
  int count = 0;
  while (x != 0){
    x = x/ 10;
    count++;
  }
  return count;
}

void initializeBins(Node** p, int n){
  for(int i=0; i<n; i++) p[i] = nullptr;
}

void Insert(Node** ptrBins, int value, int idx){
  Node * temp = new Node;
  temp->value = value;
  temp->next = nullptr;
  if(ptrBins[idx] == nullptr){
    ptrBins[idx] = temp; // ptrBins[idx] is HEAD ptr
  }
  else {
    Node* p = ptrBins[idx];
    while(p->next != nullptr) p = p->next;
    p->next = temp;
  }
}

int Delete(Node** ptrBins, int idx){
  Node* p = ptrBins[idx]; // ptrBins[idx] is head ptr
  ptrBins[idx] = ptrBins[idx]->next;
  int x = p->value;
  delete p;
  return x;
}

int getBinIndex(int x, int idx){
  return (int)(x / pow(10, idx)) % 10;
}

void RadixSort(int A[], int n){
  int max = Max(A, n);
  int nPass = countDigits(max);

  // create bins array
  Node** bins = new Node* [10];

  // update bins and A for nPass times
  for(int pass=0; pass<nPass; pass++){
    // update bins based on A values
    for(int i=0; i<n; i++){
      int binIdx = getBinIndex(A[i], pass);
      Insert(bins, A[i], binIdx);
    }
    // update A with sorted elements from bin
    int i=0;
    int j=0;
    while(i < 10){
      while(bins[i] != nullptr) A[j++] = Delete(bins,i);
      i++;
    }
    // initialize bins with nullptr again
    initializeBins(bins, 10);
  }
  // clean up
  delete [] bins;
}

int main(){
  int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
  int n = sizeof(A)/sizeof(A[0]);

  Print(A, n, "\t\tA");
  RadixSort(A, n);
  Print(A, n, " SortedA");
  return 0;

}
