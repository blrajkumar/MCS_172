#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid, pid1, pid2, pid3;

    pid = fork();

    if (pid == 0)
    {

        sleep(3);
        printf("Hey this is child(01), My pid is : %d and My parent pid is : %d\n", getpid(), getppid());
    }

    else
    {
        pid1 = fork();
        if (pid1 == 0)
        {
            sleep(2);
            printf("Hey this is child(02), My pid is : %d and My parent pid is : %d\n", getpid(), getppid());
        }
        else
        {
            pid2 = fork();
            if (pid2 == 0)
            {
                printf("Hey this is child(03), My pid is : %d and My parent pid is : %d\n", getpid(), getppid());
            }

            else
            {
                pid3 = fork();
                if (pid3 == 0)
                {
                    printf("Hey this is child(04), My pid is : %d and My parent pid is : %d\n", getpid(), getppid());
                }
                else
                {

                    sleep(3);
                    wait(NULL);
                    wait(NULL);
                    wait(NULL);
                    wait(NULL);
                    printf("This is parent is runing with id  %d\n", getpid());
                }
            }
        }
    }

    return 0;
}