#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("Enter the number of process :");
    scanf("%d", &n);
    int a[n][2], burst[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the arrival and burst time for  %dth process:", i + 1);
        scanf("%d  %d", &a[i][0], &a[i][1]);
        burst[i] = a[i][1];
    }
    int wait[n], tat[n], prev[n];
    int t = 0, averageTatSum = 0, averageWaitSum = 0;
    for (int i = 0; i < n; i++)
    {
        wait[i] = 0;
        prev[i] = 0;
    }
    while (1)
    {
        int ind = 0, min = 32763;
        for (int i = 0; i < n; i++)
        {
            if (t >= a[i][0] && min > a[i][1] && a[i][1] > 0)
            {
                min = a[i][1];
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
        tat[i] = wait[i] + burst[i];
        averageTatSum += tat[i];
        averageWaitSum += wait[i];
    }
    printf("\nprocess-no\t arrival-time\t burst-time\t waiting-time\t turnaround-time\t ");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, a[i][0], a[i][1], wait[i], tat[i]);
    }
    double averageWAIT = 0, averageTAT = 0;
    averageWAIT = averageWaitSum / (1.0 * n);
    averageTAT = averageTatSum / (1.0 * n);
    printf("\nThe average wait time of all procecss  is :%lf", averageWAIT);
    printf("\nThe average turn around time of all procecss  is :%lf", averageTAT);
}