#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

int main(){
  printf("-- _ SHELL --\n\n"); //fill _ with name or change]
  command();
  return 0;
}

int command(){
  printf("_$ "); //fill _ with something
  char s[1024];
  fgets(s,sizeof(s),stdin);
  int n = 2;
  char *p = s;
  while (*p){
    if (*p == ' '){
      n++;
    }
    p++;
  }
  char **params = malloc(sizeof(char *) * n);
  p = s;
  *strchr(p,'\n') = '\0';
  n = 0;
  char *k;
  while (k = strsep(&p," ")){
	params[n] = k;
	n++;
  }
  params[n] = NULL;
  execvp(params[0],params);
  return 0;
}
