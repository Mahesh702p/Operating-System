#include <stdio.h>

void main()
{
    int n, first =-1, process;
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
            first = i;
            break;
        }
    }

    if(first!=-1)
    {
        printf("\nprocess is allocated to index %d of size %d", first, block[first]);
        block[first] -= process ;
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