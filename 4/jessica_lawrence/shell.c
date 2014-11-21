#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>

void prompt(char* s) {
  printf ("[ :^) ]  ");
  fgets (s, 256, stdin);
}

void docmd(char* s) {
  char *c = s;
  char *t;
  char **args = NULL;
  int i = 0; 
  
  c = strsep (&c, "\n");
  
  while ((t = strsep(&c, " "))) {
    args = realloc (args, sizeof (char *) *(i+1));
    args[i] = t;
    i++;
  }
  
  args [i] = 0;
  execvp (args[0], args);
  free (args);
  printf ("wrong\n");
  exit(0);
}

