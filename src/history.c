#include "history.h"
#include <stdio.h>
#include <stdlib.h>


List* init_history(){
  List* history;
  history = (List*)malloc(sizeof(List));
  history->root = NULL;
  return history;
  
}
