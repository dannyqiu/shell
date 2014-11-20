#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *pre() {
  char cwd[256];
  getcwd(cwd, 256);
  printf("Swag Shell:%s$ ",cwd);
}

int main() {
  pre();
  while(1) {
  //This processes the input
  char input[256];
  fgets(input, 256, stdin);
  int a;
  for (a = 0;a < strlen(input);a++) { // Adds a space before the end of the buffer
    if (input[a] == '\n') {
	input[a] = ' ';
	break;
    }
  }

  if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't') {
    //execlp("exit", "exit", NULL);
    return 0;
  } else if (input[0] == 'c' && input[1] == 'd') {
    //printf("%s",strchr(input,' '));
    if (strchr(input,' ') == " ") {
      chdir("/");
    } else {
      chdir(strchr(input,' '));
    }
    pre();
  } else {
    int status;
    int f = fork ();
    char *args[256];
    int i = 0;
    char *tok = input;
    char *end = input;
    while (tok != NULL) { // The space added earlier is necessary here to make strsep work on the last arg properly.
      strsep(&end, " ");
      args[i] = tok;
      i++;
      tok = end;
    }
    args[i - 1] = NULL; // Null-terminates the array and removes the last empty arg
    if (f) {
      wait(&status);
      pre();
    } else {
      execvp(args[0], args); // Useful for large amounts of arguments
    }
  }
  }
  return 0;
}
