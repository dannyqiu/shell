#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <errno.h>


//parse
char** parse(){

  char s[256];
  fgets( s , sizeof(s) , stdin );
  strtok(s,"\n");  

  int j = 0;
  char* temp = s;
  
  while( *temp){
    if (temp == ' '){
      j++;
    }
    *temp ++;
  }

  char** arr = (char**)malloc(sizeof(char*) * j);
  arr[0] = strtok(s," ");
  char* c;
  j = 1;
  while(c = strtok(0," ")){
    arr[j] = c;
    j++;
  }

  return arr;
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

    if (a[0] == "exit"){
      execlp("exit","exit", NULL);
    }
    if (a[0] == "cd"){
      execvp("cd", a );
    }
    else{
      int f = fork();
      if( !f ){
	execvp(a[0], a );
	//everything else
	//redirection
      }      
    }

  }
  
  return 0;
}


