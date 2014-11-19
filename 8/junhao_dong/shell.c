#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>


void execute(){
  char *input = (char *) malloc(256);
  fgets(input, 256, stdin);

  int argc = 0;
  char *argv[256];
  char *arg;
  
  for (arg = strsep(&input," \n"); *arg; arg = strsep(&input, " \n"), argc++)
      argv[argc] = arg;

  argv[argc] = NULL;
  
  execvp(argv[0], argv);
}

static void sighandler(int signo){
  int f, fd, status;

  if(signo == SIGUSR1){
    printf("SIGUSR1 received.\n");
    fd = open("whoOut.txt", O_APPEND | O_WRONLY | O_CREAT);
    dup2(fd, STDOUT_FILENO);
    execlp("who","who",NULL);
  }
  else if(signo == SIGUSR2){
    printf("SIGUSR2 received.\n");
    fd = open("whoOut.txt", O_APPEND | O_WRONLY | O_CREAT);
    dup2(fd, STDOUT_FILENO);
    execlp("ps","ps",NULL);
  }
  else if(signo == SIGINT){
    f = fork();

    if (f==0){
      printf("\n\nPrinting whoOut.txt (who):\n");
      execlp("cat","cat","whoOut.txt",NULL);
    }else{
      wait(&status);
      printf("\n\nPrinting psOut.txt (ps):\n");
      execlp("cat","cat","psOut.txt",NULL);
    }
  }
}

int main(){
  signal(SIGUSR1,sighandler);
  signal(SIGUSR2,sighandler);
  signal(SIGINT,sighandler);
  while (1){
    printf("running with pid:    %d\n", getpid());
    sleep(1);
  }
}

int main(){
  printf("Enter a command...\n");
  printf("$ ");
  execute();
}
