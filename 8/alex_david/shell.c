#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

int main(){
  printf("-- _ SHELL --\n\n"); //fill _ with name or change
  command();
  return 0;
}

int command(){
  printf("_$ "); //fill _ with something
  char s[1024];
  fgets(s,sizeof(s),stdin);
  int n = 0;
  char *p = s;
  while (*p){
    if (*p == ' '){
      n++;
    }
    p++;
  }//remove newline
  char **params = (char *)malloc(64 * n);
  n = 0;
  while (s){
    params[n] = strsep(s,' ');
  }
  
  return 0;
}
