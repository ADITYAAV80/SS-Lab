/*
NAME: 23.c
NAME: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
23. Write a program to create a Zombie state of the running program.
DATE: 22 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
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

/* OUTPUT


1) Compile and run : 23.c
2) Open new terminal and execute top command and press o to filter:PID=[pid of child process]
3) Notice in State column the child process in zombie

aditya@laptop:~/SS-Lab/pg23$ ./23.out
Parent process running with pid 24198
Exiting parent process but with sleep and wait system call
Child process started
Child process executing now but parent is in sleep state it's a zombie
Child process exiting with pid 24199 and it's parent 24198
Parent actually exited Now

*/
