#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "executor.h"


int main(){

  chdir(getenv("HOME"));
  printf("error: %s\n", strerror(errno));
  
  while(1){

    char input[256];
    char cwd[256];
    getcwd(cwd,256);
    printf("JAVO:>%s ",cwd);
    fgets(input, sizeof(input), stdin);
    int i = 0;
    while(input[i] != '\n') {
      i++;
    }
    input[i] = 0;
    if(!strcmp(input,"exit")){
      exit(-1);
    }
    else if(input[0]=='c' && input[1]=='d'){
      execute(input);
    }
    int f = fork();
    wait();
    if (!f){
      execute(input);
    }
  }
  
  return 1;

}
