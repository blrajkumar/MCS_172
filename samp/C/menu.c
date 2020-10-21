#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dup();
void link();
void unlink();
void lseek();

int main()
{
    int choice;
    bool option = false;
    char menu[] = "\n=========================\n\tMenu\n=========================\n1.Dup\n2.Link\n3.UnLink\n4.Lseek\n5.Exit\n=========================";

    while (!option)
    {
        printf("%s", menu);
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            option = false;
            break;

        case 2:
            option = false;
            break;

        case 3:
            option = false;
            break;

        case 4:
            option = false;
            break;

        case 5:
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

void dup()
{
}

void link()
{
}

void unlink()
{
}

void lseek()
{
}