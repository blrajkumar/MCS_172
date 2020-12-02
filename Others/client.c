/***********************************
* MCS 172  - Assignment		   
* Filename : client.c	  	
* Author   : Rajkumar B L	 	
* Reg.No   : 2047120	
************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#define PORT 8080

int main()
{
    int sock = 0, valread;
    char info_to_server[100];
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    bool c_conct=true;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    else
    {
        printf("\nConnection Established ... \n");
    }

    while (c_conct)
    {

        char ch;
        //Menu Received
        valread = read(sock, buffer, 1024); //Read 1
        printf("%s\n", buffer);
        memset(buffer, 0, sizeof(buffer));

        memset(info_to_server, 0, sizeof(info_to_server));
        strcpy(info_to_server, "Client received the menu...");
        send(sock, info_to_server, strlen(info_to_server), 0); // Send 1
        memset(info_to_server, 0, sizeof(info_to_server));

        //Reading form server - Asking to enter the choice
        valread = read(sock, buffer, 1024); //Read 2
        printf("%s\n", buffer);
        memset(buffer, 0, sizeof(buffer));

        //Sending the Choice to the server
        scanf("%s",info_to_server);
        send(sock, info_to_server, strlen(info_to_server), 0); // Send 2 - sending client choice
        memset(info_to_server, 0, sizeof(info_to_server));
        
        //Reading the total cart value
        valread = read(sock, buffer, 1024); //Read 3
        printf("%s\n", buffer);
        memset(buffer, 0, sizeof(buffer));

        //Reading - if to add more pizza to cart
        valread = read(sock, buffer, 1024); //Read 4
        printf("%s\n", buffer);
        memset(buffer, 0, sizeof(buffer));

        //Sending the more pizza Choice to the server
        scanf("%s", info_to_server);
        send(sock, info_to_server, strlen(info_to_server), 0); // Send 3 - sending client choice
        //printf("%s", info_to_server);
        ch = info_to_server[0];
        if (ch == 'y')
        {
            c_conct = true;
            memset(info_to_server, 0, sizeof(info_to_server));
        }
        else
        {
            c_conct = false;
            //Reading - end note
            valread = read(sock, buffer, 1024); //Read end 1
            printf("%s\n", buffer);
            memset(buffer, 0, sizeof(buffer));

            valread = read(sock, buffer, 1024); //Read end 2
            printf("%s\n\n", buffer);
            memset(buffer, 0, sizeof(buffer));
            memset(info_to_server, 0, sizeof(info_to_server));
        }
    }
       
    return 0;
}
