#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "execute.h"
#include <errno.h>
//#include "strsep.h"

/* char* parseStr(char* str, char* match){ */
/*   int loc; //where to stop */
/*   loc = strcspn(str, match); //saw this in some pico code */
/*   char* done; */
/*   //printf("str: %s\n", str); */
/*   if (loc == strlen(str)){ */
/*     return '\0'; */
/*   } */
/*   printf("loc: %d\n", loc); */
/*   printf("done before: %p\n", done); */
/*   done = *(&str + 1); */
/*   printf("done after: %p\n", done); */
/*   printf("done: %p\n", done); */
/* } */


//Windows doesn't have strsep in string.h.  Really?


int execute(char* input){
  char buf[256]; //we need this for some reason pls don't buffer overflow
  strcpy(buf, input);
  buf[strlen(buf)] = '\0';
  char* running=malloc(sizeof(buf));
  strcpy(running, buf);
  int i = 0;
  char** args = calloc(5,256);
  char* prev;
  while(1){

    prev = strsep(&running, " ");
    if(!prev){
      break;
    }
    args[i] = prev;
    i++;
  }

  pid_t f = fork();
  int status;
  int w;
  if (f > 0){ //parent
    w = wait(&status);
    exit(0);
  }
  else if (f<0){
    exit(EXIT_FAILURE);
  }
  else{
      execvp(args[0], args);
      printf("%s\n", strerror(errno));
      exit(EXIT_FAILURE); //only runs if execvp fails
  }



}

int main(){
  execute("asdfasdfasdjfasdfasdfsd");
}

