/*
NAME:33b.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
33. Write a program to communicate between two machines using socket.
DATE: 20 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(0);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("bind failed");
        exit(0);
    }

    if (listen(server_fd, 3) == -1) {
        perror("listen");
        exit(0);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) == -1) {
        perror("accept");
        exit(0);
    }

    char buffer[1024] = {0};
    read(new_socket, buffer, sizeof(buffer));
    printf("Received message: %s\n", buffer);

}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg33$ ./33b.out
Received message: Hello from client

*/
