#include <iostream>

class Parent{  
public:  
  virtual void Test(void){
    std::cout<<"[Parent called]\n";
  }
};

class Child: Parent{  
public:  
  void Test(void){
    std::cout<<"[Child called]\n";
  }
};

int main(void){
  Parent parent;
  Child child;

  void (Parent::* parentFunc)(void);
  void (Child::* childFunc)(void);

  std::cout<<"parent class\n";
  parentFunc=&Parent::Test;

  (parent.*parentFunc)();
  // (child.*parentFunc)();

  std::cout<<"child class\n";
  childFunc=&Child::Test;
  (child.*childFunc)();

  std::cout<<"child-parent class\n";
  parentFunc=(void (Parent::*)(void)) childFunc;

  (parent.*parentFunc)();
  (child.*childFunc)();  
}

