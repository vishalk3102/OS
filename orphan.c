#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t p;
    p = fork();
    if (p == 0)
    {
        // child
        sleep(3);
        printf("I am child haviing pid %d\n", getpid());
        printf("My parent pid is %d :\n", getppid());
    }
    else
    {
        // parent
        printf("I am parent haviing pid %d\n", getpid());
        printf("My child pid is %d :\n", p);
    }
}