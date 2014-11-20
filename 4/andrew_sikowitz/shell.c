#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>

#define pwd pw->pw_dir

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
    char input[1024];
    fgets(input,1024,stdin);
  }
}
