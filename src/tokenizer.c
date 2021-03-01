#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>


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
  while(space_char(*c) && *c != '\0'){
    c++;
  }
  if(*c == '\0'){
    return 0;
  }
  return c;
}

char *word_end(char *str){
  char *c = str;
  while(non_space_char(*c) && *c != '\0'){
    c++;
  }
  return c;
}


int count_words(char *str){
  char *c = str;
  if(word_start(str) == 0){
    return 0;
  }
  if(*word_end(word_start(str))== 0){
    return 1;
  }
  return count_words(word_end(word_start(str)))+1;
}

char *copy_str(char *src, short len){
  char * new_src = (char *)malloc(len);
  int i;

  for(i=0; i<len;i++){
    *(new_src + 1) = src[i];
  }
  return new_src;
  
}


void print_tokens(char **tokens){
  int i;
  i = 0;
  while(tokens[i] != 0){
    printf("\n%s\n", tokens[i]);
    i++;
  }
}

void free_tokens(char **tokens){
  int i;
  i = 0;

  while(tokens[i] != 0){
    free(tokens[i]);
  }
  free(tokens[i]);
  free(tokens);
}
