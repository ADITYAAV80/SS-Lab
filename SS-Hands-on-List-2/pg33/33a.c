/*
NAME:33a.c
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

    struct sockaddr_in address;
    int sock = 0;
    char *hello = "Hello from client";

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &address.sin_addr)  == -1) {
        printf("\Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) == -1) {
        printf("\nConnection Failed \n");
        return -1;
    }

    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

}
