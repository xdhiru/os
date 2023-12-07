#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pid;
    pid = fork();

    if (pid < 0) {
        printf("\n Error ");
        exit(1); // indicate error condition
    } else if (pid == 0) {
        printf("\n Hello, I am child process");
        printf("\n My PID is %d", getpid());
        exit(0); // indicate successful completion
    } else {
        printf("\n Hello, I am parent process");
        printf("\n My actual PID is %d \n", getpid());
        exit(0); // indicate successful completion
    }

    return 0; // This line is not reachable due to the 'exit()' calls above
}
