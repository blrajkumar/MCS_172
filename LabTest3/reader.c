#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include<string.h>

int main()
{
	int X,i;

	key_t key = 6000;
	int shmid =  shmget(key, 27, 0666);
	if(shmid<0)
	{
		perror("SHMID ERROR!!!");
		return 0;
	}
 
	char *shm = (shm = shmat(shmid, NULL, 0)); 
	if(shm=="-1")
	{
		perror("SHMAT ERROR!!!");
	        return 0;
	}

	printf("\nREADER READING: ");	
	char *s = shm;
	char buff[100];
	int count=0;
	for (s = shm; *s!='\0'; s++)
        {	
		char c = *s;
		putchar(c);
		buff[count]=c;	
		count++;
	}    	
	putchar('\n');
	
	
	//printf("\nReader Wrote: %s\n",buff);
	printf("\nEnter text to be witten into shared memory: ");
	scanf("%s", buff);
	s = shm;
	*s++;
	for (i=0;i<strlen(buff);i++)
	{
		char c = buff[i];		
		*s++ = c;
	}
	
	*s = '\0';
	*shm ='*';
	
	return 0;
}
