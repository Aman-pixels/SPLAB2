#include<stdio.h>
#include<stdlib.h>

void sort(int arr[],int n)
{
    int i,j,temp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n,i,head,total=0;

    printf("Enter number of requests: ");
    scanf("%d",&n);

    int req[n];

    printf("Enter disk requests:\n");
    for(i=0;i<n;i++)
        scanf("%d",&req[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    int temp=head;

    printf("\nFCFS Disk Scheduling\n");

    for(i=0;i<n;i++)
    {
        total+=abs(req[i]-temp);
        temp=req[i];
    }

    printf("Total seek time = %d\n",total);

    sort(req,n);

    total=0;
    temp=head;

    printf("\nSCAN Disk Scheduling\n");

    int pos;

    for(i=0;i<n;i++)
    {
        if(req[i]>head)
        {
            pos=i;
            break;
        }
    }

    for(i=pos;i<n;i++)
    {
        total+=abs(req[i]-temp);
        temp=req[i];
    }

    total+=abs(199-temp);
    temp=199;

    for(i=pos-1;i>=0;i--)
    {
        total+=abs(req[i]-temp);
        temp=req[i];
    }

    printf("Total seek time = %d\n",total);

    return 0;
}