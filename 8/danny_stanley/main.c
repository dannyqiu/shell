#include "shell.h"

static void signal_handler(int signo) {
    if (signo == SIGINT) {
        printf("\x08\x08  \x08\x08"); // Prints backspace to remove interrupt
        fflush(stdout);
    }
}

int main() {
    signal(SIGINT, signal_handler);
    shell();
    printf("\nThanks for using StD!\n");
    return 0;
}
