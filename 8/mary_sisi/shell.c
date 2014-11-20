#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>


//parse
char** parse(){
 
  char s1[256];

  fgets(s1, sizeof(s1), stdin);
  s1[strlen(s1)-1]='/0';

  char * s = s1;
  char ** args = (char**)malloc(sizeof(char *) * 50);
  char * temp = strsep(&s, " ");
  //args[0] = temp;

  int i=0;
  while(temp){
    printf("?????????%s\n", temp);//     
    args[i] = temp;    
    temp = strsep(&s, " ");
    
    i ++;   
  }

  printf("%d   working???\n", i);  
  args[i] = 0;
  
  i=0;
  while(args[i]){
    printf("args[%d]:  %s\t",i,args[i]);
    i++;
  }


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

    char ** a =  (char**)malloc(sizeof(char *) * 50);
    a = parse();
    
    /* int i=0;
    while(a[i]){
      printf("command:  %s\t",a[i]);
      i++;
      }*/

      /*
    if (a[0] == "exit"){
      execlp("exit","exit", NULL);
    }
    if (a[0] == "cd"){
      execvp("cd", a );
      }*/
    //else{

    /*
      int f = fork();
      if( !f ){
	execvp(a[0], a );
	//everything else
	//redirection
            
	}*/

  }
  
  return 0;
}


