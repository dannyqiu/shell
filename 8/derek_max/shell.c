#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

//#include "parse.h"
#include "execute.h"

int main(){
  printf("> ");
  
  char s[256];
  //fgets (s, 256, stdin);
  char* s1 = s;
  //char** commands = calloc(5, 256);
  char* commands[] = {"ls -al", "echo hi", "exit"};
  //commands is null-terminated
  //parse here into commands
  int i = 0;
  //  commands[0] = "ls -al";
  //  commands[1] = "echo hi";
  //  commands[2] = "exit";
  while(commands[i]){
    printf("commands[%d]:%s\n", i, commands[i]);
    strstr("exitls -al", "exit");
    strstr("exitls -al", "exit");
    printf("%s\n", strstr("exitls -al", "exit"));

    //    printf("%s", b);
	   //    printf("%s\n", strstr(commands[i], "exit"));    


    printf("%d", 9999999);
    if(strlen(strstr(commands[i], "exit")) == strlen(commands[i])){ //only if "exit" is in the very beginning will there be no difference
      //have to add special case for no input I think...?

      printf("Exiting.\n");
      exit(EXIT_SUCCESS);
    }
    execute(commands[i]);
    i++;
  }
}
