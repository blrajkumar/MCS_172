#include <stdio.h> 
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h> 
#include <sys/msg.h> 
  
// structure for message queue 
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[100]; 
} ; 
  
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

    if((msgid=msgget(key,0644 | IPC_CREAT))==-1)
    {
        perror("msgid");
        exit(1);
    }
    else
    {
        printf("\nThe message id is %d", msgid);
    }
    
    
    printf("\nThe message id is %d",msgid);

    printf("\nEnter the text to send");
    message.mesg_type=1;

    while(gets(message.mesg_text),!feof(stdin))
    {
        if (msgsnd(msgid, &message, sizeof(message), 0) == -1)
        {
            perror("Msgsend");
            exit(1);
        }
    }
        
   
    if(msgctl(msgid,IPC_RMID,NULL)==-1)
    {
        perror("Msgctl");
        exit(1);
    }

    return 0; 
} 