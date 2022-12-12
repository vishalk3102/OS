#include <stdio.h>
#define MAX 5
int front = 0, back = 0, cs = 0, nf;
int f[MAX];

int isFound(int x)
{
    for (int i = 0; i < cs; i++)
    {
        if (f[i] == x)
            return 1;
    }
    return 0;
}

void enq(int x)
{
    if (++back == nf)
    {
        back = 0;
    }
    f[back] = x;
    cs++;
}

void deq()
{
    cs--;
    if (++front == nf)
    {
        front = 0;
    }
    return;
}

void dis()
{
    for (int i = 0; i < cs; i++)
    {
        printf("%d", f[i]);
    }
    printf("\n");
}

int main()
{
    int rf[15], rfs, pf = 0;
    printf("Enter the size of reference string :");
    scanf("%d", &rfs);
    printf("\nEnter the reference string :");
    for (int i = 0; i < rfs; i++)
    {
        scanf("%d", &rf[i]);
    }
    printf("\nEnter the number of frame: ");
    scanf("%d", &nf);
    enq(rf[0]);
    pf = 1;
    for (int i = 0; i < rfs; i++)
    {
        if (!isFound(rf[i]))
        {
            pf++;
            if (cs == nf)
                deq();

            enq(rf[i]);
        }
        dis();
    }
    printf("\n no of page fault:%d", pf);
}