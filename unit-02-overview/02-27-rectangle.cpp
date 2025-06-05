#include<iostream>

class Rectangle {
private:
  int length;
  int breadth;
public:
  // constructors (initialization)
  Rectangle() { length=breadth=1; }
  // overloading...
  Rectangle(int l, int b);
  // facilitators
  int area();
  int perimeter();
  // a getter or "accessor"
  int getLength() { return length; }
  // mutator
  void setLength(int l) { length = l; }

  // no destructor since no dynamic memory allocated
  // ~Rectangle();

};

// these functions use scope resolution
Rectangle::Rectangle(int l, int b) {
  length = l;
  breadth = b;
}

int Rectangle::area() { return length * breadth; }

int Rectangle::perimeter() { return ( 2 * (length + breadth)); }

// Not sure why this throws an error:
// Rectangle::~Rectangle { }

// now main
int main() {
  Rectangle r(10,5);
  std::cout<<"Original Length = "<<r.getLength()<<std::endl;
  std::cout<<"Area = "<<r.area()<<std::endl;
  std::cout<<"Perimeter = "<<r.perimeter()<<std::endl;
  r.setLength(20);
  std::cout<<"New Length = "<<r.getLength()<<std::endl;
  std::cout<<"New Area = "<<r.area()<<std::endl;
  std::cout<<"New Perimeter = "<<r.perimeter()<<std::endl;
  
}
