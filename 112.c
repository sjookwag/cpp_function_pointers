#include <stdio.h>

void Test(void);

void main(void){
  void (* FuncPointer)(void) = Test;

  FuncPointer();
}

void Test(void){
  printf("Function Pointer Practice\n");
}