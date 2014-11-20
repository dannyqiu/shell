#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#include "parse.h"
#include "execute.h"

int main(){
  printf("> ");
  
  char s[256];
  fgets (s, 256, stdin);
  char* s1 = s;
}
