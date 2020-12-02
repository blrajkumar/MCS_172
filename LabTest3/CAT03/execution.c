#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main()
{

    char flname[30] = "File2.txt";
    int fd = open(flname, O_CREAT | O_WRONLY | O_APPEND | O_CLOEXEC);
    printf("Hey raj, you are currently executing execution.c program\n");
    printf("PID ofexecution.c = %d\n", getpid());
    printf("FD of new prg execution.c is = %d\n", fd);
    write(fd, "This is from exec\n", 18);
    return 0;
}