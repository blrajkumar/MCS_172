#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include<string.h>
int main()
{
	int i ;
	key_t key = 6000;
	int shmid = shmget(key, 27, IPC_CREAT | 0666);
	if(shmid<0)
	{
		perror("SHMID ERROR!!!");
		return 0;
	}
 
	 char *shm = shmat(shmid, NULL, 0); 
	if(shm=="-1")
	{
		perror("SHMAT ERROR!!!");
	        return 0;
	}

	char str[100] ;
	printf("\nEnter text to be witten into shared memory: ");
	scanf("%s",str);
	char *s = shm;
	printf("\nWRITER WRITES: ");
	for (i=0;i<strlen(str);i++)
	{
		char c = str[i];	
		putchar(c);	
		*s++ = c;
	}
	*s = '\0';

	printf("\nWRITER SLEEPING\n");
	while (*shm!= '*')
        	sleep(1);

	printf("\nWRITER READ:");
	for (s = shm+1; *s!= '\0'; s++)
        	putchar(*s);
    	putchar('\n');
	shmctl(shmid,IPC_RMID,NULL);
	printf("PROGRAM COMPLETED AND THE SHMID IS DESTROYED\n");

	return 0;
}
