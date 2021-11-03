#include <stdio.h>
#include <string.h>
#include "212_chair.h"
#pragma warning(disable:4996)

void InputChair(CHAIR* pChair);
void OutputChair(const CHAIR* pChair);

void InitChair(CHAIR* pChair){
  memset(pChair, 0, sizeof(CHAIR));
  pChair->Input = InputChair;
  pChair->Output = OutputChair;
}

void InputChair(CHAIR* pChair){
  printf("[Input]\n");
  printf("[Model]: "); scanf("%s",pChair->model);  
  printf("[Price]: "); scanf("%d",pChair->price); //fflush(stdin);
  printf("[ Size]: "); scanf("%d",pChair->size);
}

void OutputChair(const CHAIR* pChair){
  printf("[Output]\n");
  printf("[ Model]:%s\n",pChair->model);
  printf("[ Price]:%d\n",pChair->price);
  printf("[  Size]:%d\n",pChair->size); 
}
