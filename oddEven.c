#include <stdio.h>
// #include <unistd.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int pid = fork();
    if (pid < 0)
    {
        printf("Child process creation is unsuccessfull \n");
    }
    else if (pid == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 != 0)
            {
                sum += a[i];
            }
        }
        printf("Child process %d :\n", sum);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                sum += a[i];
            }
        }
        printf("Parent process %d :\n", sum);
    }
}