#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t mutex,writeblock;
int data=0,rcount=0;

void *reader(void *arg)
{
    int f=*((int*)arg);

    sem_wait(&mutex);
    rcount++;

    if(rcount==1)
        sem_wait(&writeblock);

    sem_post(&mutex);

    printf("Reader %d reads data = %d\n",f,data);

    sem_wait(&mutex);
    rcount--;

    if(rcount==0)
        sem_post(&writeblock);

    sem_post(&mutex);
}

void *writer(void *arg)
{
    int f=*((int*)arg);

    sem_wait(&writeblock);

    data++;
    printf("Writer %d writes data = %d\n",f,data);

    sem_post(&writeblock);
}

int main()
{
    pthread_t r[3],w[2];
    sem_init(&mutex,0,1);
    sem_init(&writeblock,0,1);

    int a[3]={1,2,3};
    int b[2]={1,2};

    pthread_create(&w[0],NULL,writer,&b[0]);
    pthread_create(&r[0],NULL,reader,&a[0]);
    pthread_create(&r[1],NULL,reader,&a[1]);
    pthread_create(&w[1],NULL,writer,&b[1]);
    pthread_create(&r[2],NULL,reader,&a[2]);

    for(int i=0;i<3;i++)
        pthread_join(r[i],NULL);

    for(int i=0;i<2;i++)
        pthread_join(w[i],NULL);

    return 0;
}