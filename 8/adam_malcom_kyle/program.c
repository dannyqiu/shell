#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute(char * start){
  //execute: Takes a char pointer start representing the beginning f a String
  //Splits the string arguements and runs them with a child process and execvp
  //Returns nothing
  printf("%s\n",start);
  char * args[10];
  int x = 0;
  char * y;
  while (start){
    y = strsep(&start, " ");
    args[x] = y;
    x++;
  }
  args[x -1] = strsep(&args[x-1], "\n");
  args[x]=0;
  int f = fork();
  if (!f){
    //printf("running: %s %s\n",args[0],args[1]);
    //execl("/bin/ls","ls","-l",NULL);
    execvp(args[0],args);
  }
  else{
    wait(&f);
  }
}

int main(int argc, char *argv[]){

  while(1){
    printf("input: ");
    char input[256];
    fgets(input, 256, stdin);
    printf("\n");
    char * start = &input[0];
    char * y;
    while (start){
      execute(strsep(&start, ";"));
      
    }
  
    
  }
  return 0;
}
    
