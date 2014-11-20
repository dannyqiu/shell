#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char** parse(char* input, char* s){
  strtok( input, "\n");
    int count = 0;
    char *p = input;
    while(*p){
      if(*p == *s){
	count++;
      }
      p++;
    }
    char * arg = strtok(input, s);
    char ** args = (char **)malloc(sizeof(char *)* count+1);
    args[0] = arg;
    int i = 0;
    while(arg){
        i++;
        arg = strtok(NULL, s);
        args[i] = arg;
    }
    return args;
}

int main(){
  while(1){
    //Prompt
    char prompt[4096];
    wait();
    strcpy(prompt,"Shell:");//add directory and username
    printf("%s", prompt);
    getcwd(prompt, sizeof(prompt));
    printf("%s$ ", prompt);
    
    char input[4096];
    fgets(input, 4096, stdin);

    //attempt at semicolon
    char ** superargs = parse(input,";"); 
    
    char ** args = parse(input," ");

   
    
    
    //Executes input
    if(strcmp(args[0],"exit") == 0){
      exit(0);
    }else if(strcmp(args[0],"cd") == 0){
      chdir(args[1]);
    }else{
      int f = fork();
      if(!f){
	execvp(args[0],args);
	printf("Command not found\n");
      }
    }
    
  }
  
}
