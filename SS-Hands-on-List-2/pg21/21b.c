/*
NAME:21b.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
21. Write two programs so that both can communicate by FIFO -Use two way communications.
DATE: 09 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	char buf3[500],buf4[500];

	printf("Enter the text to send\n");
	scanf("%[^\n]",buf4);

	int fd1 = open("myfifo1",O_RDONLY);
	int fd2 = open("myfifo2",O_WRONLY);
	if ( fd1 == -1 || fd2 == -1){
		perror("file opening");
		exit(0);
	}

	int r = read(fd1,buf3,sizeof(buf3));
	if (r == -1){ perror("read"); exit(0);}
	printf("The text from program 1 to program 2 is : %s\n",buf3);

	int w = write(fd2,buf4,sizeof(buf4));
	if (w == -1){ perror("write"); exit(0);}

}
