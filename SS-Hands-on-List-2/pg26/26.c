/*
NAME:26.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
26. Write a program to send messages to the message queue. Check $ipcs -q
DATE:16 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdlib.h>

struct buffer{
	long message_type;
	char m[100];
}msg;

int main() {

	int key = ftok(".",1);
	int msg_queue = msgget(key, 0666 | IPC_CREAT);
	if (msg_queue == -1){
		perror("msgget");
	}
	printf("message queue id : %d\n",msg_queue);
	msg.message_type = 1;
	fgets(msg.m, 10 ,stdin);
	int ms = msgsnd(msg_queue,&msg,sizeof(msg),0);
	if(ms == -1){
		perror("msgsend");
		exit(0);
	}
	printf("Data sent to message queue\n");

}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg26$ ./a.out
message queue id : 5
Let's store message in queue
Data sent to message queue
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg26$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x0106164a 0          aditya     777        0            0           
0x0106041f 1          aditya     777        0            0           
0x0306041f 2          aditya     777        0            0           
0x01061a6e 3          aditya     777        0            0           
0x01061a72 5          aditya     666        112          1           

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg26$ ./a.out
message queue id : 5
hello
Data sent to message queue
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg26$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x0106164a 0          aditya     777        0            0           
0x0106041f 1          aditya     777        0            0           
0x0306041f 2          aditya     777        0            0           
0x01061a6e 3          aditya     777        0            0           
0x01061a72 5          aditya     666        224          2      

*/
