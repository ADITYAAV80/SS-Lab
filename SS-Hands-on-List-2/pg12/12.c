/*
NAME:12.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
DATE: 7 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>


int main(){

	pid_t pid;
	if (fork()==0){
		printf("Child process with ppid %d\n",getppid());
		kill(getppid(),SIGKILL);
		sleep(3);
		printf("Child process is orphan now with ppid : %d\n",getppid());
	}
	else{
		printf("Parent running\n");
		sleep(1);
		while(1){};
	}

}

/* OUTPUT

Parent running
Child process with ppid 39735
Killed
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg12$ Child process is orphan now with ppid : 1669

*/
