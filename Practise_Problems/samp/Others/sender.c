#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 100

// message queue
struct mesg
{
	long mesg_type;
	char mesg_text[MAX];
} message;

int main()
{
	key_t key = 12345;
	int msgid;
	msgid = msgget(key, 0666 | IPC_CREAT);
	message.mesg_type = 1;
	printf("Messase to Client : ");
	
	scanf("%s", message.mesg_text);
	msgsnd(msgid, &message, sizeof(message), 0);

	msgrcv(msgid, &message, sizeof(message), 2, 0);
	printf("Messege from Client: %s \n", message.mesg_text);

	return 0;
}
