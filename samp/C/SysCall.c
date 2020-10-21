#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void flopen();
void flread();
void flwrite();
void fldup();
void fllink();
void flunlink();
void fllseek();

int main()
{
    int choice;
    bool option = false;
    char menu[] = "=====Menu=======\n1.open\n2.close\n3.read\n4.write\n5.dup\n6.link\7.unlink\n8.lseek\n=========\n";

    while (!option)
    {
        printf("%s", menu);
        printf("Enter the choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            flopen();
            option = true;
            break;
        case 2:
            flread();
            option = true;
            break;

        case 3:
            flwrite();
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

flopen()
{
    int fd;
    char file[30];
    printf("Enter the file name to be created or opened: ");
    scanf("%s", file);
    if ((fd = open(file, O_CREAT | O_RDWR, 0777)) < 0)
    {
        printf("Error in file creation or opening!");
    }
    else
    {
        printf("File Creted or opened succesfully: ");
        close(fd);
    }
}

flread()
{
    int fd;
    char file[30];
    char content[100];
    printf("Enter the file to be read: ");
    scanf("%s", file);
    if ((fd = open(file, O_RDONLY | O_CREAT, 0777)) < 0)
    {
        printf("Error in opening or reading the file: ");
    }
    else
    {
        printf("Information read from the file:\n");
        while (read(fd, content, 5))
            write(STDOUT_FILENO, content, 5);
    }
}

flwrite()
{
    int fd;
    char file[30];
    char content[100];
    printf("Enter the file to write: ");
    scanf("%s", file);
    if ((fd = open(file, O_WRONLY, 0777)) < 0)
    {
        printf("Error in opening the file: ");
    }
    else
    {
        printf("Enter the information to be written: ");
        scanf("%s", content);
        if ((write(fd, content, strlen(content))) < 0)
        {
            printf("Error i writing to the file");
        }
        else
        {
            printf("Information written succesfully");
        }
    }
}

fldup()
{
    int fd = open("dup_dummy.txt", O_WRONLY | O_APPEND);
    if (fd < 0)
        printf("Error opening the file\n");
    int cpy_fd = dup(fd);
    write(cpy_fd, "\nHey, i am writing to this txt file using cpy_fd\n", 51);
    write(fd, "\nHey, i am writing to this txt file using fd\n", 51);
}

fllink()
{
    printf("Link function\n");
    char *path1 = "a1";
    char *path2 = "chmaaa1";
    int status;
    link(path1, path2); //0 is success and -1 error
}

flunlink()
{
    const char *path = "chmaaa1";
    unlink(path); //0 is success and -1 error
}

fllseek()
{
    int fd = open("dup_dummy.txt", O_WRONLY | O_APPEND);
    lseek(fd, 5, SEEK_CUR);
    write(fd, "\nHello Lseek World\n", 51);
}
