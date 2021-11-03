#include <stdio.h>

void First(void);
int Second(int n);

void main(void){
  void (* func1)(void);
  int (* func2)(int);

  func1=(void (*)(void)) Second;
  printf("return: %d\n", ((int (*)(int)) func1)(123));

  func2=(int (*)(int)) First;
  ((void (*)(void)) func2)();
}

void First(void){
  printf("First() \n");
}

int Second(int n){
  printf("Second() \n");
  return n*2;
}