#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int sum; // data shared among threads

void *run(void *param); // the thread *I

int main(int argc, char *argv[])
{
    // thread identifier
    pthread_t tid;
    // set of thread attributes
    pthread_attr_t attr;

    if (argc != 2)
    {
        fprintf(stderr, "Error!\n");
        return 1;
    }

    if (atoi(argv[1]) < 0)
    {
        fprintf(stderr, "Number should be positive!\n");
        return 1;
    }

    // get default attributes
    pthread_attr_init(&attr);

    // thread calculates the sum of numbers from
    // 1 to argv[1] (an integer)
    pthread_create(&tid, &attr, run, argv[1]);

    // wait for thread to exit *I
    pthread_join(tid, NULL);

    printf("SUM: %d\n", sum);

    return 0;
}

void *run(void *param)
{
    int i, upper = atoi(param);
    sum = 0;

    if (upper > 0)
    {
        for (i = 1; i <= upper; i++)
        {
            sum += i;
        }
    }

    pthread_exit(0);
}


/*
output:
kapil@kapil-VirtualBox:~$ gcc -pthread thread1.c -o th.out
kapil@kapil-VirtualBox:~$ ./th.out 10
Sum = 55
kapil@kapil-VirtualBox:~$
*/