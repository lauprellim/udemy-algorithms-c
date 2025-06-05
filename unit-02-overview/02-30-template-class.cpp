#include<iostream>

template<class T>
class Arithmetic {
private:
  T a, b;
public:
  Arithmetic(T a, T b);
  T add();
  T sub();
};

template<class T>
Arithmetic<T>::Arithmetic(T a, T b) {
    this->a=a;
    this->b=b;
}

template<class T>
T Arithmetic<T>::add() {
    T c;
    c=a+b;
    return c;
}

template<class T>
T Arithmetic<T>::sub() {
    T c;
    c=a-b;
    return c;
  }

int main() {
  Arithmetic<int> ar_int(10, 5);
  std::cout<<"Addition: "<<ar_int.add()<<std::endl;
  std::cout<<"Subtraction: "<<ar_int.sub()<<std::endl;

  Arithmetic<float> ar_flo(5.2, 6.1);
  std::cout<<"Addition: "<<ar_flo.add()<<std::endl;
  std::cout<<"Subtraction: "<<ar_flo.sub()<<std::endl;

  Arithmetic<char> ar_char('A', 3);
  std::cout<<"Addition: "<<ar_char.add()<<std::endl;
  std::cout<<"Subtraction: "<<ar_char.sub()<<std::endl;
  
  return 0;
}
