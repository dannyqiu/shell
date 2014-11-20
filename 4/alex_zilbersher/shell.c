#include "shell.h"

int run(){
  char s[256];
  printf("@&Z ");
  fgets(s,255,stdin);
  s[strlen(s)-1]=0;
  char *args[256];
  char *s1=s;
  char *s2;
  int i=0;
  while(s2=strsep(&s1," ")){
    if(strcmp(s2,"")!=0){
      //printf("s2:%s.\n",s2);
      args[i]=s2;
      i++;
    }
  }
  args[i]=0;
  execvp(args[0],args);
  return 0;
}
