#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

#pragma warning(disable:4996)

enum {ARRAY_SIZE=20};

void FillRandom(int* array, int size);
void Print(int* array, int size);
void SelectionSort(int* array, int size, int(* CmpFunc)(int, int));
void Selection(int* array, int size, int(* CmpFunc)(int, int));

int compareAsc(int n1, int n2);
int compareDsc(int n1, int n2);

void main(void){
  int ch;
  int array[ARRAY_SIZE];
  while(1)
  {
    FillRandom(array, ARRAY_SIZE);
    Print(array, ARRAY_SIZE);
    
    printf("\n[space]Exit [A]Ascending [D]Descending ");
    ch = toupper(getch());
    if(ch==' ')
      break;
    if(ch!='A' && ch!='D')
      continue;

    if(ch=='A') SelectionSort(array, ARRAY_SIZE, compareAsc);
    else SelectionSort(array, ARRAY_SIZE, compareDsc);
    Print(array, ARRAY_SIZE);
  } 
}

void FillRandom(int* array, int size){
  for(int i=0; i< size; i++){
    array[i] = rand()%100;
  }
}

void Print(int* array, int size){
  printf("\n");
  for(int i=0; i< size; i++){
    printf("%3d", array[i]);
    if(i%10==9)
      printf("\n");
  }
}

void Selection(int* array, int size, int(* CmpFunc)(int, int)){
  int i, MaxPos=0;  
  for(i=1; i<size; ++i){
    if(CmpFunc(array[i], array[MaxPos])==1)
      MaxPos=i;
  }
              i=array[MaxPos];
  array[MaxPos]=array[size-1];
  array[size-1]=i;
}

void SelectionSort(int* array, int size, int(* CmpFunc)(int, int)){
  for(int i=size; i>1; --i){
    Selection(array, i, CmpFunc);
  }
}

int compareAsc(int n1, int n2){
  return n1>n2;
}

int compareDsc(int n1, int n2){
  return n1<n2;
}