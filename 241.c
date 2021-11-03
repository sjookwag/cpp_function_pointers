#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void Change(int* pn);
void ToDouble(int* pn);
void PrintElement(int* pn);
void ProxyFunction(void (* func)(int*), int* array, int size);

void main(void){
  void (* FuncArray[3])(int*) = { Change, ToDouble, PrintElement };
  int array[10] = {0};
  int menu;

  while(1){
    printf("[0]Exit [1]Create [2]Double [3]Print - ");
    scanf("%d", &menu);
    if(menu<0||menu>3)
      continue;
    if(menu==0)
      break;
    ProxyFunction(FuncArray[menu-1], array, 10);
    if(menu==3)
      printf("\n");
  }
}

void Change(int* pn){
  *pn=rand()%100;
}
void ToDouble(int* pn){
  *pn*=2;
}
void PrintElement(int* pn){
  printf("%3d", *pn);
}
void ProxyFunction(void (* func)(int*), int* array, int size){
  for(int i=0; i<size; ++i)
    func(array+i);
}