#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef void (* func)(int*, int);

void FillRandom(int* array, int size);
void DoubleUp(int* array, int size);
void Print(int* array, int size);
void ProxyFunction(func funct, int* array, int size);

void main(void){
  int array[10];
  int menu;

  while(1){
    printf("[0]Exit [1]Create [2]DoubleUp [3]Print - ");
    scanf("%d", &menu);
    if(menu==0){
      break;
    }
    switch(menu){
      case 1: ProxyFunction(FillRandom, array, 10); break;
      case 2: ProxyFunction(DoubleUp, array, 10); break;
      case 3: ProxyFunction(Print, array, 10); break;
    }
  }
}

void FillRandom(int* array, int size){
  for(int i=0; i< size; i++){
    array[i] = rand()%100;
  }
}

void DoubleUp(int* array, int size){
  for(int i=0; i< size; i++){
    array[i] *= 2;
  }
}
void Print(int* array, int size){
  for(int i=0; i< size; i++){
    printf("%3d", array[i]);

    printf("\n");
  }
}

void ProxyFunction(func funct, int* array, int size){
  funct(array, size);
}
