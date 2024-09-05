/*
NAME: 21.c
AUTHOR: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
21. Write a program, call fork and print the parent and child process id.
DATE: 22 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[]){

	if(fork()){
		printf("PARENT PROCESS\n");
		printf("PID of parent ID : %d\n",getpid());
	}
	else{
		printf("CHILD PROCESS\n");
		printf("PID of child ID : %d\n",getpid());
		printf("PID of it's parent : %d\n",getppid());
	}
	return 0;
}

/* OUTPUT

1) Compile and execute : 21.c

aditya@laptop:~/SS-Lab/pg21$ ./21.out
PARENT PROCESS
PID of parent ID : 22940
CHILD PROCESS
PID of child ID : 22941
PID of it's parent : 22940

*/
