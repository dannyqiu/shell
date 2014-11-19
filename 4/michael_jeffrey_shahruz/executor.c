#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
  printf("What do you want to do? ");
  char s[256];
  fgets( s, 256, stdin );

  char* pars = s;
  char* cmd = strsep( &pars, " ");
  // printf("cmd: %s\npars: %s", cmd, pars);

  char path[200];
  strcpy(path, "/bin/");
  strcat(path, cmd);
  char* temp = pars;
  strsep( &temp, "\n");

  //printf("path: %s\n", path);
  //printf("pars: %s\n", pars);

  char** args = NULL;
  int k = 1;
  args = (char**)malloc(sizeof(char *));
  args[0] = cmd;
  while( pars ){
    args = realloc(args, sizeof(char *) * (k+1) );
    args[k] = strsep( &pars, " ");
    //    printf("args[%d]: %s\n", k, args[k]);
    k++;
  }
  args[k] = NULL;

  char* test[4];
  test[0] = "ls";
  test[1] = "-a";
  test[2] = "-l";
  test[3] = NULL;

  free(args);
  
  execvp(path, args);
  return 0;
}
