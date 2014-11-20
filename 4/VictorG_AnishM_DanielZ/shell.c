#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
//more includes

char ** separate(char *s){
  char *pos;
  if ((pos=strchr(s, '\n')) != NULL)
    *pos = '\0';
  char *s1=s;
  char **s2;
  //printf("yo\n");
  int i;
  for (i=0;s[i];i++){
    s2[i] = (char *)malloc(25*sizeof(char));
    s2[i] = strsep(&s1, " ");
  }
  
  //s2[i-1]=
  s2[i]=(char *)malloc(25*sizeof(char));
  s2[i]=NULL;
  return s2;
}
void run(char *input){
  char **inputA;
  inputA=separate(input);
  //printf("%s\n",inputA[0]);
  char* problemChild=inputA[0];
  if (strcmp(problemChild,"cd")){
    
  }
  execvp(inputA[0],inputA);
  
}




int main(){
  char s[1024];
  printf("wedemboyz$$:");
  run(fgets(s,1024,stdin));
  return 0;
}
