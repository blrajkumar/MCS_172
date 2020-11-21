#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main()
{
    int mq;
    key_t k = ftok("/var", 'c');
    if (k != -1)
    {
        mq = msgget(k, 0644 | IPC_CREAT);
        if (mq != -1)
        {
            char b[256] = "";
            while (1)
            {
                if (msgrcv(mq, &b, sizeof(b), 0, 0) != -1)
                {
                    if (strcmp(b, "stop") == 0)
                        break;
                    printf("%s\n", b);
                }
                else
                {
                    perror("msgrcv()");
                    break;
                }
            }
        }
        else
        {
            perror("msgget()");
            return 2;
        }
    }
    else
    {
        perror("ftok()");
        return 1;
    }
    return 0;
}