#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

<<<<<<< HEAD
int execute(char s[256]) {

=======
int execute() {
  char s[256];
  printf("JAVO:> ");
  fgets(s, sizeof(s), stdin);
  int i = 0;
  while(s[i] != '\n') {
    i++;
  }
  s[i] = 0;
>>>>>>> 3297b7ba4fbb5ba18ffa417a2915eeac1601a943
  char *s1 = s;
  char *s2;
  char *arg[256];
  
  int i = 0;
  while(s2) {
    s2 = strsep(&s1, " ");
    arg[i] = s2;
    i++;
  }
  arg[i+1] = 0;
  
  execvp(arg[0], arg);
  return 0;
}
