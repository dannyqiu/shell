#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
  while(1){
    
    char prompt[4096];
    wait();
    strcpy(prompt,"Shell:");//add directory and username
    printf("%s", prompt);
    char input[4096];
    fgets(input, 4096, stdin);
    //Parse Input
    strtok( input, "\n");
    int count = 0;
    char *p = input;
    while(*p){
      if(*p == ' '){
	count++;
      }
      p++;
    }
    char * arg = strtok(input, " ");
    char ** args = (char **)malloc(sizeof(char *)* count+1);
    args[0] = arg;
    int i = 0;
    while(arg){
        i++;
        arg = strtok(NULL, " ");
        args[i] = arg;
    }
    
   
    if(strcmp(args[0],"exit") == 0){
      exit(0);
    }else if(strcmp(args[0],"cd\n") == 0){
      //need to parse input
      //add stuff here
    }else{
      int f = fork();
      if(!f){
	execvp(args[0],args);
	printf("Command not found\n");
      }
    }
    /*
    i = 0;
    
    while(args[i]){
      printf("%s\n",args[i]);
      i++;
    }
    */
  }
  
}
