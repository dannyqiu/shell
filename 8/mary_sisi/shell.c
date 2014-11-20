#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>


//parse
char** parse(){
 
  char s[256];
  char * ps = s;
  fgets(s, sizeof(s), stdin);
  s[strlen(s)-1]='\0';

  char ** args = (char**)malloc(sizeof(s));

  args[0] = strsep(&ps," ");

  int i=1;

  while(ps){
    args[i] = ps;
    strsep(&ps," ");
    i++;
  }
 
  /*  i=0;
  while(args[i]){
    printf("command:  %s\t",args[i]);
    i++;
    }*/

  return args;

}


int redirection (char * source, char * dest){

  return 0;
}

void print_promt(){
  char path[256];
  getcwd(path, 256);  
  
  printf("%s$ ", path);
}

int main(){

  print_promt();

  while(1){

    char ** a = parse();
    //printf("%s\t",a[0]);

    int i=0;

    while(a[i]){
      printf("command:  %s\t",a[i]);
      i++;
    }

    /*
    if (a[0] == "exit"){
      execlp("exit","exit", NULL);
    }
    if (a[0] == "cd"){
      execvp("cd", a );
      }*/
    //else{
      int f = fork();
      if( !f ){
	execvp(a[0], a );
	//everything else
	//redirection
            
    }

  }
  
  return 0;
}


