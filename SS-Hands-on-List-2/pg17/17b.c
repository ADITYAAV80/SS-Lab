/*
NAME:17b.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
17. Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
DATE: 08 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

	int pipefds[2];

	if (pipe(pipefds)==-1){
		perror("pipe");
		exit(0);
	}

	if (!fork()){

		close(pipefds[0]);
		dup2(pipefds[1],1);
		char *args[] = {"ls","-l",NULL};
		execv("/bin/ls",args);
		close(pipefds[1]);
		wait(0);
	}
	else{

		close(pipefds[1]);
		dup2(pipefds[0],0);
		char *args[] = {"wc",NULL};
		execv("/bin/wc",args);
		close(pipefds[0]);

	}
}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg17$ ./17b.out
      5      38     221

*/
