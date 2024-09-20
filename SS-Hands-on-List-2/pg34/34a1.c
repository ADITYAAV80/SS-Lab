/*
NAME:34a1.c
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

void handle_client(int client_socket) {
 
    //store buffer information
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    //recieve messages from client
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Received message: %s\n", buffer);
    //send message to client
    const char* response = "Hello from the server!";
    send(client_socket, response, strlen(response), 0);
    //to avoid TIME_WAIT
    close(client_socket);
}

int main() {

    //creates a socket end point and returns the file descriptor
    //socket uses TCP and communication over network
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        perror("socket");
        exit(0);
    }

    //sets sender ip address to same machine
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //updates the socket options common across both TCP and UDP allows reuse of local address and opt enables the option
    //it'll not wait till TIME_WAIT expires
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsocketopt");
        exit(0);
    }

    //binds socket to server
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(0);
    }

    //listens to messages from client with max backlog 5 to be present in queue data structure
    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(0);
    }

    while (1) {

	//keep accepting new connection and if it's successful then start creating new children to handle further new connections
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            exit(1);
        }

	//creating children for concurrent servers
        if (fork() == 0) {
	    //only parent is supposed to listen to new connection the child should focus on sending and receving messages
            close(server_socket);
            handle_client(client_socket);
            exit(0);
        } else {
	    //parent doesn't need to interact with new client
            close(client_socket);
        }
    }
    //should avoid being in time wait state
    close(server_socket);
    return 0;
}

/* OUTPUT


CLIENT
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg34$ ./34a2.out
Received message: Hello from the server!
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg34$ cc 34a2.c -o 34a2.out
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg34$ ./34a2.out
Received message: Hello from the server!
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg34$ ./34a2.out
Received message: Hello from the server!
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg34$ ./34a2.out
Received message: Hello from the server!
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg34$ ./34a2.out
Received message: Hello from the server!

SERVER
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg34$ ./34a1.out
Received message: Hello from the client
Received message: Hello from the client
Received message: Hello from the client
Received message: Hello from the client
Received message: Hello from the client
^C

*/
