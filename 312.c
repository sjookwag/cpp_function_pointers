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
void PrintBooks(BOOK* books, int size);
int compareTitle(const void* p1, const void* p2);

void main(void){
  BOOK books[ARRAY_SIZE];
  BOOK input;
  BOOK* find=NULL;

  InitBooks(books, ARRAY_SIZE);
  qsort(books, ARRAY_SIZE, sizeof(books[0]), compareTitle);  
  PrintBooks(books, ARRAY_SIZE);
  printf("[Exit] quit\n");

  while(1){
    printf("Title(quit): ");
    gets(input.title);
    fflush(stdin);
    if(strcmp(input.title,"quit")==0)
      break;
    find=bsearch(&input, books, ARRAY_SIZE, sizeof(books[0]), compareTitle);
    if(find!=NULL)
      printf("Result: %s %d %d\n", find->title, find->price, find->page);
    else
      printf("Result: No Found!\n");
  }
}

void InitBooks(BOOK* books, int size){
  BOOK shelf[ARRAY_SIZE]={
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
    books[i]=shelf[i%ARRAY_SIZE];
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
