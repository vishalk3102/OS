#include <stdio.h>
int main()
{
    int initial, total = 0, n;
    printf("Enter the initial posiiton of head :");
    scanf("%d", &initial);
    printf("\nEnter the number of track to be reached:");
    scanf("%d", &n);

    int a[n];
    printf("\nEnter the disk track nuumber to reached: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int c = 0;
    while (c != n)
    {
        int d = 10000, ind;
        for (int i = 0; i < n; i++)
        {
            int l = initial - a[i];
            if (l < 0)
                l = l * (-1);

            if (l < d)
            {
                d = l;
                ind = i;
            }
        }
        initial = a[ind];
        a[ind] = 10000;
        total += d;
        c++;
    }
    printf("The total amount is %d", total);
    return 0;
}