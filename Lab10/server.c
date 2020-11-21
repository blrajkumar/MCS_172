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
            size_t l;
            while (fgets(b, sizeof(b), stdin) != NULL)
            {
                if ((l = strlen(b)) > 0)
                {
                    if (b[l - 1] == '\n')
                    {
                        b[l - 1] = 0;
                        l--;
                    }
                    if (strcmp(b, "quit") == 0)
                        break;
                    if (msgsnd(mq, &b, l, 0) == -1)
                    {
                        perror("msgsnd()");
                        break;
                    }
                }
            }
        }
        else
        {
            perror("msgget()");
            return 2;
        }
        if (msgctl(mq, 0, NULL) == -1)
        {
            perror("msgctl()");
            return 3;
        }
    }
    else
    {
        perror("ftok()");
        return 1;
    }
    return 0;
}