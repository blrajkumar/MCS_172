#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <string.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
int main()
{
    sem_t MUTEX;
    char ch[50];
    int len;
    int fd, fd1;
    sem_init(&MUTEX, 1, 1);
    int pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        sem_wait(&MUTEX);
        printf("IN CHILD PROCESS :\n");
        fd = open("FILE2.txt", O_CREAT | O_WRONLY, 0777);
        printf("\nEnter content to be written in FILE2.txt.\n");
        fgets(ch, 50, stdin);
        len = strlen(ch);
        write(fd, ch, 50);
        printf("Writing done\n");
        close(fd);
        fd1 = open("FILE1.txt", O_CREAT | O_RDONLY, 0777);
        while (read(fd, ch, 50) > 0)
            write(STDOUT_FILENO, ch, strlen(ch));
        close(fd1);
        sem_post(&MUTEX);
    }
    else
    {
        printf("IN PARENT PROCESS :");
        wait(NULL);
        sem_wait(&MUTEX);
        fd = open("FILE1.txt", O_CREAT | O_WRONLY, 0777);
        printf("\nEnter content to be written in FILE1.txt.\n");
        fgets(ch, 50, stdin);
        len = strlen(ch);
        write(fd, ch, 50);
        printf("Writing done\n");
        close(fd);
        fd1 = open("FILE2.txt", O_CREAT | O_RDONLY, 0777);
        while (read(fd, ch, 50) > 0)
            write(STDOUT_FILENO, ch, strlen(ch));
        close(fd1);
        sem_post(&MUTEX);
    }
}