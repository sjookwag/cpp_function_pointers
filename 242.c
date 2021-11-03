#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

enum {ARRAY_SIZE=20};

void FillRandom(int* array, int size);
void Print(int* array, int size);
void SelectionSort(int* array, int size);
void Selection(int* array, int size);

void main(void){
  int array[ARRAY_SIZE];
  do
  {
    FillRandom(array, ARRAY_SIZE);
    SelectionSort(array, ARRAY_SIZE);
    Print(array, ARRAY_SIZE);
    printf("Exit[space]\n");
  } while (getch()!=' ');
}

void FillRandom(int* array, int size){
  for(int i=0; i< size; i++){
    array[i] = rand()%100;
  }
}

void Print(int* array, int size){
  for(int i=0; i< size; i++){
    printf("%3d", array[i]);
    if(i%10==9)
      printf("\n");    
  }
}

void Selection(int* array, int size){
  int i, MaxPos=0;  
  for(i=0; i<size; ++i){
    if(array[i]>array[MaxPos])
      MaxPos=i;
  }
              i=array[MaxPos];
  array[MaxPos]=array[size-1];
  array[size-1]=i;
}

void SelectionSort(int* array, int size){
  for(int i=size; i>1; --i){
    Selection(array, i);
  }
}
