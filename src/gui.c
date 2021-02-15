#include <stdio.h>

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


void main(){
  userInputGUI();
  char name[100] = "Nadia ";
  int i;
  for(i = 0; i < 7; i = i+1){
    printf("%i\n", space_char(name[i]));
    printf("%i\n", non_space_char(name[i]));
  }
}
