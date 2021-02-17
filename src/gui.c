#include <stdio.h>
#include <tokenizer.h>

void userInputGUI(){
  char userInput[100];
  int i;
  char inputChar;
  printf("Please input a string\n");
  while(inputChar != '\n'){
    inputChar = getchar();
    userInput[i] = inputChar;
    i = i+1;
  }
  printf("%s\n", userInput);
}


void main(){
  userInputGUI();
}
