#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


char* getUserInput(){
  char* userInput = malloc(100);
  int i;
  char inputChar;

  while((inputChar = getchar()) != '\n'){
    userInput[i] = inputChar;
    i = i + 1;
    putchar(inputChar);
  }
  userInput[i] = '\0';

  return userInput;
}

void getHistory(List* history){
  char histChar;
  char intKeyStr[3];
  char exPoint;
  int i;
  
  printf("\nWould you like to view your full history or individual history(F or I):\n");
  histChar = getchar();
  histChar = getchar();
  
  if(histChar == 'F'){
    print_history(history);
  }
  if(histChar == 'I'){
    printf("\nPlease enter the int key of history. (ex !1) \n");
    exPoint = getchar();
    i = 0;
    while((exPoint = getchar()) != '\n'){
      intKeyStr[i] = exPoint;
      i = i + 1;
    }
    printf("%s\n", intKeyStr);
    printf("\n%s\n", get_history(history,intKeyStr[1]- '0'));
  }
  
}

void userInputGUI(){
  char *userInput;
  char inputChar;
  char **tokens;
  List* history = init_history();
  int cont = 1;
  char conChar;

  while(cont){
    userInput = (char*)malloc(100);
    printf("Please enter string\n");
    userInput = copyStr(userInput, getUserInput());
    
    printf("\n");
    tokens = tokenize(userInput);
    print_tokens(tokens);
    printf("\n");
    add_history(history, userInput);
    free_tokens(tokens);
    printf("\n");
    printf("\nContinue (Y or N)\n");
    conChar = getchar();
    if(conChar == 'Y'){
      cont = 1;
      userInput = copyStr(userInput, getUserInput());
    }
    else{
      cont = 0;
    }
  }
  
  getHistory(history);
  free_history(history);
}


void main(){
  userInputGUI();
}
