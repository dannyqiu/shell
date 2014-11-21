#include <stdio.h>
#include <stdlib.h>

int main() {
  char * input = malloc(1024);
  fgets(input, 1024, stdin);
  char * s = strsep(&input, " ");
  char * s2 = strsep(&input, " ");
  printf("%d\n", strcmp(s2, ""));
  printf("You said: %s,%s,%s\n", s, s2, input);
  free(s);
  return 0;
}
