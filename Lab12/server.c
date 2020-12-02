#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
    int i;
    void *sm = ((char *)sm);
    char buff[100];
    int shmid;
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    printf("Key of shared memory is %d\n", shmid);
    sm = shmat(shmid, NULL, 0);
    printf("Process attached at %p\n", sm);
    printf("Enter some data to write to shared memory\n");
    read(0, buff, 100);
    strcpy(sm, buff);
    printf("You wrote : %s\n", sm);
}
