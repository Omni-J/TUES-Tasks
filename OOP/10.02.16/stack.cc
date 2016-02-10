/*
!!!!!!!!!!!!!!!!!!!!!!!!!

For specialized tempate dev : Modern C++ design: Generic Programming and desing patterns applied (c++in depth series).

!!!!!!!!!!!!!!!!!!!!!!!!!
*/

#include <iostream>
using namespace std;

class StackError{};

template<typename T>
class Stack{
    const static int STACK_SIZE = 10;
    int top_;
    T data_[STACK_SIZE];
public:
  Stack()
  : top_(0)
  {}

  bool empty() const {
    return top_ == 0;
  }

  bool full() const{
    return top_ == STACK_SIZE;
  }

  void push(T val){
    if(full()){
      throw StackError();
    }
    data_[top_++] == val;
  }

  T pop(){
    if (empty()){
      throw StackError();
    }
    return data_[--top_];
  }
  void foo(){
    T val;
    val.get_x();
  }
};

int main() {

  Stack<int> ist;
  Stack<double> dst;

  for(int i = 0; i)
  return 0;
}
