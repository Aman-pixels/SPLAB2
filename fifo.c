#include<stdio.h>

int main()
{
    int pages,frames,i,j,k,pos,faults=0;

    printf("Enter number of pages: ");
    scanf("%d",&pages);

    int p[pages];

    printf("Enter page reference string:\n");
    for(i=0;i<pages;i++)
        scanf("%d",&p[i]);

    printf("Enter number of frames: ");
    scanf("%d",&frames);

    int f[frames];

    for(i=0;i<frames;i++)
        f[i]=-1;

    int index=0;

    for(i=0;i<pages;i++)
    {
        int found=0;

        for(j=0;j<frames;j++)
        {
            if(f[j]==p[i])
            {
                found=1;
                break;
            }
        }

        if(!found)
        {
            f[index]=p[i];
            index=(index+1)%frames;
            faults++;
        }
    }

    printf("FIFO Page Faults = %d\n",faults);

    return 0;
}