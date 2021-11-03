#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

void First(void);
void Second(void);
void Third(void);

void main(void){
  printf("------ before atexit() -------\n");  
  atexit(First);
  atexit(Second);
  atexit(Third);
  printf("------ after atexit() -------\n");  
}

void First(void){
  printf("First() \n");
}

void Second(void){
  printf("Second() \n");  
}

void Third(void){
  printf("Third() \n");  
}