/*
NAME:29.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
29. Write a program to remove the message queue.
DATE: 18 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(void) {
 
    int key = ftok(".", 1);
    if(key == -1) { perror("ftok");exit(0); }

    int msgid = msgget(key, 0666 | IPC_CREAT);
    if(msgid == -1) { perror("msgget");exit(0); }

    printf("Message queue id = %d\n", msgid);

    system("ipcs -q");

    int ctr = msgctl(msgid, IPC_RMID, NULL);
    if(ctr == -1) { perror("msgctl");exit(0); }

    printf("Message queue removed.\n");
}

/* OUTPUT

Message queue id = 5

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x0106164a 0          aditya     777        0            0           
0x01061a7a 1          aditya     666        0            0           
0x02061a7a 2          aditya     766        0            0           
0x010616bd 5          aditya     666        0            0           

Message queue removed.

*/
