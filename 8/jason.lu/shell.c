#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
  while(1){
    
    char prompt[4096];
    strcpy(prompt,"Shell:");//add directory and username
    printf("%s", prompt);
    char input[4096];
    fgets(input, 4096, stdin);
    
  }
  
}
