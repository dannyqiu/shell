#include "program.h"


void process(char * start){
  //site of user input processing
  while (start){
    execute(strsep(&start, ";"));
      
  }
}

void execute(char * start){
  //execute: Takes a char pointer start representing the beginning f a String
  //Splits the string arguements and runs them with a child process and execvp
  //Returns nothing
  //printf("%s\n",start);
  char * args[10];
  int x = 0;
  char * y;
  while (start){
    y = strsep(&start, " ");
    args[x] = y;
    x++;
  }
  args[x -1] = strsep(&args[x-1], "\n");
  args[x]=0;
  if (! (strcmp("cd",args[0]) && strcmp("exit",args[0])))
    normal_process(args);
  else{
    child_process(args);
  }
}
void normal_process(char * args[]){
  //For processes that require the main process to run
  //Takes the process with args as an array
  if (! (strcmp("cd",args[0]))){
    printf("IMPLEMENT CD PLS\n");
  }
  else if (! (strcmp("exit",args[0])))
    exit(0);
}

void child_process(char * args[]){
  //For processes that require a child to run
  //Takes the process with args as an array
  int f = fork();
  if (!f){
    //printf("running: %s %s\n",args[0],args[1]);
    //execl("/bin/ls","ls","-l",NULL);
    execvp(args[0],args);
  }
  else{
    wait(&f);
  }
}

int main(int argc, char *argv[]){
  char directory[256];
  while(1){
    getcwd(directory,256);
    char * direct_point = &directory[0];
    char * args[15];
    int x = 0;
    while (direct_point){
      args[x] = strsep(&direct_point, "/"); 
      x++;
    }
    printf("%s/%s: input: ",args[x-2],args[x-1]);
    char input[256];
    fgets(input, 256, stdin);
    printf("\n");
    char * start = &input[0];
    process(start);  
    
  }
  return 0;
}
    
