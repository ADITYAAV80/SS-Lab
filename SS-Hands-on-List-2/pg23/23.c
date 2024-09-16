/*
NAME:23.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:23. Write a program to print the maximum number of files can be opened 
within a process and size of a pipe (circular buffer).
DATE:24 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>

int main(void) {

	if(mkfifo("myfifo",S_IRWXU)==-1){
		perror("Fifo");
	}

	long nooffiles = sysconf(_SC_OPEN_MAX);
	if (nooffiles == -1){
		perror("Sysconf");
	}

	printf("Max files that can be open = %ld\n",nooffiles);

	long sizeofpipe = pathconf("myfifo", _PC_PIPE_BUF);
	if ( sizeofpipe == -1){
		perror("Pathconf");
	}

	printf("Max size of pipe (circular buffer) = %ld\n",sizeofpipe);
	return 0;

}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg23$ ./a.out
Max files that can be open = 1024
Max size of pipe (circular buffer) = 4096

*/
