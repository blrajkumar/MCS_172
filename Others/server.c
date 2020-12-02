/***********************************
* MCS 172  - Assignment		   
* Filename : server.c	  	
* Author   : Rajkumar B L	 	
* Reg.No   : 2047120	
************************************/
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <stdbool.h>
#define PORT 8080
int cart();

int main()
{
    int server_fd, new_socket, valread;
    char info_to_customer[250];
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    bool s_conct = true;

    char menu[250] = "\n============================\n       Pizza-Hut Menu\n============================\n1.Hawaiin      ---> Rs.150\n2.Greek-Veg    ---> Rs.200\n3.Pepperoni    ---> Rs.250\n4.Triple Crown ---> Rs.300\n5.BBQchicken   ---> Rs.250\n============================";
    int cart_amount = 0;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,(socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }


    while (s_conct)
    {
        char ch;
        //Sending Menu to the client
        send(new_socket, menu, strlen(menu), 0); //Send 1 Menu

        valread = read(new_socket, buffer, 1024); // Read 1 if the menu is received
        printf("\nConnection Established ... \n");
        printf("%s\n", buffer);
        memset(buffer, 0, strlen(buffer));

        //Ask the user to enter the choice
        memset(info_to_customer, 0, strlen(info_to_customer));
        strcpy(info_to_customer, "Enter the choice to add to the cart:");
        send(new_socket, info_to_customer, strlen(info_to_customer), 0); //Send 2 - Enter the choice
        memset(info_to_customer, 0, strlen(info_to_customer));

        //Read the option selected by the client
        valread = read(new_socket, buffer, 1024); // Read 2
        printf("Client responded with their choice...\n");

        char ct_amt_st[5];
        cart_amount = cart_amount + cart(buffer);
        printf("Total Amount in the cart is %d\n", cart_amount);
        memset(buffer, 0, sizeof(buffer));
        //Sending current cart total amount to client
        strcpy(info_to_customer, "Cart total = ");
        snprintf(ct_amt_st, 5, "%d", cart_amount);
        strcat(info_to_customer, ct_amt_st);
        send(new_socket, info_to_customer, strlen(info_to_customer), 0); //Send 3 - Sending total cart value
        memset(info_to_customer, 0, sizeof(info_to_customer));

        //Asking customer if they want to add more pizzas to the cart
        strcpy(info_to_customer, "\nWould you like to add more pizza's to the cart (y/n):");
        send(new_socket, info_to_customer, strlen(info_to_customer), 0); //Send 4 - Asking to add more item
        memset(info_to_customer, 0, sizeof(info_to_customer));

        //Read the option selected by the client for more pizza
        valread = read(new_socket, buffer, 1024); // Read 3
        printf("Client responded with their choice...\n");
        //printf("%s", buffer);
        ch=buffer[0];
        if (ch=='y')
        {
            s_conct = true;
            memset(buffer, 0, strlen(buffer));
        }
        else
        {
            memset(info_to_customer, 0, sizeof(info_to_customer));
            strcpy(info_to_customer, "\nYour order has been placed.\nOn delivery pay a toatl of RS.");
            snprintf(ct_amt_st, 5, "%d", cart_amount);
            strcat(info_to_customer, ct_amt_st);
            send(new_socket, info_to_customer, strlen(info_to_customer), 0); //Send end 1 - Sending total cart value
            memset(info_to_customer, 0, sizeof(info_to_customer));

            s_conct = false;
            strcpy(info_to_customer, "\nThank you for visiting us today.\nHave a happy day!");
            send(new_socket, info_to_customer, strlen(info_to_customer), 0); //Send end 2 - sending end note
            memset(buffer, 0, strlen(buffer));
            printf("\nConnection ended ... \n");
        }
    }

    return 0;
}

int cart(char choice[])
{
    int cost=0;
    switch (choice[0])
    {
        case '1':
            cost=150;
            break;
        case '2':
            cost = 200;
            break;
        case '3':
            cost = 250;
            break;
        case '4':
            cost = 300;
            break;
    }
    return cost;
}
