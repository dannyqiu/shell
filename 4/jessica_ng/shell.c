#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>

int main () {
  
  while (1) {
   
    printf ("\nshell prompt: ");
    
    char s[256];
    fgets (s, 256, stdin);
    //printf ("%s", s);
    int f = fork();
    if(f == 0) {
      char *c = s;
      char *t;
      char **args = NULL;
      int i = 0; 
      
      c = strsep (&c, "\n");
      
      while ((t = strsep(&c, " "))) {
	//printf ("%s", l[i]);
	//printf ("\n");
	args = realloc (args, sizeof (char *) *(i+1));
	args[i] = t;
	i++;
      }
      args [i] = 0;
      //args [0] = "ls"
      //execvp ("ls", args);
      execvp (args[0], args);
      free (args);
      printf ("\n wrong \n shell prompt:");
      exit(0);
    }
  }
  return 0;
}
