#include <stdio.h>
#include <stdlib.h>

int chopstick[5] = {1,1,1,1,1}; // 1=avilable, 0=in use
int state[5] = {0,0,0,0,0};// 1=eating 0=thinking

int wait(int S)
{
    return --S;
}

int signal(int S)
{
    return ++S;
}

void take_chopstick(int i)
{
    if(chopstick[i] == 1 && chopstick[(i+1)%5] == 1)
    {
        chopstick[i]= wait(chopstick[i]);
        chopstick[(i+1)%5] = wait(chopstick[(i+1)%5]);
        state[i]=1;//eating
        printf("Philosopher %d is eating with chopstick %d and %d \n", i,i,(i+1)%5);
    }
    else
    {
        printf("Philosopher %d is thinking (chopstick not available) \n", i);
    }
}

void put_chopstick(int i)
{
    if(state[i]==1)
    {
        chopstick[i]= signal(chopstick[i]);
        chopstick[(i+1)%5] = signal(chopstick[(i+1)%5]);
        state[i]=0;//thinking
        printf("Philosopher %d has finished eating and put down the chopstick \n", i);
    }
    else
    {
        printf("Philosopher %d is not eating cannot put down chopstick \n", i);
    }
}

void main()
{
    int choice , philosopher ;
    printf("--- DINING PHILOSOPHER SIMULATION --- \n");
    while(1)
    {
        printf("1.Philosopher wants to eat \n");
        printf("2.Philosopher finished eating \n");
        printf("3.Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter Philosopher number (0-4) : ");
                scanf("%d", &philosopher);
                if(philosopher<=0 || philosopher<5)
                {
                    take_chopstick(philosopher);
                }
                else
                {
                    printf("Enter valid Philosopher");
                }
                break;

            case 2:
                printf("Enter Philosopher number (0-4) : ");
                scanf("%d", &philosopher);
                if(philosopher<=0 || philosopher<5)
                {
                    put_chopstick(philosopher);
                }
                else
                {
                    printf("Enter valid Philosopher");
                }
                break;
            
            case 3: 
                exit(0);
        }
    }
}