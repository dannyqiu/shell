#include "shell.h"

int o = 1;

int main() {
  while(o) {
    printprompt();
    execute();
  }
  return 0;
}

void printprompt() {
  char * wd[256];
  //getcwd(wd, sizeof(wd));
  printf("owl:%s$ ", wd);
}

void execute(){
  char s[256];
  fgets(s, sizeof(s), stdin);
  char* s1 = s; 
  char *sep;
  char** args = NULL;
  int i = 0;
  s1 = strsep(&s1, "\n");  
  while (sep = strsep(&s1, " ")){
    i++;
    args = realloc(args, sizeof(char*)*i);
    args[i-1] = sep;
  }
  args[i] = 0;
  if (args[0] != "cd") {
    int f = fork();
    int status;
    if (f == 0)
      execvp(args[0], args);
    else {
      wait(&status);
    }
  }
  else if (args[0] == "exit") {
    o = 0;
    exit(0);
  }
  else
    execvp(args[0], args);
  free(args);
}
