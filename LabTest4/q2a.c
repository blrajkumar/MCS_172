#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>
int main()
{
    for (int i = 0; i < 4; i++)
    {   
        if (fork() == 0)
        {
            printf("Hey this is child(%d), My pid is : %d and My parent pid is : %d\n", (i+1) ,getpid(), getppid());
            printf("Child(%d) Terminated\n", (i + 1));
            exit(0);
        }
    }
    for (int i = 0; i < 4; i++) 
    {
        wait(NULL);
    }
    printf("Parent(%d) Terminated\n", getpid());
    exit(0);
}
