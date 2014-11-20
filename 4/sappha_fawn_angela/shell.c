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
  char* s2 = s;
  char *sep1, *sep2;
  char** args2 = NULL;
  char** args1 = NULL;
  
  int i = 0;
  int j = 0;

  //parsing command on ";"
  s1 = strsep(&s1, "\n");
  while (sep1 = strsep(&s1, ";")){
    j ++;
    args1 = realloc(args1, sizeof(char*)*j);
    args1[j - 1] = sep1;
    //parsing command on " "
    while (sep2 = strsep(&s2, " ")){
      i++;
      args2 = realloc(args2, sizeof(char*)*i);
      args2[i-1] = sep2;
    }
    args2[i] = 0;
    /*printf("%s", args1[j - 1]);
    printf("---");
    printf("%s\n", args2[i - 1]);*/
  }
  args1[j] = 0;
  
  //printf("args2[0]:%s\n", args2[0]);
  if (strcmp(args2[0], "exit") == 0) { //if calling exit
    //printf("%s", args2[0]);
    exit(0);
  }
  else if (strcmp(args2[0], "cd") == 0) {//if calling cd
    
  }
  else { //otherwise, we need to fork
    //printf("%s", args2[0]);
    int f, status;
    f = fork();
    if (f == 0) {//child process
      execvp(args2[0], args2);
    }
    else {//parent process
      wait(&status);
    } 
  }
  free(args2);
  free(args1);
}
