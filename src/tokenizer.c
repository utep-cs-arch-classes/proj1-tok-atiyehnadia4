#include "tokenizer.h"

#include <stdio.h>

int space_char(char c){
  int count;
  count = 0;
  if(c < 21){
    count = count + 1;
  }
  return count;
}

int non_space_char(char c){
  int count;
  count = 0;
  if(c > 20){
    count = count + 1;
  }
  return count;
}
