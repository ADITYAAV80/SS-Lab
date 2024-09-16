/*
NAME:22.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM: 22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
DATE:16 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<fcntl.h>
int main() {

	fd_set readfds;
	struct timeval time;

	int ret = mkfifo("myfifo",0666);
	if(ret==-1){ perror("fifo"); }
	int fd = open("myfifo",O_RDONLY|O_NONBLOCK);

	FD_ZERO(&readfds);
	FD_SET(fd,&readfds);
	time.tv_sec = 10;
	time.tv_usec = 0; 
	ret = select(fd+1,&readfds,NULL,NULL,&time);
	if(ret==-1){
		perror("select");
	}
	else if (ret){
		printf("Input obtained within 10 seconds\n");
		exit(0);
	}
	else{
		printf("No input\n");
		exit(0);
	}
	close(fd);
	return 0;
}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg22$ ./22.out
fifo: File exists
Input obtained within 10 seconds
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg22$ ./22.out
fifo: File exists
No input

*/


