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

char *copy_str(char *inStr, short len){
  char * new_src = (char *)malloc(sizeof(char)*len+1);
  int i;

  for(i = 0; i < len; i++){
    new_src[i] = inStr[i];
  }
  new_src[i] = '\0';
  return new_src;
  
}
char **tokenize(char* str){
  int i;
  int num_words = count_words(str);
  char **tokens = (char **)malloc(sizeof(char*)*(num_words+1));

  char *start = str;
  char *end = str;

  for(i = 0; i < num_words; i++){
    start = word_start(end);
    end = word_end(start);
    tokens[i]= copy_str(start, end-start);
  }
  tokens[i] = '\0';
  return tokens;
}


void print_tokens(char **tokens){
  int i;
  i = 0;
  while(tokens[i] != 0){
    printf("\ntokens[%i] ='%s'",i,tokens[i]);
    i++;
  }
  printf("\ntokens[%i] ='%s'",i, tokens[i]);
  printf("\n");
}

void free_tokens(char **tokens){
  int i = 0;
  while(tokens[i] != 0){
    free(tokens[i]);
    //printf("\ntokens[%i] = '%s'", i, tokens[i]);
    i++;
  }
  free(tokens[i]);
  //printf("\ntokens[%i] = '%s'", i, tokens[i]);
  free(tokens);
}
