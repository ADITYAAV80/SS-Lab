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

	if(access("myfifo1",F_OK) == -1){
		int m1 = mkfifo("myfifo1",0666);
		if ( m1 == -1){
			perror("mkfifo");
			exit(0);
		}
	}
	if(access("myfifo2",F_OK) == -1){
		int m2 = mkfifo("myfifo2",0666);
		if ( m2 == -1){
			perror("mkfifo");
			exit(0);
		}
	}

	char buf1[500];
	printf("Enter the text to be read\n");
	scanf("%[^\n]",buf1);
	printf("Data read successfully\n");

	int fd1 = open("myfifo1",O_WRONLY);
	int fd2 = open("myfifo2",O_RDONLY);
	if ( fd1 == -1 || fd2 == -1){
		perror("file opening");
		exit(0);
	}

	int w = write(fd1,buf1,sizeof(buf1));
	printf("myfifo wrote %d bytes to buf1\n",w);
	if (w == -1){ perror("write"); exit(0);}


	char buf2[500];
	int r = read(fd2,buf2,sizeof(buf2)-1);
	if (r == -1){ perror("read"); exit(0);}

	buf2[r]='\n';
	printf("The text from program 2 to program 2 is : %s\n",buf2);
	close(fd1);
	close(fd2);

}
