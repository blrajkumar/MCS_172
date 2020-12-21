#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main()
{
    char flname[30] = "File1.txt";
    int fd = open(flname, O_CREAT | O_WRONLY | O_APPEND | O_CLOEXEC);
    printf("Hey raj, you are currently executing execution.c program\n");
    printf("PID ofexecution.c = %d\n", getpid());
    printf("FD of new prg execution.c is = %d\n", fd);
    write(fd, "EXEC\n", 6);
    return 0;
}