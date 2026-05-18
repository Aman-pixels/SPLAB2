#include<stdio.h>

void firstFit(int block[],int m,int process[],int n)
{
    int i,j,temp[m];

    for(i=0;i<m;i++)
        temp[i]=block[i];

    printf("\nFirst Fit\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(temp[j]>=process[i])
            {
                printf("Process %d allocated to Block %d\n",i+1,j+1);
                temp[j]-=process[i];
                break;
            }
        }
    }
}

void bestFit(int block[],int m,int process[],int n)
{
    int i,j,best,temp[m];

    for(i=0;i<m;i++)
        temp[i]=block[i];

    printf("\nBest Fit\n");

    for(i=0;i<n;i++)
    {
        best=-1;

        for(j=0;j<m;j++)
        {
            if(temp[j]>=process[i])
            {
                if(best==-1 || temp[j]<temp[best])
                    best=j;
            }
        }

        if(best!=-1)
        {
            printf("Process %d allocated to Block %d\n",i+1,best+1);
            temp[best]-=process[i];
        }
    }
}

void worstFit(int block[],int m,int process[],int n)
{
    int i,j,worst,temp[m];

    for(i=0;i<m;i++)
        temp[i]=block[i];

    printf("\nWorst Fit\n");

    for(i=0;i<n;i++)
    {
        worst=-1;

        for(j=0;j<m;j++)
        {
            if(temp[j]>=process[i])
            {
                if(worst==-1 || temp[j]>temp[worst])
                    worst=j;
            }
        }

        if(worst!=-1)
        {
            printf("Process %d allocated to Block %d\n",i+1,worst+1);
            temp[worst]-=process[i];
        }
    }
}

int main()
{
    int m,n,i;

    printf("Enter number of blocks: ");
    scanf("%d",&m);

    int block[m];

    printf("Enter block sizes:\n");
    for(i=0;i<m;i++)
        scanf("%d",&block[i]);

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int process[n];

    printf("Enter process sizes:\n");
    for(i=0;i<n;i++)
        scanf("%d",&process[i]);

    firstFit(block,m,process,n);
    bestFit(block,m,process,n);
    worstFit(block,m,process,n);

    return 0;
}