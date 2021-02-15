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
  if(c != '\n'|| c != '\t' || c != ' '){
    count = count + 1;
  }
  return count;
}

int non_space_char(char c){
  if(c == '\n'){
  }
    return 0;
}


void main(){
  userInputGUI();
  char letter;
  letter = 'n';
  printf("%i\n" ,space_char(letter));
}
