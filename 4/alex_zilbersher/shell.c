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
  int semi=0; //for ; in commands
  while(s2=strsep(&s1," ")){
    if(strcmp(s2,"")!=0){
      if(strcmp(s2,";")!=0){
	args[i]=s2;
	i++;
      }else{
	semi=1;
	break;
      }
    }
  }
  args[i]=0;
  //printf("%d\n",semi);
  if(semi){
    int f=fork();
    if(f){
      wait(&f);
      printf("\n");
      run_command(s1);
    }else{
      //printf("%s\n",s1);
      execvp(args[0],args);
    }
  }else{
    execvp(args[0],args);
  }
  return 0;
}

int run_command(char* s){
  char *args[256];
  char *s1=s;
  char *s2;
  int i=0;
  int semi=0; //for ; in commands
  while(s2=strsep(&s1," ")){
    if(strcmp(s2,"")!=0){
      if(strcmp(s2,";")!=0){
	args[i]=s2;
	i++;
      }else{
	semi=1;
	break;
      }
    }
  }
  args[i]=0;
  if(semi){
    int f=fork();
    if(f){
      wait(&f);
      printf("\n");
      run_command(s1);
    }else{
      execvp(args[0],args);
    }
  }else{
    execvp(args[0],args);
  }
  return 0;
}
