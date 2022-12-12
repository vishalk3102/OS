#include <stdio.h>

int main()
{
    int initial, total, n;
    printf("Enter the initial posiiton of head :");
    scanf("%d", &initial);

    printf("\nEnter the number of track to be reached:");
    scanf("%d", &n);

    int a[n];
    printf("\nEnter the reference string: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    total = initial - a[0];
    if (total < 0)
    {
        total = (-1) * total;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int temp = a[i] - a[i + 1];
        if (temp < 0)
        {
            temp = temp * (-1);
        }
        total += temp;
    }
    printf("\nThe total ampount of seek operation is :%d", total);
}