#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX 100

// message queue
struct mesg_buffer
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
	printf("DATA TO CLIENT PROGRAM : ");
	//gets(message.mesg_text);
	scanf("%s", message.mesg_text);
	msgsnd(msgid, &message, sizeof(message), 0);
	sleep(10);

	//read response
	msgrcv(msgid, &message, sizeof(message), 2, 0);
	printf("DATA FROM CLIENT IS : %s \n", message.mesg_text);

	return 0;
}
