#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>


/*Ok, so the parse is sort of working. If you test it out, you can see that
at the end of the pasre function i print it out and each element is correct
but then when i try to print it in main it doesn't work
So when the value is being returned is where it gets messed up somehow
 
*/

//parse
/*char** parse(){
 
 


  return args;

  }*/


int redirection (char * source, char * dest){

  return 0;
}

void print_prompt(){
  char path[256];
  getcwd(path, 256);  
  
  printf("%s$ ", path);
}

int main(){

  print_prompt();
  int run = 1;
  while(run){

    //   char ** a =  (char**)malloc(sizeof(char *) * 50);
    //char ** a = parse();
    
    //PARSING
    char s1[256];
    fgets(s1, sizeof(s1), stdin);
    s1[strlen(s1)-1]='\0';

    char * s = s1;
    char ** args = (char**)malloc(sizeof(char *) * 50);
    char * temp = strsep(&s, " ");

    int i=0;
    while(temp){
      args[i] = temp;    
      temp = strsep(&s, " ");
      i ++;   
    }
    args[i] = 0;
  
    /* testing that parsing works
      i=0;
      while(args[i]){
      printf("args[%d]:  %s\t",i,args[i]);
      i++;
      }*/
    

    //RUNNING PARSED CODE 
    if (strcmp(args[0], "exit") == 0){
      run = 0;
      printf("BYE!!!!\n");
    }
    else if  (strcmp(args[0], "cd") == 0){
      chdir(args[1]);
      print_prompt();
    }
    else{  
      int f = fork();
      int status;
      if( !f ){
	execvp(args[0], args );
	//everything else
	//redirection
      }else{
	wait(&status);
	print_prompt();
      }
    }
  }
  
  return 0;
}


