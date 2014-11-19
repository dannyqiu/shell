#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
  while(1){
    
    char prompt[4096];
    strcpy(prompt,"Shell:");//add directory and username
    printf("%s", prompt);
    char input[4096];
    fgets(input, 4096, stdin);
    printf("%d",strcmp(input,"exit"));
    if(strcmp(input,"exit\n") == 0){
      exit(0);
      printf("exited");
    }
    printf("%s",input);
  }
  
}
