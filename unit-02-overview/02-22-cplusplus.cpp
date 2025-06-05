#include<iostream>

class Rectangle {
private:
  int length;
  int breadth;

public:
  // this would work...but a bit clumsy. We want to
  // initialize at the same time as declaration!
  /*
  void initialize (int l, int b) {
    length=l;
    breadth=b;
  }
  */

  // this is a CONSTRUCTOR, it does the job
  // of initializing the object, that's why it
  // has the same name as class name.
  Rectangle(int l, int b) {
    length=l;
    breadth=b;
  }

  int area() {
    return length * breadth;
  }

  void changeLength(int l) {
    length=l;
  }
};

int main() {
  // not a var, this is an actual object:
  // Rectangle r;
  // r.initialize(10,5);

  // initialize the object at time of declaration is better:
  Rectangle r(10,5);
  std::cout<<"Initial area of rectangle 10,5: "<<r.area()<<std::endl;
  r.changeLength(20);
  std::cout<<"New area of rectangle 20,5: "<<r.area()<<std::endl;

  return 0;
}
