#include <stdio.h>
#pragma warning(disable:4996)

typedef void(* func)(void);

void Fantasy(void);
void Action(void);
void Horror(void);
func GetFuncPointer(int index);

void main(void){
  int menu;

  void(* funct)(void) = NULL;

  while(1){
    printf("[0]Exit [1]Fantasy [2]Action [3]Horror - ");
    scanf("%d", &menu);
    if(menu==0){
      break;
    }
    funct = GetFuncPointer(menu);
    funct();
  }
}

void Fantasy(void){
  printf("Fantasy\n");
}
void Action(void){
  printf("Action\n");
}
void Horror(void){
  printf("Horror\n");
}

func GetFuncPointer(int index){
  void (* func[])(void) = {Fantasy, Action, Horror};
  return func[index-1]; 
}
// func GetFuncPointer(int index){
//   void (* func)(void) = NULL;
//   switch(index){
//     case 1: func = Fantasy; break;
//     case 2: func = Action; break;
//     case 3: func = Horror; break;
//   }
//   return func;
// }