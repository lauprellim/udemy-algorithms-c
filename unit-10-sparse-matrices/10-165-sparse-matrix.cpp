#include<iostream>
using namespace std;

class Element {
public:
  int i; int j; int x;
};

class Sparse {
private:
  // dimensions
  int m; int n; int num;
  Element *ele;
public:
  // parametricized constructor
  Sparse(int m, int n, int num) {
    this->m = m;
    this->n = n;
    this->num = num;
    ele = new Element[this->num];
  }
  ~Sparse() { delete [] ele; }

  void read() {
    cout<<"Enter nonzero elements: ";
    // can directly access these members, they're part of the same class
    for(int i = 0; i < num; i++) cin>>ele[i].i>>ele[i].j>>ele[i].x;
  }

  void display() {
    int k = 0;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
	// display an element if there is a nonzero element
	if( ele[k].i == i && ele[k].j == j )
	  cout<<ele[k++].x<<" ";
	else cout<<"0 ";
      }
      cout<<endl;
    }
  }
};

int main() {
  // set some default parameters, don't take them from keyboard
  // create a sparse matrix of dimensions 5 x 5 with 5 nonzero elements
  Sparse s1(5,5,5);
  s1.read();
  s1.display();

  return 0;
}
