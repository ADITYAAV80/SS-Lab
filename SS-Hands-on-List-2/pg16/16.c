/*
NAME:16.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.
DATE: SEP 8 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){

	int pipefdspc[2];
	int pipefdscp[2];
	if (pipe(pipefdspc) == -1 || pipe(pipefdscp) == -1){
		perror("pipe");
		exit(0);
	}
	if (fork()!=0){

		close(pipefdspc[0]);
		close(pipefdscp[1]);

		char *pbuf = "Hello from the parent side\n";
		int w = write(pipefdspc[1],&pbuf,sizeof(pbuf));
		if (w==-1){ perror("write");exit(0);}

		char *cbuf;
		int r = read(pipefdscp[0],&cbuf,sizeof(cbuf));
		if (r==-1){ perror("read");exit(0);}

		printf("Parent with pid %d reads :: %s\n",getpid(),cbuf);

		close(pipefdspc[1]);
		close(pipefdscp[0]);

		wait(0);

	}
	else{

		close(pipefdspc[1]);
		close(pipefdscp[0]);

		char *cbuf = "Hello from the child side\n";
		int w = write(pipefdscp[1],&cbuf,sizeof(cbuf));
		if (w==-1){ perror("write");exit(0);}


		char *pbuf;
		int r = read(pipefdspc[0],&pbuf,sizeof(pbuf));
		if (r==-1){ perror("read");exit(0);}


		printf("Child with pid %d and parent pid %d reads :: %s\n",getpid(),getppid(),pbuf);

		close(pipefdspc[0]);
		close(pipefdscp[1]);

	}
}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg16$ ./a.out
Parent with pid 15477 reads :: Hello from the child side

Child with pid 15478 and parent pid 15477 reads :: Hello from the parent side


		(A) fdpc[1]--------|--|  |--------fdpc[1] (A)
    parent	(X) fdpc[0]--------|  |->|--------fdpc[0] (X)  child

		(A) fdcp[0]--------|<-|  |--------fdcp[0] (X)
		(X) fdcp[1]--------|  |--|--------fdcp[1] (A)
*/
