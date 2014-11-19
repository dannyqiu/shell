#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void command(char* comm){
  int argcount = 0;
  int i = 0;
  char delim = ' ';
  for (i;i<strlen(comm);i++){
    if (comm[i]==delim){
      argcount++;
    }
  }
  printf("Arguments counted: %d\n", argcount);
  argcount=argcount+2; //1 for command itself and 1 for NULL
  char **arguments=(char **)malloc((argcount)*sizeof(char *));
  char *temp = comm;
  i = 0;
  while (argcount){
    char *blah = strsep(&temp," ");
    arguments[i]=blah;//last index would be NULL
    i++;
    argcount--;
  }
  execvp(arguments[0],arguments);
  free(arguments);
}

int main(){
  printf("Testing if this works ");
  char uinput[256];
  fgets(uinput,sizeof(uinput),stdin);
  char *temp = uinput;
  temp=strsep(&temp,"\n");
  if (strcmp(uinput,"exit")==0){
    printf("Bye!");
    exit(0);
  }
  else{
    command(uinput);
  }
  return 0;
}
