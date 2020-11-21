
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BUFF 100

void *consume(void *arg);
void *produce(void *arg);
int buf[MAX_BUFF], front, rear;
sem_t lock, full, empty;

int main()
{
	pthread_t pid, cid;
	sem_init(&lock, 1, 1);
	sem_init(&full, 1, 0);
	sem_init(&empty, 1, 1);
	pthread_create(&pid, NULL, produce, NULL);
	pthread_create(&cid, NULL, consume, NULL);
	pthread_join(pid, NULL);
	pthread_join(cid, NULL);
}
void *produce(void *arg)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		sem_wait(&empty);
		sem_wait(&lock);
		printf("produced item is %d\n", i);
		buf[(++rear) % MAX_BUFF] = i;
		sleep(1);
		sem_post(&lock);
		sem_post(&full);
	}
	return NULL;
}
void *consume(void *arg)
{
	int item, i;
	for (i = 0; i < 10; i++)
	{
		sem_wait(&full);
		sem_wait(&lock);
		item = buf[(++front) % MAX_BUFF];
		printf("consumed item is %d\n", item);
		sleep(1);
		sem_post(&lock);
		sem_post(&empty);
	}
	return NULL;
}