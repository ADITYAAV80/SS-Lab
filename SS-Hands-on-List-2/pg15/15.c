/*
NAME: 15.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
15. Write a simple program to send some data from parent to the child proces
DATE: 08 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){

	int pipefds[2];
	pid_t x;

	if (pipe(pipefds)== -1){
		perror("pipe");
		exit(0);
	}
	if(fork()!=0){
		close(pipefds[0]);

		char bufw[100];
		printf("I am parent process please enter some data to send to child : \n");
		int r = read(0,bufw,sizeof(bufw));
		int w = write(pipefds[1],bufw,strlen(bufw));
		printf("Parent with PID %d sent the data with %d bytes\n",getpid(),w);

		close(pipefds[1]);

	}
	else{
		close(pipefds[1]);

		char bufr[100];
		int r = read(pipefds[0],bufr,sizeof(bufr)-1);
		if (r>0){
			bufr[r]='\n';
		}
		printf("Child with pid %d ppid %d finished reading %d bytes of data\n",getpid(),getppid(),r);
		printf("String specified by parent : %s\n",bufr);
		close(pipefds[0]);
	}
}

/* OUTPUT 

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg15$ ./15.out
I am parent process please enter some data to send to child : 
hello hello hello
Parent with PID 14865 sent the data with 18 bytes
Child with pid 14866 ppid 14865 finished reading 18 bytes of data
String specified by parent : hello hello hello


*/