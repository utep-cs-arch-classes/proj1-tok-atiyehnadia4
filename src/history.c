#include "history.h"
#include <stdio.h>
#include <stdlib.h>

char* copyStr(char* dest, char* src){
  int i;
  for(i = 0; src[i] != '\0'; i++){
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return dest;
}

int numChar(char *str){
  int i;
  int count = 0;
  i = 0;
  while(str[i] !='\0'){
    count++;
    i++;
  }
  return count;
}

List* init_history(){
  List* history;
  history = (List*)malloc(sizeof(List));
  history->root = NULL;
  return history;
  
}

void add_history(List *list, char *str){
  Item* node = (Item *)malloc(sizeof(Item));
node->str = (char *)malloc(sizeof(char) * numChar(str));
  node->str = copyStr(node->str, str);
  node->next = NULL;

  Item* curr = list->root;
  if(curr == NULL){
    node->id = 0;
    list->root = node;
  }
  else{
    while(curr != NULL && curr->next != NULL){
      curr = curr->next;
    }
    node->id = curr->id+1;
    curr->next = node;
  }
}
char *get_history(List *list, int id){
  Item* curr = list->root;
  if(id == 0){
    return list->root->str;
  }
  else{
    while(curr != NULL){
      if(curr->id == id){
	return curr->str;
      }
      curr = curr->next;
    }
  }
  return NULL;
  
}

void print_history(List *list){
  Item* curr = list->root;
  while(curr != NULL){
    printf("\n%i: %s\n", curr->id, curr->str);
    curr = curr->next;
  }
  
}

void free_history(List *list){
  Item* curr = list->root;
  while(curr != NULL){
    Item* temp = curr;
    curr = curr->next;
    free(temp);
  }
  free(list);
}
