#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

// structure for message queue
struct mesg_buffer
{
    long mesg_type;
    char mesg_text[100];
};

int main()
{
    key_t key;
    int msgid;
    struct mesg_buffer message;

    if (key = ftok("prgpath", 65) == -1)
    {
        perror("Key");
        exit(1);
    }

    if ((msgid = msgget(key, 0644)) == -1)
    {
        perror("msgid");
        exit(1);
    }

    printf("\nThe message id is %d", msgid);

    for(;;)
    {
        if (msgrcv(msgid, &message, sizeof(message),1, 0) == -1)
        {
            perror("Msgsend");
            exit(1);
        }
    }

    if (msgctl(msgid, IPC_RMID, NULL) == -1)
    {
        perror("Msgctl");
        exit(1);
    }

    return 0;
}