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

	char buf1[100];
	char buf2[100];
	int pipefds[2];

	if (pipe(pipefds) == -1){
		perror("pipe");
		exit(0);
	}
	printf("Please enter text to be passed into pipe: \n");
	scanf("%[^\n]",buf1);

	int w = write(pipefds[1],buf1,strlen(buf1));
	close(pipefds[1]);

	int r = read(pipefds[0],buf2,w);
	close(pipefds[0]);

	printf("Data which is being read from stdin : %s\n",buf2);

	return 0;
}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg14$ ./a.out
Please enter text to be passed into pipe: 
hello from the other side
Data which is being read from stdin : hello from the other side

*/
