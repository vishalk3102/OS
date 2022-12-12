#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of process :");
    scanf("%d", &n);
    int a[n][3], burst[n];
    int wait[n], prev[n], tat[n];
    int t = 0, averageTatSum = 0, averageWaitSum = 0;
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the arrival burst time and priority number of %dth process :", i + 1);
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
        burst[i] = a[i][1];
    }
    for (int i = 0; i < n; i++)
    {
        wait[i] = 0;
        prev[i] = a[i][0];
    }

    while (1)
    {
        int ind = 0, min = 32763;
        for (int i = 0; i < n; i++)
        {
            if (t >= a[i][0] && min > a[i][2] && a[i][1] > 0)
            {
                min = a[i][2];
                ind = i;
            }
        }
        if (min == 32763)
            break;
        a[ind][1] -= 1;
        wait[ind] += t - prev[ind];
        t++;
        prev[ind] = t;
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = burst[i] + wait[i];
        averageTatSum += tat[i];
        averageWaitSum += wait[i];
    }

    double averageTAT = 0, averageWAIT = 0;
    averageTAT = averageTatSum / (1.0 * n);
    averageWAIT = averageWaitSum / (1.0 * n);
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, a[i][0], a[i][1], a[i][2], wait[i], tat[i]);
    }
    printf("\nThe average wait time of all procecss  is :%lf", averageWAIT);
    printf("\nThe average turn around time of all procecss  is :%lf", averageTAT);
}