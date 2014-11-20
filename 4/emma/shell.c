#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
  printf("$ ");
  char command [256];
  fgets(command, 256, stdin);

  command[strlen(command) - 1] = 0;

  char * s1 = command;
  char * s2;
  char * strsep_array[256];
  int i = 0;

  while (s2 = strsep(&s1, ";")){
    strsep_array[i] = s2;
    i++;
  }

  command[i] = 0;

  int j = 0;
  /*
  for (j; j < i; j++){
    printf ("command[%d]: %s\n", j, a[j]);
  }
  */

  for (j; j < i; j++){
    int k = 0;
    fork();
    char * a1 = strsep_array[j];
    char * a2;
    char * exec_array[256];
    while (a2 = strsep(&a1, " ")){
      exec_array[k] = a2;
      k++;
    }
    execvp(exec_array[k], exec_array);
  }
  //execvp(a[0], a);
  
  return 0;
}
