#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  while ("( ‾ʖ̫‾)") {
    printf("ヽ༼ຈل͜ຈ༽ﾉ: ");
    char input[256];
    fgets(input,sizeof(input),stdin);
    
    char ** parsed = NULL;
    char * item = strtok(input," ");
    int numitems = 0;
    while (item) {
      parsed = realloc(parsed,sizeof(char*)*++numitems);
      parsed[numitems-1] = item;
      item = strtok(NULL," ");
    }
    strtok(parsed[numitems-1], "\n");
    parsed = realloc(parsed,sizeof(char*)*(numitems+1));
    parsed[numitems] = 0;
    int i = fork();
    if (i) {
      wait();
    }
    else {
      execvp(parsed[0],parsed);
      free(parsed);
      return 0;
    }
  }
}
