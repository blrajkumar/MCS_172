#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void fd_fork();
void fd_exec();
void fd_dup();
void fd_dup2(); 

int main()
{
    int choice;
    bool option = false;
    char fl[30];

    printf("=========================\n\tMenu\n=========================\n1.Fork\n2.Exec\n3.Dup\n4.Dup2\n5.Exit\n=========================");

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
            fd_dup();
            option = false;
            break;

        case 4:
            fd_dup2();
            option = false;
            break;

        case 5:
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
    char flname[30]="File1.txt";
    int fd = open(flname, O_CREAT| O_WRONLY | O_APPEND);
    if (fd < 0)
        printf("Error opening the file...\n");
    else
        printf("File opened succesfully...\n");

    int pid=fork();
    if (pid!=0)
    {
        printf("This is child writing to the file with fd = %d\n", fd);
        write(fd, "hello ", 6);
        
    }
    else
    {
        printf("This is parent writing to the file with fd = %d\n", fd);
        write(fd, "world\n", 6);
        _exit(0);
    }
}

void fd_exec()
{
    char flname[30] = "File1.txt";
    int fd = open(flname, O_CREAT | O_WRONLY | O_APPEND | O_CLOEXEC);
    if (fd < 0)
        printf("Error opening the file...\n");
    else
        printf("File opened succesfully...\n");

    printf("FD of current fdBhv is = %d\n", fd);
    execv("./execut", NULL);
    write(fd, "FDBHV\n", 6);
}

void fd_dup()
{
    char flname[30] = "File1.txt";
    int fd = open(flname, O_CREAT | O_WRONLY | O_APPEND | O_CLOEXEC);
    if (fd < 0)
        printf("Error opening the file...\n");
    else
        printf("File opened succesfully...\n");


    int cpy_fd = dup(fd);
    printf("Writing to the file using fd --> %d\n", fd);
    write(fd, "\nHey, i am writing to this txt file using fd\n", 49);
    printf("Writing to the file using dup(fd) --> %d\n", cpy_fd);
    write(cpy_fd, "\nHey, i am writing to this txt file using cpy_fd\n", 49);
    
}

void fd_dup2()
{
    char flname[30] = "File1.txt";
    int fd = open(flname, O_CREAT | O_WRONLY | O_APPEND | O_CLOEXEC);
    if (fd < 0)
        printf("Error opening the file...\n");
    else
        printf("File opened succesfully...\n");

    printf("Writing to the file using my original/old fd --> %d\n", fd);
    write(fd, "\nHey, i am writing to this txt file using  my original/old fd\n", 49);
    int new_fd = dup2(fd, 20);
    printf("Writing to the file using my  new fd after dup2(fd,new value) --> %d\n", new_fd);
    write(fd, "\nHey, i am writing to this txt file using my new fd after dup2(fd,new value)\n", 49);
}