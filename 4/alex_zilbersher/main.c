#include "shell.h"
//
int f=0;

static void sighandler(int signo) {
  if (signo==SIGINT){ // contrl-c or kill -2
    if(f){
      wait(&f);
      printf("\nExited Zilbash\n");
      exit(-1);
    }else{
      exit(-1);
    }
  }
}

int main(){
  while(1){
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    f = fork();
    if(f){
      wait(&f);
    }else{
      run();
    }
  }
}
