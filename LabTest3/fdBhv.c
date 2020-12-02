#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void fd_fork();
void fd_exec();
 
int main()
{
    int choice;
    bool option = false;
    char fl[30];

    printf("=========================\n\tMenu\n=========================\n1.Fork\n2.Exec\n3.Exit\n=========================");

    while (!option)
    {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            fd_fork();
            option = false;
            break;

        case 2:
            fd_exec();
            option = false;
            break;

        case 3:
            option = true;
            break;

        default:
            printf("\nInvalid choice. Try again!");
            option = false;
        }
    }

    return 0;
}

void fd_fork()
{
    char flname[30]="File.txt";
    int fd = open(flname, O_CREAT| O_WRONLY | O_APPEND);
    if (fd < 0)
        printf("Error opening the file...\n");
    else
        printf("File opened succesfully...\n");

    int pid=fork();
    if (pid!=0)
    {
        printf("This is child writing to the file with fd = %d\n", fd);
        write(fd, "Raj ", 6);
        
    }
    else
    {
        printf("This is parent writing to the file with fd = %d\n", fd);
        write(fd, "Kumar\n", 6);
        close(fd);
        _exit(0);
    }
}

void fd_exec()
{
    char flname[30] = "File2.txt";
    int fd = open(flname, O_CREAT | O_WRONLY | O_APPEND | O_CLOEXEC);
    if (fd < 0)
        printf("Error opening the file...\n");
    else
        printf("File opened succesfully...\n");

    printf("FD of current fdBhv is = %d\n", fd);
    execv("./excute", NULL);
    write(fd, "FDBHV\n", 6);
}