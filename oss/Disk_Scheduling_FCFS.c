#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, total=0, head;
    printf("Enter the number of requests : ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the Requests in Sequence : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &requests[i]);
    }

    printf("Enter Initial head Possition : ");
    scanf("%d", &head);
    
    printf("Requests : %d", head);
    for(int i=0;i<n;i++)
    {
        printf("--> %d", requests[i]);
        total += abs(requests[i]-head);
        head = requests[i];
    }
    float avg = (float)total/n;

    printf("\nTotal head movement = %d", total);
    printf("\nAverage Head Movement = %f", avg);
}