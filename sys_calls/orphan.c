#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid = fork();

    if (pid > 0) {
        printf("Parent process is exiting\n");
        exit(0);
    } else if (pid == 0) {
        sleep(50);
        printf("Child process running with PID: %d and parent PID: %d\n", getpid(), getppid());
    }

    return 0;
}
