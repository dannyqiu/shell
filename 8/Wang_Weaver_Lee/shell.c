#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void mycd(){
  printf("changed\n");
}



void parse(char* input){
  char **commands = (char **) calloc(64, sizeof(char *));
  int i ;
  int numArgs = 0;
  char *tmp = strtok(input, " \n");
  do {
    commands[numArgs] = (char *) calloc(64, sizeof(char));
    strcpy(commands[numArgs], tmp);
    numArgs++;
  } while(tmp = strtok(NULL, " \n"));
  commands[numArgs]=0;

  if(strcmp(commands[0], "cd") == 0){
    mycd(input);
    for (i= 0; i < numArgs; i++){
	free(commands[i]);
      }
      free(commands);
  }
  else if(strcmp(commands[0], "exit") == 0){
    for (i= 0; i < numArgs; i++){
	free(commands[i]);
      }
      free(commands);
    exit(-1);
  }
  else{
  
    int p = fork();
    if(p){
      wait();
      for (i= 0; i < numArgs; i++){
	free(commands[i]);
      }
      free(commands);
    }
    else{
      execvp(commands[0], commands);
    }
    
  }
}
int main(){
  while(1){
    char path[256];
    getcwd(path,sizeof(path));
    printf("%s\n", path);
    char usr[256];
    strcpy(usr,getenv("USER"));
    
    printf("%s:~/%s$ ",usr,path);
    char input[256];
    fgets(input,sizeof(input),stdin);
    char *tmp = strtok(input, ";");
    char **commands = (char **) calloc(64, sizeof(char *));
    int numArgs = 0;
    do {
      commands[numArgs] = (char *) calloc(64, sizeof(char));
      strcpy(commands[numArgs], tmp);
      numArgs++;
    } while(tmp = strtok(NULL, ";"));
    commands[numArgs]=0;

    int i;
    for(i = 0; i<numArgs; i++){
      parse(commands[i]);
    }
    for (i= 0; i < numArgs; i++){
      free(commands[i]);
    }
    free(commands);
  }
}
