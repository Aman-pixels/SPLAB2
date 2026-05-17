#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>

int main()
{
    int shmid;
    int *buffer;
    int n,i;

    shmid=shmget(IPC_PRIVATE,1024,0666|IPC_CREAT);
    buffer=(int*)shmat(shmid,NULL,0);

    printf("Enter number of items: ");
    scanf("%d",&n);

    if(fork()==0)
    {
        for(i=0;i<n;i++)
        {
            printf("Producer produced: ");
            scanf("%d",&buffer[i]);
        }
        exit(0);
    }
    else
    {
        wait(NULL);
        for(i=0;i<n;i++)
        {
            printf("Consumer consumed: %d\n",buffer[i]);
        }
        shmdt(buffer);
        shmctl(shmid,IPC_RMID,NULL);
    }

    return 0;
}