/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[]){

	if(fork()==0){
		printf("Child process started\n");
		printf("Child process executing now but parent is in sleep state it's a zombie\n");
		printf("Child process exiting with pid %d and it's parent %d\n",getpid(),getppid());
		exit(0);

	}
	else{
		printf("Parent process running with pid %d\n",getpid());
		printf("Exiting parent process but with sleep and wait system call\n");
		sleep(50);
		wait(0);
		printf("Parent actually exited Now\n");

	}
}
