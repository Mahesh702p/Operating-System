#include <stdio.h>

void main()
{
    int n, best =-1, process;
    printf("Enter the number of blocks : ");
    scanf("%d", &n);
    int block[n+1];
    for(int i=1;i<=n;i++)
    {
        printf("Enter the size of block %d :", i);
        scanf("%d", &block[i]);
    }

    printf("Enter the size of process : ");
    scanf("%d", &process);

    for(int i=1;i<=n;i++)
    {
        printf("\n%d - %d KB", i, block[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(block[i]>=process)
        {
            if(best ==-1 || block[i]<block[best])
            {
                best = i;
            }
        }
    }

    if(best!=-1)
    {
        printf("\nprocess is allocated to index %d of size %d", best, block[best]);
        block[best] -= process ;
    }
    else
    {
        printf("nop suitable block found");
    }

    for(int i=1;i<=n;i++)
    {
        printf("\n%d - %d KB", i, block[i]);
    }
}