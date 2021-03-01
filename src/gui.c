#include <stdio.h>
#include "tokenizer.h"

void userInputGUI(){
  char userInput[100];
  int i;
  char inputChar;
  printf("Please input a string\n");
  i = 0;
  while((inputChar = getchar()) != '\n'){
    userInput[i] = inputChar;
    i = i+1;
    putchar(inputChar);
  }
  userInput[i] = '\0';
  //printf("\n%c\n", *word_start(userInput));
  //printf("\n%c\n", *word_end(userInput));
  printf("\n%i\n", count_words(userInput));
  
}


void main(){
  userInputGUI();
}
