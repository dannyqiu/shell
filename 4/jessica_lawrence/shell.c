#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>

void prompt(char* s) {
  printf ("shell prompt: ");
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

int main () {
  char s[256];
  while (1) {
    prompt(s);
    int f = fork();
    if(f == 0) {
      docmd(s);
    } else {
      wait();
    }
  }
  return 0;
}
