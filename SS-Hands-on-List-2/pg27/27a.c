/*
NAME:27a.c
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

	/*----COMMENT BELOW TWO LINES TO SEE DIFFERENCE B/W 0 AND IPCNOWAIT---*/
/*	int s = msgsnd(msg_queue,&msg,sizeof(msg),0);
	if(s == -1){ perror("msgrcv"); }
*/
	int r = msgrcv(msg_queue,&msg,sizeof(msg),1,0);
	if(r == -1){ perror("msgrcv"); }
	else{
		printf("Message recieved is %s\n",msg.m);
	}
}

/* OUTPUT

WITHOUT COMMENT 

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg27$ cc 27a.c -o 27a.out 
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg27$ sudo nano 27a.c
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg27$ cc 27a.c -o 27a.out
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg27$ ./27a.out
Enter a message
hello
Message recieved is hello

WITH COMMENT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg27$ sudo nano 27a.c
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg27$ cc 27a.c -o 27a.out
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg27$ ./27a.out
Enter a message
hello




^C

*/
