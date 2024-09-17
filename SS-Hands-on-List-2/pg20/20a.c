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

	int ret = mkfifo(path,0666);
	if (ret == -1){ perror("mkfifo");}

	char buf[500];
	printf("Data to be sent from a to b:\n");
	scanf("%[^\n]",buf);


	int fd = open(path, O_WRONLY);
	if (fd == -1){ perror("open"); exit(0);}

	int w = write(fd,buf,strlen(buf));
	if (w == -1){ perror("write"); exit(0);}
	else{ printf("no of bytes written %d\n",w);}
	close(fd);
}

/* OUTPUT

Terminal 1:
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg20$ ./a.out
Data to be sent from a to b:
hello from the other side

Terminal 2:
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg20$ ./a.out
No of bytes read from a : 26
hello from the other side

Terminal 1:
no of bytes read 26
no of bytes written 26

*/
