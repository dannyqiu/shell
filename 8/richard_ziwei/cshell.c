//HAHAHAHAHAHAH
#include"heads.h"


void dumb_exceptions(char arg[]){
  if (arg[0] == 'c' && arg[1] == 'd' && (arg[2] == 0 || arg[2] == ' ')){
    strsep(&arg," ");
    chdir(arg);
  }
  else if (!strcmp(arg,"exit")){
    printf("I am exiting\n");
  }
}

int main(){
  while (1){
    char input[256];
    char direct[256];
    getcwd(direct,sizeof(direct));
    printf("%s$",direct);
    fgets(input,sizeof(input),stdin);
    input[strlen(input)-1]=0;
    printf("%s\n",input);
    dumb_exceptions(input);
  }
  return 0;
}
