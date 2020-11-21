/*
 * Student Name : Rajkumar B L
 * Student id   : 2047120
 * Email        : rajkumar.bl@cs.christuniversity.in
 * MCS 172      : Lab Test - 02
 */

#include <stdio.h>
#include <unistd.h>

int main()
{
    int pipefds1[2], pipefds2[2];
    int pp1return, pp2return;
    int pid;
    int parentid,childid;
    char pipe1wrbuff[50] = "I am your parent and My Id is ";
    char pipe2wrbuff[50] = "Hi parent, My ID is ";
    char rdbuff[50];
    pp1return = pipe(pipefds1);
    if (pp1return == -1)
    {
        printf("Error in creating pipe 1\n");
        return 1;
    }
    pp2return = pipe(pipefds2);

    if (pp2return == -1)
    {
        printf("Error in creating pipe 2\n");
        return 1;
    }
    pid = fork();
    if (pid == 0)
    {
        parentid = getppid();
        childid = getpid();
    }
    if (pid != 0) // Parent process
    {
        close(pipefds1[0]);
        close(pipefds2[1]);
        write(pipefds1[1], pipe1wrbuff, sizeof(pipe1wrbuff));
        read(pipefds2[0], rdbuff, sizeof(rdbuff));
        printf("Parent Reading from child, the message is ------> %s%d\n", rdbuff,parentid);
    }
    else
    {
        close(pipefds1[1]);
        close(pipefds2[0]); 
        read(pipefds1[0], rdbuff, sizeof(rdbuff));
        printf("Child Reading from parent, the message is ------> %s%d\n", rdbuff,childid);
        write(pipefds2[1], pipe2wrbuff, sizeof(pipe2wrbuff));
    }
    return 0;
}

