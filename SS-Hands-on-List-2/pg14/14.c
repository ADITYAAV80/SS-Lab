/*
NAME:14.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
DATE: 07 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


int main(){

	char buf[100];
	char buf1[100];
	int pipefds[2];

	if (pipe(pipefds) == -1){
		perror("pipe");
		exit(0);
	}
	printf("Please enter text to be passed into pipe: \n");
	int r = read(0,buf1,sizeof(buf1));

	write(pipefds[1],buf1,r);
	read(pipefds[0],buf,r);
	printf("Data which is being read from stdin : %s\n",buf);

	close(pipefds[0]);
	close(pipefds[1]);
	return 0;
}
