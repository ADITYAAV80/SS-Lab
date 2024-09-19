/*
NAME:28.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
28. Write a program to change the exiting message queue 
permission. (use msqid_ds structure)
DATE: 18 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>


int main(void) {

	int key = ftok(".", 2);
	if(key == -1) { perror("ftok");exit(0); }

	int msg_id = msgget(key, 0777 | IPC_CREAT);
	if(msg_id == -1) { perror("msgget");exit(0); }

	struct msqid_ds msg_ds;
	int t = msgctl(msg_id, IPC_STAT, &msg_ds);
	if(t == -1) { perror("msgctl");exit(0); }

	printf("The current permission is: %o\n", msg_ds.msg_perm.mode);
	msg_ds.msg_perm.mode = 0766;

	t = msgctl(msg_id, IPC_SET, &msg_ds);
	if(t == -1) { perror("msgctl");exit(0); }

	printf("The permission changed to %o\n", msg_ds.msg_perm.mode);

}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg28$ ./28.out
The current permission is: 777
The permission changed to 766

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg28$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x0106164a 0          aditya     777        0            0           
0x01061a7a 1          aditya     666        0            0           
0x02061a7a 2          aditya     766        0            0           

*/
