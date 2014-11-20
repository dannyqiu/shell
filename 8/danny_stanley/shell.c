#include "shell.h"

void shell() {
    char *input = (char *) malloc(BUFFER_SIZE);
    int done = 0;
    while (!done) {
        printf(">> ");
        fflush(stdout);
        done = parse_input(input);
    }
    free(input);
}

int parse_input(char *input) {
    char *argv = input;
    fgets(argv, BUFFER_SIZE, stdin);
    if (feof(stdin)) { // To handle EOF
        return 1;
    }
    char *cmd = strsep(&argv, " \n");
    if (strcmp(cmd, "quit") == 0 || strcmp(cmd, "exit") == 0) {
        return 1;
    }
    else if (cmd) {
        if (strstr(cmd, "cd") != NULL) {
            change_directory(argv);
        }
        else {
            printf("Running: %s %s\n", cmd, argv);
            call_cmd(cmd, argv);
        }
    }
    return 0;
}

void call_cmd(char *cmd, char *argv) {
    pid_t pid = fork();
    if (pid) { // Parent process to wait for child to finish
        int status;
        wait(&status);
    }
    else { // Child process to execute commands
        char *argv_buf[BUFFER_SIZE];
        char *arg;
        argv_buf[0] = cmd;
        int i = 1;
        for (arg = strsep(&argv, " \n"); *arg; arg = strsep(&argv, " \n")) {
            argv_buf[i] = arg;
            ++i;
        }
        argv_buf[i] = NULL;
        execvp(cmd, argv_buf);
        if (errno) {
            printf("%s: %s\n", cmd, strerror(errno));
        }
        exit(0);
    }
}

void change_directory(char *argv) {
    char *path = strsep(&argv, " \n");
    chdir(path);
    if (errno) {
        printf("%s: %s\n", "cd", strerror(errno));
    }
}
