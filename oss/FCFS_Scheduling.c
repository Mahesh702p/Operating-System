#include <stdio.h>

int main()
{
    int n,i,ttat=0,twt=0;
    float awt, atat;
    printf("Enter the number of processes : ");
    scanf("%d", &n);

    int bt[n], at[n], wt[n], tat[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter Arrival time for P%d :", i+1);
        scanf("%d", &at[i]);
        printf("Enter Burst time for P%d : ", i+1);
        scanf("%d", &bt[i]);
    }

    printf("\nProcess\tArrival Time\tBurst Time\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\n", i+1, at[i], bt[i]);
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1; j<n;j++)
        {
            if(at[i]>at[j])
            {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    wt[0] = 0;
    int start_time = at[0];

    for(int i=1;i<n;i++)
    {
        int end_time = start_time + bt[i-1];
        if(end_time < at[i])
        {
            start_time = at[i];
        }
        else
        {
            start_time = end_time ;
        }
        wt[i] = start_time - at[i];
    }

    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<n;i++)
    {
        tat[i] = wt[i]+bt[i];
        twt += wt[i];
        ttat += tat[i];
        printf("P%d\t%d\t%d\n", i+1, wt[i], tat[i]);
    }
    awt = (float)twt/n;
    atat = (float)ttat/n;

    printf("\n Average Waiting Time : %f", awt);
    printf("\n Average Turnaround Time : %f", atat);
}