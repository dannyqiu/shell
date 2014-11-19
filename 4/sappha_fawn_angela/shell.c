#include "shell.h"


static void sighandler(int signo){
  if (signo == SIGINT){
    exit(0);
  }
}

int main() {
  signal(SIGINT, sighandler);
  while(1) {
    printprompt();
    execute();
  }
  return 0;
}

void printprompt() {
  char* wd[256];
  //getcwd(wd, sizeof(wd));
  printf("owl:%s$ ", wd);
}

//I don't think this works for | calls...
//so we can use this specifically if there is no | aka not calling two different things in one line
void execute(){
  char s[256];
  fgets(s, sizeof(s), stdin);
  char* s1 = s; 
  char *sep;
  char** args = NULL;
  int i = 0;
  s1 = strsep(&s1, "\n");  

  //parsing our command
  while (sep = strsep(&s1, " ")){
    i++;
    args = realloc(args, sizeof(char*)*i);
    args[i-1] = sep;
  }
  args[i] = 0;
  //printf("args[0]:%s\n", args[0]);
  if (strcmp(args[0], "exit") == 0) { //if calling exit
    //printf("%s", args[0]);
    exit(0);
  }
  else if (strcmp(args[0], "cd") == 0) {//if calling cd
  
  }
  else { //otherwise, we need to fork
    //printf("%s", args[0]);
    int f, status;
    f = fork();
    if (f == 0) {//child process
      execvp(args[0], args);
    }
    else {//parent process
      wait(&status);
    } 
  }
  free(args);
}
