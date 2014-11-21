#include "shell.h"

int main () {
  char s[256];
  while (1) {
    prompt(s);
    int f = fork();
    if(f == 0) {
      docmd(s);
    } else {
      wait();
    }
  }
  return 0;
}
