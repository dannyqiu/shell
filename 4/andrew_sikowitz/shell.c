#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>

#define pwd pw->pw_dir

char isRed(char c) {
  return c == '>' || c == '<' || c == '|';

int parse(char * input) {
  int c = 0;
  int i, j;
  for (i=0; i<strlen(input); i++) {
    if (isRed(input[i]))
      c++;
  }
  
  char[1024] * commands = malloc(1024*c);
  char * step;
  char * placeholder = input;

  for (i=0; i<c; i++) {
    int inner_c = 0;
    int max_len = 0;
    while ((step = strsep(&input, " ><|")) && !isRed(step[0])) {
      if (!strcmp(step, ""))
	inner_c++;
      if (strlen(step) > max_len)
	max_len = strlen(step);
    }

    

int main() {
  //Main program
  printf("PID: %d\n", getpid());
  printf("Login: %s\n", getlogin());
  char hostname[4096];
  char cwd[4096];
  char * cwdp;
  getcwd(cwd, 4096);
  gethostname(hostname, 4096);
  struct passwd *pw = getpwuid(getuid());
  printf("Home Directory: %s\n", pwd);
  printf("CWD: %s\n", cwd);
  printf("Hostname: %s\n", hostname);
  while (1) {
    getcwd(cwd, 4096);
    gethostname(hostname, 4096);
    getpwuid(getuid());
    cwdp = strstr(cwd, pwd) + strlen(pwd) - 1;
    *cwdp = '~';
    printf("%s@%s:%s$ ", getlogin(), hostname, cwdp);
    char input = malloc(1024);
    fgets(input,1024,stdin);
    parse(input);
    free(input);
  }
}
