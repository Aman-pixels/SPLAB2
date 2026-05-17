#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,head,total=0;

    printf("Enter number of requests: ");
    scanf("%d",&n);

    int req[n];

    printf("Enter requests:\n");
    for(i=0;i<n;i++)
        scanf("%d",&req[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    for(i=0;i<n;i++)
    {
        total+=abs(req[i]-head);
        head=req[i];
    }

    printf("Total seek time using FCFS = %d\n",total);

    return 0;
}