#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define bufsz 100
char txt[bufsz];
char fd1_name[bufsz];
int   fd1;

void dup_func();
int write_func();
int open_func();
void lseek_func();

int main()
{
    int choice;
    bool option = false;

    printf("=========================\n\tMenu\n=========================\n1.Dup\n2.Write\n3.Open\n4.Lseek\n5.Exit\n=========================");

    while (!option)
    {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            dup_func();
            option = false;
            break;

        case 2:
            write_func();
            option = false;
            break;

        case 3:
            open_func();
            option = false;
            break;

        case 4:
            lseek_func();
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

void dup_func()
{
    printf("Enter the File name to dup\n");
    scanf("%s", txt);
    int fd = open(txt, O_WRONLY | O_APPEND);
    if (fd < 0)
        printf("Error opening the file\n");
    int cpy_fd = dup(fd);
    write(cpy_fd, "\nHey, i am writing to this txt file using cpy_fd\n", 51);
    write(fd, "\nHey, i am writing to this txt file using fd\n", 51);
}

int write_func()
{
    printf("Enter the File name to be Write:\n");
    scanf("%s", fd1_name);
    if ((fd1 = open(fd1_name, O_CREAT | O_WRONLY | O_TRUNC, 0777)) < 0)
    {
        printf("Error in opening the file\n");
    }
    else
    {
        printf("Enter the information to write in the file\n");
        scanf("%s", txt);
        if ((write(fd1, txt, strlen(txt))) < 0)
        {
            printf("Error in writing to the file\n");
        }
        else
        {
            printf("\nInformation appended Successfully\n");
            close(fd1);
            printf("\nFile Closed\n");
        }
    }
}

int open_func()
{
    printf("Enter the File name to open\n");
    scanf("%s", txt);
    fd1 = open(txt, O_RDONLY, 0777);
    printf("Information about the file\n");
    while (read(fd1, txt, 50) > 0)
        write(STDOUT_FILENO, txt, 5);
    close(fd1);
}

void lseek_func()
{
    printf("Enter the File name to lseek\n");
    scanf("%s", txt);
    int fd = open(txt, O_WRONLY | O_APPEND);
    lseek(fd, 5, SEEK_CUR);
    write(fd, "\nHello Lseek World\n", 51);
}