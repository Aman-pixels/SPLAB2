#include<stdio.h>

int main()
{
    int n,f,i,j,k,flag,pos=0,faults=0;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    int pages[n];

    printf("Enter pages:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);

    int frame[f];

    for(i=0;i<f;i++)
        frame[i]=-1;

    for(i=0;i<n;i++)
    {
        flag=0;

        for(j=0;j<f;j++)
        {
            if(frame[j]==pages[i])
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            frame[pos]=pages[i];
            pos=(pos+1)%f;
            faults++;
        }
    }

    printf("Page Faults = %d\n",faults);

    return 0;
}