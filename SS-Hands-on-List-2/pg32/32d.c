/*
NAME:32d.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
DATE: 19 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/sem.h>
union semun {
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
};
int main() {

	key_t key = ftok(".", 1);
	if( key == -1){ perror("ftok");exit(0);}

	int semid = semget(key, 1, IPC_CREAT|0777);//no of semaphores = 1

        union semun arg;
	arg.val = 1;//binary semaphore

	int ret = semctl(semid,0,SETVAL,arg);
	if (ret != -1){
    		printf("Binary semaphore created and initialized with sem id %d\n",semid);
	}
	else{
		perror("semctl");
		exit(0);
	}
	system("ipcs -s");
	if (semctl(semid,0,IPC_RMID)==1){ perror("semctl");exit(0);}
	printf("Semaphore removed successfully\n");
	system("ipcs -s");
}

/* OUTPUT 

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg32$ ./32d.out
Binary semaphore created and initialized with sem id 3

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x010616bb 0          aditya     777        1         
0x0106b144 3          aditya     777        1         

Semaphore removed successfully

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x010616bb 0          aditya     777        1         



*/
