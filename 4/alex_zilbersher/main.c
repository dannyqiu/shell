#include "shell.h"

static void sighandler(int signo) {
  if (signo==SIGINT){ // contrl-c or kill -2
    kill(getppid(),SIGUSR1);
    //exit(-1);
  }
  if (signo == SIGUSR1){ //kill -30
    printf("\nExited Zilbash\n");
    //exit(-1);
  }
}

int main(){
  while(1){
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    int f = fork();
    if(f){
      wait(&f);
    }else{
      char s[256];
      printf("@&Z ");
      fgets(s,255,stdin);
      s[strlen(s)-1]=0;
      char *args[256];
      char *s1=s;
      char *s2;
      int i=0;
      while(s2=strsep(&s1," ")){
	args[i]=s2;
	i++;
      }
      args[i]=0;
      execvp(args[0],args);
    }
  }
}
