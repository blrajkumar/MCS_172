#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mesg_buffer
{
	long mesg_type;
	char mesg_text[100];
} message;

int main()
{

	key_t key = 12345;
	int msgid;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgrcv(msgid, &message, sizeof(message), 1, 0);
	printf("DATA FROM SERVER IS : %s \n", message.mesg_text);

	//send response
	printf("DATA TO SERVER PROGRAM : ");
	// gets(message.mesg_text);
	scanf("%s", message.mesg_text);
	message.mesg_type = 2;
	msgsnd(msgid, &message, sizeof(message), 0);

	msgctl(msgid, IPC_RMID, NULL);

	return 0;
}
