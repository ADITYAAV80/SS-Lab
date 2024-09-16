/*
NAME:27b.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
27. Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
DATE: 16 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buf{

	long message_type;
	char m[100];

}msg;

int main() {

	int key = ftok("../.",1);
	int msg_queue = msgget(key, 0666 |IPC_CREAT);
	if( msg_queue == -1){
		perror("msgget");
		exit(0);
	}
	printf("Enter a message\n");

	msg.message_type = 1;
	fgets(msg.m,10,stdin);

	/* COMMENT AND UNCOMMENT THESE TWO LINES BELOW */

	int s = msgsnd(msg_queue,&msg,sizeof(msg),0);
	if(s == -1){ perror("msgsnd"); }

	int r = msgrcv(msg_queue,&msg,sizeof(msg),1,IPC_NOWAIT);
	if(r == -1){ perror("msgrcv"); }
	else{
		printf("Message recieved is %s\n",msg.m);
	}

}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg27$ ./27a.out
Enter a message
hello
Message recieved is hello

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg27$ ./27b.out
Enter a message
hello
msgrcv: No message of desired type


*/
