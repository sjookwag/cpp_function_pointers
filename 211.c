#include <stdio.h>
#pragma warning(disable:4996)

typedef struct _CHAIR {
  char model[32];
  int price;
  char size;
} CHAIR;

void InputChair(CHAIR* pChair);
void OutputChair(const CHAIR* pChair);

void main(void){
  CHAIR chair;

  InputChair(&chair);
  OutputChair(&chair);

}

void InputChair(CHAIR* pChair){
  printf("[Input]\n");
  printf("[Model]: "); scanf("%s",pChair->model);
  printf("[Price]: "); scanf("%d",pChair->price); //fflush(stdin);
  printf("[ Size]: "); scanf("%c",pChair->size);
}
void OutputChair(const CHAIR* pChair){
  printf("[Output]\n");
  printf("[ Model]:%s\n",pChair->model);
  printf("[ Price]:%d\n",pChair->price);
  printf("[  Size]:%c\n",pChair->size); 
}
