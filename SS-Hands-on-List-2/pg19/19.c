/*
NAME:19.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
DATE:

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(){

	int ret = mknod("mknod_fifo", S_IFIFO| 0666, 0);
	if (ret==-1){
		perror("mknod");
		exit(0);
	}
	ret = mkfifo("mkfifo_fifo", 0666);
	if (ret==-1){
		perror("mkfifo");
		exit(0);
	}

}
