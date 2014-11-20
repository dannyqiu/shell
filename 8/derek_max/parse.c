#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "execute.h"
#include <errno.h>

char ** parse(char * input){
  char buf[256];
  strcpy(buf, input);
  buf[strlen(buf)] = '\0';
  char* running=malloc(sizeof(buf));
  strcpy(running, buf);
  int i = 0;
  char** args = calloc(5,256);
  char* prev, prev2;
  while(1){

    prev = strsep(&running, ";");
    if(!prev){
      break;
    }
    args[i] = prev;
    i++;
  }
  printf("%s\n%s\n\n", args[0], args[1]);
  return args;
}

int main(){
  parse("ls -l; touch cat");
}
