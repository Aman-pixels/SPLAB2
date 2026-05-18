#include<stdio.h>

int search(int key,int frame[],int f)
{
    for(int i=0;i<f;i++)
    {
        if(frame[i]==key)
            return 1;
    }
    return 0;
}

int predict(int pages[],int frame[],int pn,int index,int f)
{
    int farthest=index,res=-1;

    for(int i=0;i<f;i++)
    {
        int j;

        for(j=index;j<pn;j++)
        {
            if(frame[i]==pages[j])
            {
                if(j>farthest)
                {
                    farthest=j;
                    res=i;
                }
                break;
            }
        }

        if(j==pn)
            return i;
    }

    if(res==-1)
        return 0;
    else
        return res;
}

int main()
{
    int pn,f,i,j;

    printf("Enter number of pages: ");
    scanf("%d",&pn);

    int pages[pn];

    printf("Enter page reference string:\n");
    for(i=0;i<pn;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);

    int frame[f];

    for(i=0;i<f;i++)
        frame[i]=-1;

    int faults=0,index=0;

    printf("\nFIFO Page Replacement\n");

    for(i=0;i<pn;i++)
    {
        if(!search(pages[i],frame,f))
        {
            frame[index]=pages[i];
            index=(index+1)%f;
            faults++;
        }
    }

    printf("FIFO Page Faults = %d\n",faults);

    for(i=0;i<f;i++)
        frame[i]=-1;

    faults=0;
    int filled=0;

    printf("\nOptimal Page Replacement\n");

    for(i=0;i<pn;i++)
    {
        if(search(pages[i],frame,f))
            continue;

        if(filled<f)
        {
            frame[filled]=pages[i];
            filled++;
        }
        else
        {
            j=predict(pages,frame,pn,i+1,f);
            frame[j]=pages[i];
        }

        faults++;
    }

    printf("Optimal Page Faults = %d\n",faults);

    return 0;
}