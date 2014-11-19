#include <stdio.h>
#include <stdlib.h>

#include "executor.h"


int main(){

  while(1){

    int f = fork();
    wait();
    if (!f){
      execute();
    }
  }
  
  return 1;

}
