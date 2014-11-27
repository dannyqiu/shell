#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "directorystack.h"

#define TOK_INIT_SIZE 512
#define FILE_SIZE 256

void parse_input(char *);
void execute(char **);
void change_directory(char *, node *);

void cleanup_argv();
void setup_argv();

static const char *shell_name = "StD";
