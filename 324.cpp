#include <iostream>

struct Test{  
  // member variable
  // function pointer as a member function
  void (Test::* func)(void); 

  // constructor
  Test(void)
  :func(&Test::Print)
  {
    
  }

  // member functions
  void Print(void){
    std::cout<<"member function called\n";
  }
  void Proxy(void){
    (this->*func)();
  }
};


int main(void){
  Test test;

  test.Proxy();
  (test.*test.func)();
}

