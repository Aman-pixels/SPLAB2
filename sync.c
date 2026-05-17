#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int buffer;
sem_t empty,full;

void *producer()
{
    int item;

    printf("Enter item: ");
    scanf("%d",&item);

    sem_wait(&empty);
    buffer=item;
    printf("Produced: %d\n",buffer);
    sem_post(&full);
}

void *consumer()
{
    sem_wait(&full);
    printf("Consumed: %d\n",buffer);
    sem_post(&empty);
}

int main()
{
    pthread_t p,c;

    sem_init(&empty,0,1);
    sem_init(&full,0,0);

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);

    return 0;
}