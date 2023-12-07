#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {

    int pid;
    pid = fork();
    if (pid < 0) {
        printf("\n Error");
        exit(1);
    } else if (pid == 0) {
        printf("\n Hello, I am the child process ");
        printf("\n My PID is %d \n", getpid());
        exit(0);
    } else if (pid > 0) {
        printf("\n Hello, I am the parent process");
        printf("\n My actual PID is %d \n", getpid());
        wait(NULL);
        exit(1);
    }
}
