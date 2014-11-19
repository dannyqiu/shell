#include <unistd.h>
#include<sys/stat.h>
#include <stdio.h>
#include <string.h>
#include<dirent.h>


int cd (char* s) {

  char cwd [256];
  getcwd (cwd, sizeof(cwd));
  strcat (cwd, "/");
  strcat (cwd, s);

  chdir(cwd);
}

int main () {

  cd ("..");
}
