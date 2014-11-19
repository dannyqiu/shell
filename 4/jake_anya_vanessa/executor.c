#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int execute() {
  char s[256];
  printf("What would you like to do? ");
  fgets(s, sizeof(s), stdin);
  int i = 0;
  while(s[i] != '\n') {
    i++;
  }
  s[i] = 0;
  char *s1 = s;
  char *s2;
  char *arg[256];
  i = 0;
  while(s2) {
    s2 = strsep(&s1, " ");
    arg[i] = s2;
    i++;
  }
  arg[i+1] = 0;
  execvp(arg[0], arg);
  return 0;
}
