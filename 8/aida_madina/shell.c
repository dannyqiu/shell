#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main() {
  
  char command[200];
  char *args = command;
  char *args_array[10];
  int num_args = 0;
  int pid;
  
  while(1) {
    printf("\nseashell$ ");
    fgets(command, sizeof(command), stdin);
    command[strlen(command)-1]='\0';

    if (!strchr(command, ' ')){
      printf("You want to: %s\n", command);
      pid = fork();
      execlp(command, command, NULL);
    }

    else {
      char *p = command;

      while (*p){
	if (*p == ' '){
	  num_args++;
	}
	p++;
      }

      char *comm = strtok(args, " ");
      int i = 1;
      args_array[0]=comm;
      while (i <= num_args) {
	args_array[i] = strtok(NULL, " ");
	i++;
      }
      args_array[i]=NULL;
      execvp(args_array[0], args_array);

    }
  }
  return 0;
}

