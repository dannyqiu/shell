#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <singal.h>
#include <sys/stat.h>
#include <errno.h>


//parse
char** parse(char* s){
  char * args[];

  char command[256];
  char * arr_pointer = command;
  
  fgets(command, sizeof(command), stdin);

  command[strlen(command) - 1] = '\0';

  strsep( &arr_pointer, " " )


  return args;
}



int redirection (char * source, char * dest){
//

  return 0;
}

void print_promt(){
  char path[256];
  getcwd(path, 256);  
  
  printf("%s$", path);
}

int main(){

  print_promt();

  while(1){
  //if exit

  //if cd

  //everything else

  //redirection
  }



  return 0;
}


