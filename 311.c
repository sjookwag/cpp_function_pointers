#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996);

enum {ARRAY_SIZE=13};
enum {QUIT, TITLE, PRICE, PAGE, MENU_COUNT};

typedef struct{
  char title[32];
  int price;
  int page;
}
BOOK;

void InitBooks(BOOK* books, int size);
int SelectMenu(void);
void PrintBooks(BOOK* books, int size);

int compareTitle(const void* p1, const void* p2);
int comparePrice(const void* p1, const void* p2);
int comparePage(const void* p1, const void* p2);

void main(void){
  int (* compareFuncs[])(const void*, const void*) =
  {
    NULL, compareTitle, comparePrice, comparePage
  };
  BOOK books[ARRAY_SIZE];
  int select;

  InitBooks(books, ARRAY_SIZE);
  printf("[before sorting]\n");
  PrintBooks(books, ARRAY_SIZE);
  while(1){
    select = SelectMenu();
    if(select==QUIT)
      break;
    qsort(books, ARRAY_SIZE, sizeof(books[0]), compareFuncs[select]);
    PrintBooks(books, ARRAY_SIZE);
  }
}

void InitBooks(BOOK* books, int size){
  BOOK shelf[13]={
    "12",32000,890,
    "07",16000,425,
    "05",34000,1079,
    "08",37000,859,
    "06",30000,497,
    "04",26000,699,
    "10",40000,1127,
    "01",42000,1275,
    "02",44000,779,
    "13",17000,423,
    "11",22000,454,
    "09",12000,248,
    "03",23000,560,
  };
  for(int i=0; i<size; i++)
    books[i]=shelf[i%13];
}

int SelectMenu(void){
  char menu[32];
  int index = -1;
  
  do
  {
    printf("[MENU] quit title price page - ");
    scanf("%s", menu);
    fflush(stdin);
         if(strcmp(menu,"quit")==0) index=QUIT;
    else if(strcmp(menu,"title")==0) index=TITLE;
    else if(strcmp(menu,"price")==0) index=PRICE;
    else if(strcmp(menu,"page")==0) index=PAGE;
  }
  while(index<0||index>=MENU_COUNT);
  return index;
}
void PrintBooks(BOOK* books, int size){
  for(int i=0; i<size; i++)
    printf("%-30s %5d %4d\n", books[i].title, books[i].price, books[i].page);
  printf("\n");
}

int compareTitle(const void* p1, const void* p2){
  BOOK* pb1=(BOOK*) p1;
  BOOK* pb2=(BOOK*) p2;
  return strcmp(pb1->title, pb2->title);
}
int comparePrice(const void* p1, const void* p2){
  return ((BOOK*) p1)->price - ((BOOK*) p2)->price;
}
int comparePage(const void* p1, const void* p2){
  return ((BOOK*) p1)->page - ((BOOK*) p2)->page;
}