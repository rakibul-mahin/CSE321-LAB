#include <stdio.h>

int main(void) {
  FILE *userInput;
  userInput = fopen("task2b_input.txt","r");
  
  FILE *output;
  output = fopen("task2b_output.txt", "w");

  char res[100];

  fgets(res,100,userInput);
  char *tok = strtok(res, " ");
  while(tok != NULL){
    printf("%s ", tok);
    fprintf(output, " %s", tok);
    tok = strtok(NULL, " ");
  }
  
  fclose(userInput);
  return 0;
}
