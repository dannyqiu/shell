#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  printf("Welcome to the The Magic Conch Shell.\n");
  char cwd[200];
  char s[200];
  while(1){
    getcwd(cwd,sizeof(cwd));
    printf("%s$ ",cwd);
    fgets(s,200,stdin);
    
	   
  }
}

    
