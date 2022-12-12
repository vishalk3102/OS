#include <stdio.h>

void sort(int a[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][2] < a[j][2])
            {
                int t = a[i][0];
                int k = a[i][1];
                int l = a[i][2];

                a[i][0] = a[j][0];
                a[i][1] = a[j][1];
                a[i][2] = a[j][2];

                a[j][0] = t;
                a[j][1] = k;
                a[j][2] = l;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of process :");
    scanf("%d", &n);
    int a[n][3];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the arrival and burst time for  %dth process:", i + 1);
        scanf("%d  %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }

    sort(a, n);
    int wait[n], tat[n];
    int averageWaitSum = 0, averageTatSum = 0;
    wait[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wait[i] = wait[i - 1] + a[i - 1][1];
        averageWaitSum += wait[i];
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = wait[i] + a[i][1];
        averageTatSum += tat[i];
    }
    printf("\nprocess-no\t arrival-time\t burst-time\t  priority-no\t waiting-time\t turnaround-time\t ");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, a[i][0], a[i][1], a[i][2], wait[i], tat[i]);
    }
    double averageWAIT = 0, averageTAT = 0;
    averageWAIT = averageWaitSum / (1.0 * n);
    averageTAT = averageTatSum / (1.0 * n);
    printf("\nThe average wait time of all procecss  is :%lf", averageWAIT);
    printf("\nThe average turn around time of all procecss  is :%lf", averageTAT);
}