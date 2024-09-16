/*
NAME:24.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:24. Write a program to create a message queue and print the 
key and message queue id.
DATE: 16 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

int main(void) {

	int msg_queue =ftok("../.",3);
	if (msg_queue == -1){
		perror("Error");
		return 0;
	}

	int que = msgget(msg_queue, IPC_CREAT |0777);
	if(que ==-1){
		perror("msgget");
		return 0;
	}

	printf("Key: %d\n", msg_queue);
	printf("Message Queue ID: %d\n",que);
}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg24$ ./a.out
Key: 17176138
Message Queue ID: 0

CHANGING DIRECTORY IN FTOK CHANGES HASH VALUE

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg24$ sudo nano 24.c
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg24$ cc 24.c
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg24$ ./a.out
Key: 17171487
Message Queue ID: 1

CHANGING PROJ_ID BUT KEEPING SAME DIRECTORY

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg24$ ./a.out
Key: 50725919
Message Queue ID: 2

*/
