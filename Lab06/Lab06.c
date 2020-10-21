#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void dup_func();
int link_func();
int unlink_func();
void lseek_func();

int main()
{
    int choice;
    bool option = false;
    
    printf("=========================\n\tMenu\n=========================\n1.Dup\n2.Link\n3.UnLink\n4.Lseek\n5.Exit\n=========================");

    while (!option)
    {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            dup_func();
            option = true;
            break;

        case 2:
            if (link_func() == 0)
            {
                printf("Linked Successfully\n");
            }
            else
            {
                printf("Error in linking\n");
            }
            option = true;
            break;

        case 3:
            if (unlink_func() == 0)
            {
                printf("Un-Linked Successfully\n");
            }
            else
            {
                printf("Error in Un-Linking\n");
            }
            option = true;
            break;

        case 4:
            lseek_func();
            option = true;
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
    int fd = open("dup_dummy.txt", O_WRONLY | O_APPEND);
    if (fd < 0)
        printf("Error opening the file\n");
    int cpy_fd = dup(fd);
    write(cpy_fd, "\nHey, i am writing to this txt file using cpy_fd\n", 51);
    write(fd, "\nHey, i am writing to this txt file using fd\n", 51);
}


int link_func()
{
    printf("Link function\n");
    char *path1 = "a1";
    char *path2 = "chmaaa1";
    int status;
    return link(path1, path2);
}

int unlink_func()
{
    const char *path = "chmaaa1";
    return unlink(path);
}

void lseek_func()
{
    int fd = open("dup_dummy.txt", O_WRONLY | O_APPEND);
    lseek(fd,5,SEEK_CUR);
    write(fd, "\nHello Lseek World\n", 51);
}