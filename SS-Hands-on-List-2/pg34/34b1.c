/*
NAME:34b1.c
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
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void* handle_client(void* arg) {

    int client_socket = *((int*)arg);
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Received message: %s\n", buffer);

    const char* response = "Hello from the server!";
    send(client_socket, response, strlen(response), 0);

    close(client_socket);
    pthread_exit(NULL);
}

int main() {

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(0);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsocketopt");
        exit(0);
    }

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(0);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(0);
    }

    while (1) {

	//almost everything is same except this because this
	//ensures pointer is valid even after main thread continues 
        //executing or else it may pass the previous pointer 
	//leading to upreditable behaviour
        int* client_socket = malloc(sizeof(int));
        *client_socket = accept(server_socket, NULL, NULL);
        if (*client_socket == -1) {
            perror("accept");
            exit(0);
        }

        pthread_t tid;
	//creating lwp using pthread_create instead of creating child processess
        if (pthread_create(&tid, NULL, handle_client, client_socket) != 0) {
            perror("pthread_create");
            exit(0);
        }
	//don't wait till for other thread to finish 
	//clean up resources by self and move on
        pthread_detach(tid);
    }

    close(server_socket);
}
