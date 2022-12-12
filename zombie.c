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
        printf("I am a child process having PID %d:\n", getpid());
        printf("My parent PID %d:\n", getppid());
    }
    else
    {
        // parent
        sleep(3);
        printf("I am parent process having PID %d\n", getpid());
        printf("My child PID is %d :\n", p);
    }
}