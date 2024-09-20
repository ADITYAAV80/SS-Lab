/*
NAME:32a.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
DATE: 18 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<sys/sem.h>
#include<fcntl.h>
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

	if(semctl(semid,0,SETVAL,arg) == -1 && errno !=EEXIST){
		perror("semctl");
		exit(0);
	}

	int fd = open("records.txt",O_RDWR);
	if (fd == -1) { perror("open");exit(0);}

	struct sembuf lck = {0,-1,0};

	if (semop(semid,&lck,1) == -1){
		perror("semop-lck");
		exit(0);
	}

	printf("\n\n\nRecords locked for writing [In critical section]\n");

	int val;
	int r = read(fd,&val,sizeof(val));
	if (r == -1){ perror("read");exit(0);}

	printf(" You are looking at ticket no: %d\n",val);
	val+=1;
	printf(" Updated ticket no %d\n",val);
	lseek(fd,0,SEEK_SET);
	write(fd,&val,sizeof(val));

	printf("--------Press enter to exit--------\n");
	getchar();
	lck.sem_op = 1;
	if (semop(semid,&lck,1) == -1){
		perror("semop");
		exit(0);
	}
	close(fd);

}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg31$ ./31a.out
Binary semaphore created and initialized.

*/
