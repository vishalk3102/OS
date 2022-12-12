#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    pid_t p;
    char a[100], str[100];
    int fd[2], n, m;
    pipe(fd);
    p = fork();
    if (p == 0)
    {
        printf("\nEnter a string :");
        n = write(fd[1], str, strlen(str));
        printf("child wrote %d bytes\n", n);
        exit(0);
    }
    else
    {
        m = read(fd[0], a, sizeof(a));
        a[m] = '\0';
        printf("parent read %d bytes :%s\n", m, a);
    }
    return 0;
}