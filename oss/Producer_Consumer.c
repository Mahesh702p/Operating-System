#include <stdio.h>
#include <stdlib.h>

int mutex=1, full=0, empty=3, x=0;

int wait(int S)
{
    return --S;
}

int signal(int S)
{
    return ++S;
}

void Producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("PRODUCER PRODUCES ITEM %d \n", x);
    mutex = signal(mutex);
}

void Consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    x--;
    printf("CONSUMER CONSUMES ITEM %d ", x);
    mutex = signal(mutex);
}

void main()
{
    int choice ;
    printf(" --- PRODUCER-CONSUMER PROBLEM SIMULATION --- \n");
    printf("1. Producer\n2. Consumer\n3. Exit\n");
    while(1)
    {
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if((mutex==1) && (empty!=0))
                Producer();
            else
                printf("BUFFER IS FULL");
            break;
        
        case 2:
            if((mutex==1) && (full!=0))
                Consumer();
            else
                printf("BUFFER IS EMPTY");
            break;
        
        case 3:
            exit(0);
        default:
            break;
        }
    }
}