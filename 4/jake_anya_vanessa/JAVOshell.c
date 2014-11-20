#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "executor.h"


int main(){

  while(1){

    char input[256];
    printf("JAVO:> ");
    fgets(input, sizeof(input), stdin);
    int i = 0;
    while(input[i] != '\n') {
      i++;
    }
    input[i] = 0;
    if(!strcmp(input,"exit")){
      exit(-1);
    }
    else if(!strcmp(input,"cd")){
      //do cd stuff
    }
    int f = fork();
    wait();
    if (!f){
      execute(input);
    }
  }
  
  return 1;

}
