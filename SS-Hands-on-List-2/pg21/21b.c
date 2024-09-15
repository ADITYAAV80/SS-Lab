/*
NAME:21.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
21. Write two programs so that both can communicate by FIFO -Use two way communications.
DATE: 09 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	char buf1[500];

	int fd1 = open("myfifo1",O_WRONLY);
	int fd2 = open("myfifo2",O_RDONLY);
	if ( fd1 == -1 || fd2 == -1){
		perror("file opening");
		exit(0);
	}

	int r = read(fd1,buf1,sizeof(buf1));
	if (r == -1){ perror("read"); exit(0);}
	else{ printf("%d bytes read",r);}
	printf("The text from program 1 to program 2 is : %s\n",buf1);

	printf("Enter the text to send");
	char buf2[500];
	r = read(0,buf2,sizeof(buf2));
	if (r == -1){ perror("read"); exit(0);}

	int w = write(fd2,buf2,sizeof(buf2));
	if (w == -1){ perror("write"); exit(0);}

	close(fd1);
	close(fd2);

}
