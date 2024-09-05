/*
NAME: 16.c
NAME: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
DATE: 17 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main( int argc, char *argv[]){

	if (argc!=2){
		printf("PLease enter file name in CLI\n");
		exit(0);
	}
	int fd = open(argv[1],O_CREAT| O_RDWR);
	if(fd!=-1){
		printf("File opened successfully\n");
	}
	else{
		perror("Error opening file");
	}
	struct flock l;
	l.l_type = F_RDLCK;
	l.l_whence = SEEK_SET;
	l.l_start = 0;
	l.l_len = 0;

	if (fcntl(fd,F_SETLKW,&l)==-1){
		printf("Read lock failed to acquire\n");
		perror("");
	}
	else{
		printf("Read lock successfully acquired\n");
	}

	printf("Press enter to release it\n");
	getchar();
	l.l_type= F_UNLCK;
	if (fcntl(fd,F_SETLKW,&l)==-1){
		printf("Read lock release fail\n");
		perror("");
	}
	else{
		printf("Read lock released successfully\n");
	}

	l.l_type= F_WRLCK;
	if (fcntl(fd,F_SETLKW,&l)==-1){
		printf("Write lock failed to acquire\n");
		perror("");
	}
	else{
		printf("Write lock successfully acquired\n");
	}

	printf("Press enter to release it\n");
	getchar();
	l.l_type= F_UNLCK;
	if (fcntl(fd,F_SETLKW,&l)==-1){
		printf("Write lock release fail\n");
		perror("");
	}
	else{
		printf("Write lock released successfully\n");
	}

}

/* OUTPUT

A:In terminal 1
1) Compile and excecute the file : 16.c
2) The resource 1 acquires read lock

B:In terminal 2
1) Go to same location
2) Execute the file : 16.out
3) The resource 2 acquires read lock

C:In terminal 1
1) Press enter to release read lock
2) Notice here the write lock is not acquired by resource 1

D:In terminal 2
1) Press enter to release read lock
2) Since read lock, is released from both the resources it immediatedly acquires write lock
3) Press enter to release write lock from resource 2

E:In terminal 1
1) Resource 1 acquires write lock since no other resources are locking the files
2) Press enter to release write lock in resource 1

TERMINAL 1:

aditya@laptop:~/SS-Lab/pg16$ ./16.out file.txt
File opened successfully
Read lock successfully acquired
Press enter to release it 

Read lock released successfully
Write lock successfully acquired
Press enter to release it

Write lock released successfully

TERMINAL 2:
aditya@laptop:~/SS-Lab/pg16$ ./16.out file.txt
File opened successfully
Read lock successfully acquired
Press enter to release it

Read lock released successfully
Write lock successfully acquired
Press enter to release it

Write lock released successfully
*/
