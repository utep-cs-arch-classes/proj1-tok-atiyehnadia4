#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

int toPow(int base, int pow){
  if(pow == 0){
    return 1;
  }
  return base * toPow(base, pow-1);
}


void getHistory(List* history){
  char intKeyStr[100];
  char exPoint;
  int i;
  int cont2 = 1;
  char conChar;
  char histChar;

  
  while(cont2){
    printf("\nWould you like to view your full history, individual history, or exit? (F,I, or E): ");
    histChar = getchar();
    histChar = getchar();

    if(histChar == 'F'){
      print_history(history);
      printf("\n");
      printf("Continue? (Y or N):  ");
      conChar = getchar();
      conChar = getchar();
      if(conChar == 'Y'){
	cont2 = 1;
      }
      else{
	cont2 = 0;
      }
    }
    else if(histChar == 'I'){
      printf("\nPlease enter the int key of history. (ex !1) \n");
      exPoint = getchar();
      i = 0;
      while((exPoint = getchar()) != '\n'){
	intKeyStr[i] = exPoint;
	i = i + 1;
      }
      intKeyStr[i] = '\0';
      printf("%s\n", intKeyStr);

      int j;
      int finalKey = 0;
      i = i - 1;
      for(j = i; j >= 1; j--){
	finalKey = finalKey + ((intKeyStr[j] - '0') * toPow(10, j));
      
      }
      printf("\n%s\n", get_history(history, finalKey));
      printf("\n");
      printf("Continue? (Y or N):  ");
      conChar = getchar();
      
      if(conChar == 'Y'){
	cont2 = 1;
      }
      else{
	cont2 = 0;
      }
  }

    if(histChar == 'E'){
      cont2 = 0;
    }
  }
  free_history(history);
  printf("Thank you! Exiting\n");
}
    
 
void userInputGUI(){
  char *userInput;
  char inputChar;
  char **tokens;
  List* history = init_history();
  int cont = 1;
  int cont2 = 1;
  char histChar;
  char conChar;

  while(cont){
    userInput = (char*)malloc(100);
    printf("Please enter string\n");
    userInput = copyStr(userInput, getUserInput());
    
    printf("\n");
    tokens = tokenize(userInput);
    print_tokens(tokens);
    add_history(history, userInput);
    free_tokens(tokens);
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
}


void main(){
  userInputGUI();
}
