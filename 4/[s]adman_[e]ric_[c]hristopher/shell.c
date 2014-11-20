#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

//just incase lmao
#include <errno.h>



int main(){
  char* args=calloc(256,sizeof(char));
  char* cwd=calloc(256,sizeof(char));  
  while (1){


    getcwd(cwd,256);
    printf("%s:::::::",cwd);
    fgets(args,256,stdin);
    args = strsep(&args,"\n");
    char* p;
    for(p=args;*p;++p) *p= tolower(*p);
    printf("\nyou put:-%s-\n",args);
    printf("\n how many times i fked yo moder: %d\n",strcmp(args,"exit"));
    if (! strcmp(args,"exit")){
      printf("flag\n");
      exit(0);
    }else if (! strcmp(args,"cd")){
      execlp("cd","cd",args+3);
      printf("swag you cd'd to %s",args+3);
    }
  }

  return 0;
}
