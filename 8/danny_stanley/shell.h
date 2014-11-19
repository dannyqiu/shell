#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void change_directory(char*);
void exit_shell();
void shell();
void call_cmd(char*,char*);
