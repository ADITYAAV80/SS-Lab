/*
NAME:20.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
20. Write two programs so that both can communicate by FIFO -Use one way communication.
DATE: SEP 8 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main(){

	const char *path = "myfifo";

	int fd = open(path, O_RDONLY);

	char buf[500];
	int r = read(fd,buf,sizeof(buf));
	printf("No of bytes read from a : %d\n",r);
	printf("%s",buf);
}
