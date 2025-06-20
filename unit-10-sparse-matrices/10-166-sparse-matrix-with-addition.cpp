/* this version overloads insertion and display functions

   Here's sample input & output:


  Enter values for first 5x5 matrix (only 5 elements): 
  Enter nonzero elements: 0 0 1
  1 1 1
  2 2 1
  3 3 1
  4 4 1
  Enter values for second 5x5 matrix (only 5 elements): 
  Enter nonzero elements: 0 0 5
  0 1 5
  0 2 5
  0 3 5
  0 4 5
  First matrix: 
  1 0 0 0 0 
  0 1 0 0 0 
  0 0 1 0 0 
  0 0 0 1 0 
  0 0 0 0 1 
  Second matrix: 
  5 5 5 5 5 
  0 0 0 0 0 
  0 0 0 0 0 
  0 0 0 0 0 
  0 0 0 0 0 
  Sum of matrices: 
  6 5 5 5 5 
  0 1 0 0 0 
  0 0 1 0 0 
  0 0 0 1 0 
  0 0 0 0 1 
*/

#include<iostream>
using namespace std;

class Element {
public:
  int i, j, x;
};

class Sparse {
private:
  // dimensions
  int m, n, num;
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

  // define a function to add matrices.
  // Parameter: needs two matrices: one is itself, the other is specified here:
  Sparse operator+(Sparse &s);

  // overload the operators for insertion and extraction
  // this is for read
  // remember friend functions??? They are not members of the class
  // but they have access to private and protected data of the class.
  // friend functions appear outside class scope
  friend istream & operator >> (istream &is, Sparse &s);
  // this is for display
  friend ostream & operator << (ostream &os, Sparse &s);

};

// here's the add function using scope resolution
Sparse Sparse::operator+(Sparse &s) {
  int i, j, k;

  // check if dimensions are the same, otherwise you can't add matrices:
  // could be return NULL in older versions of C++. nullptr doesn't work...
  // I'll just comment this out for now...
  // if(m != s.m || n != s.n) return;

  // allocate memory for third matrix which will be the sum of the two:
  Sparse *sum = new Sparse(m,n,num+s.num);

  i = j = k = 0;

  // the logic for summing the two matrices. this is again largely
  // the same, most of these lines were copied and pasted...
  // again we move the three pointers i, j, and k on the three matricies,
  // comparing their addresses and values, and populating the new summation
  // matrix "sum"...
  while( i<num && j<s.num ) {
    if(ele[i].i < s.ele[j].i) sum->ele[k++] = ele[i++];
    else if(ele[i].i > s.ele[j].i) sum->ele[k++] = s.ele[j++];
    else {
      if(ele[i].j < s.ele[j].j) sum->ele[k++] = ele[i++];
      else if(ele[i].j > s.ele[j].j) sum->ele[k++] = s.ele[j++];
      // if both indicies i and j are equal, do the addition
      else {
	// first copy the entire element
	sum->ele[k] = ele[i];
	// then do the actual sum and postincrement the counters whiel you're at it
	sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
      }
    }
  }
  // we are out of the while loop now. Be sure to copy remaning elements as i and j
  // may not have traversed every single element in their respective arrays
  for(; i < num; i++) sum->ele[k++] = ele[i];
  for(; j < s.num; j++) sum->ele[k++] = s.ele[j];
  sum->num = k;

  // return dereferenced value
  return *sum;
  
}

// here are the friend functions
// doesn't need scope resolution because this is a friend function
// before, this was
// void read() { ... }
istream & operator >> (istream &is, Sparse &s) {
  cout<<"Enter nonzero elements: ";
  // can directly access these members, they're part of the same class
  for(int i = 0; i < s.num; i++) cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
  return is;
}

// again use the signature in the class for overloading...
// before, this was
// void display() { ... }
ostream & operator << (ostream &os, Sparse &s) {
  int k = 0;
  for(int i = 0; i < s.m; i++) {
    for(int j = 0; j < s.n; j++) {
      // display an element if there is a nonzero element
      if( s.ele[k].i == i && s.ele[k].j == j )
	cout<<s.ele[k++].x<<" ";
      else cout<<"0 ";
    }
    cout<<endl;
  }
  return os;
}

int main() {
  // set some default parameters, don't take them from keyboard
  // create a sparse matrix of dimensions 5 x 5 with 5 nonzero elements
  Sparse s1(5,5,5);

  // create second matrix, to be added to the first:
  Sparse s2(5,5,5);

  // prompt user for elements:
  cout<<"Enter values for first 5x5 matrix (only 5 elements): "<<endl;
  cin>>s1;
  cout<<"Enter values for second 5x5 matrix (only 5 elements): "<<endl;
  cin>>s2;

  Sparse sum = s1 + s2;

  cout<<"First matrix: "<<endl<<s1;
  cout<<"Second matrix: "<<endl<<s2;
  cout<<"Sum of matrices: "<<endl<<sum;
  
  return 0;
}
