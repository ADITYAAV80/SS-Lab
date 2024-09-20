/*
NAME:34a2.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
34. Write a program to create a concurrent server.
a. use fork
b. use pthread_create
DATE: 20 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating client socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("connect");
        exit(0);
    }

    const char* message = "Hello from the client";
    send(client_socket, message, strlen(message), 0);

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Received message: %s\n", buffer);

    close(client_socket);
    return 0;
}
