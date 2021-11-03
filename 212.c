#include "212_chair.h"

void main(void){
  CHAIR chair;

  InitChair(&chair);  

  chair.Input(&chair);
  chair.Output(&chair);

}