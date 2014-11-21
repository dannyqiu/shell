#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>



void parse(char *input);
void mycd(){
  printf("changed\n");
}

/*
void mycd (char* arg) {
  int err;
  char *path = strsep(&arg, "\n");
  char current [256];
  getcwd (current, sizeof(current));
  strcat(current, "/");
  strcat(current, path);
  err = chdir(current);
  if (err=-1) {
    printf("Error");
  }
}
 */




void redirect(char *input){
  if (strchr(input, '>')){
    char *p = strstr(input, "> ");
    int pend = strcspn(p + 2, " \n");
    char fileoutput[64];
    strncpy(fileoutput, p + 2, pend);
    printf("%s\n", fileoutput);
    int fdout = open(fileoutput, O_WRONLY |  O_CREAT | O_APPEND);
    dup(STDOUT_FILENO
  }
  
  
  else{
    parse(input);
  }
}
void parse(char* input){
 
  char **commands = (char **) calloc(64, sizeof(char *));
  int i ;
  int numArgs = 0;
  char *tmp = 0;
  tmp = strtok(input, " \n");

  if (tmp == 0){
    return;
  }
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
    //printf("%s\n", path);
    char usr[256];
    strcpy(usr,getenv("USER"));

    char *p = strstr(path,usr);
    p += strlen(usr) + 1;
 
    
    printf("%s:~/%s$ ",usr,p);
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
      redirect(commands[i]);
    }
    for (i= 0; i < numArgs; i++){
      free(commands[i]);
    }
    free(commands);
  }
}
