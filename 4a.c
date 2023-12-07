#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
    pid_t pid, p;
    p = fork();
    pid = getpid();
    if (p < 0)
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    printf("Output of fork td : %d \n", p);
    printf("process id is : %d \n", pid);
    return 0;
}

