#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    char source[50];
    char destination[50];
    int s, d;
    int c = 0;
    char temp[50];

    printf("Enter the name of the source file: ");
    scanf("%s", source);

    printf("Enter the name of the destination file: ");
    scanf("%s", destination);

    s = open(source, O_RDONLY);
    if (s == -1)
    {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    d = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (d == -1)
    {
        perror("Error opening/creating destination file");
        close(s);
        exit(EXIT_FAILURE);
    }

    while ((c = read(s, temp, sizeof(temp))) > 0)
    {
        write(d, temp, c);
    }

    close(s);
    close(d);

    printf("File copied successfully.\n");

    return 0;
}
