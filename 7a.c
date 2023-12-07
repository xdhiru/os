#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void copy(int s, int d)
{
    int c = 0;
    char m[50];
    while ((c = read(s, m, sizeof(m))) > 0)
    {
        write(d, m, c);
    }
}

int main()
{
    char source[50];
    char destination[50];
    int s, d;

    printf("Enter the name of the source file: ");
    scanf("%s", source);

    s = open(source, O_RDONLY);
    if (s == -1)
    {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    printf("Enter the name of the destination file: ");
    scanf("%s", destination);

    d = creat(destination, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (d == -1)
    {
        perror("Error creating destination file");
        close(s);
        exit(EXIT_FAILURE);
    }

    copy(s, d);

    close(s);
    close(d);

    printf("File copied successfully.\n");

    return 0;
}
