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
    shmid = shmget((key_t)2345, 1024, 0666);
    printf("Key of shared memory is %d\n", shmid);
    sm = shmat(shmid, NULL, 0);
    printf("Process attached at %p\n", sm);
    printf("Data read from shared memory is : %s\n", sm);
    shmdt(sm);
    shmctl(shmid, IPC_RMID, NULL);
}
