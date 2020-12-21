#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>
int main()
{
    int pid,pid2;
    pid = fork();
    if (pid == 0)
    {
            printf("I am Child --> Printing odd numbers ");
            for (int i = 0; i <= 99999; i++)
            {
                if (!(i % 2 == 0))
                {
                    printf("\n%d ", i);
                }
            }
            printf("\n");
            exit(0);
    }
    sleep(1);
    kill(pid,SIGINT);
    return 0;
}
