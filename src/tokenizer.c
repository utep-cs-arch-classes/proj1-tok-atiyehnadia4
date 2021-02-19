#include "tokenizer.h"
#include <stdio.h>


int space_char(char c){
  if(c == '\n' || c == '\t' || c == ' '){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  return !space_char(c);
}


char *word_start(char *str){
  char *c = str;
  while(space_char(*c)){
    c++;
  }
  if(*c != '\0'){
    return c;
  }
}

char *word_end(char *str){
  char *c = str;
  while(space_char(*c)){
    c++;
  }
  if(*c != '\0'){
    return  c + 1;
  }  
}
   
int count_words(char *str){
}
