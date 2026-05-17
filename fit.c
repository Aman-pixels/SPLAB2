#include<stdio.h>

int main()
{
    int nb,np,i,j;
    
    printf("Enter number of blocks: ");
    scanf("%d",&nb);

    int block[nb];

    printf("Enter block sizes:\n");
    for(i=0;i<nb;i++)
        scanf("%d",&block[i]);

    printf("Enter number of processes: ");
    scanf("%d",&np);

    int process[np];

    printf("Enter process sizes:\n");
    for(i=0;i<np;i++)
        scanf("%d",&process[i]);

    printf("\nFirst Fit\n");

    int temp[nb];

    for(i=0;i<nb;i++)
        temp[i]=block[i];

    for(i=0;i<np;i++)
    {
        for(j=0;j<nb;j++)
        {
            if(temp[j]>=process[i])
            {
                printf("Process %d allocated to block %d\n",i+1,j+1);
                temp[j]-=process[i];
                break;
            }
        }
    }

    return 0;
}