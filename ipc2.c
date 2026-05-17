#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

struct msgbuf
{
    long type;
    int data;
};

int main()
{
    int msgid,n,i;
    struct msgbuf message;

    msgid=msgget(IPC_PRIVATE,0666|IPC_CREAT);

    printf("Enter number of items: ");
    scanf("%d",&n);

    if(fork()==0)
    {
        for(i=0;i<n;i++)
        {
            printf("Enter item: ");
            scanf("%d",&message.data);
            message.type=1;
            msgsnd(msgid,&message,sizeof(int),0);
        }
        exit(0);
    }
    else
    {
        wait(NULL);

        for(i=0;i<n;i++)
        {
            msgrcv(msgid,&message,sizeof(int),1,0);
            printf("Consumed: %d\n",message.data);
        }

        msgctl(msgid,IPC_RMID,NULL);
    }

    return 0;
}