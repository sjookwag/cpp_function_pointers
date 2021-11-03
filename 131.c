#include <stdio.h>
#pragma warning(disable:4996)

void Hello(void);
void GoodNight(void);
void WhatsUp(void);

void main(void){
  void (* func[])(void) = {Hello, GoodNight, WhatsUp};
  int menu;

  while(1){
    printf("[0] Quit [1] Hello [2] GoodNight [3] WhatsUp - ");
    scanf("%d", &menu);
    if(menu<0 || menu>3)
      continue;
    if(menu==0)
      break;    
    func[menu-1]();
  }  
}

void Hello(void){
  printf("Hello\n");
}

void GoodNight(void){
  printf("Good night\n");
}

void WhatsUp(void){
  printf("What's Up?\n");
}