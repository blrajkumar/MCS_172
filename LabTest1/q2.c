/*
 * Student Name : Rajkumar B L
 * Student id   : 2047120
 * Email        : rajkumar.bl@cs.christuniversity.in
 * MCS 172      : Lab Test - 01
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void part1();
void part2();

int main()
{
    int choice;
    bool option = false;
    char menu[] = "\n=========================\n\tMenu\n=========================\n1.Create, Read & Write File\n2.UnLink\n3.Exit\n=========================";

    while (!option)
    {
        printf("%s", menu);
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            part1();
            option = false;
            break;

        case 2:
            part2();
            option = false;
            break;

        case 3:
            option = true;
            break;

        default:
            printf("\nInvalid choice. Try again!");
            option = false;
            break;
        }
    }

    return 0;
}

void part1()
{
    int fd,fd2;
    char file[30];
    char txt[50];
    printf("Enter the file name to be created or opened: ");
    scanf("%s", file);
    if ((fd = open(file, O_CREAT | O_RDWR, 0777)) < 0)
    {
        printf("Error in file creation or opening!\n");
    }
    else
    {
        printf("File Creted or opened succesfully\n");
        while (read(fd, txt, 50))
            write(STDOUT_FILENO, txt, strlen(txt));
        if ((fd2 = open("file2.txt",O_RDWR, 0777)) < 0)
        {
            printf("Error in opening file2 to write into\n");
        }
        else
        {
            lseek(fd, 50, SEEK_SET);
            while (read(fd, txt, 50))
                write(fd2, txt, strlen(txt));
        }
        close(fd);
    }
}

void part2()
{
    char file[30];
    printf("Enter the file to be unlinked: ");
    scanf("%s",file);
    const char *path = file;
    if (unlink(path) == -1)
    {
        printf("Error in unlinking the file!\n");
        
    }
    else
    {
        printf("File unlinked successfully\n");
    }
    
}
