/*
NAME:21a.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
21. Write two programs so that both can communicate by FIFO -Use two way communications.
DATE: 09 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	int m1 = mkfifo("myfifo1",0777);
	int m2 = mkfifo("myfifo2",0777);
	if ( m1 == -1 || m2 == -1){
		perror("mkfifo");
	}

	char buf1[500];
	printf("Enter the text to be read\n");
	scanf("%[^\n]",buf1);

	int fd1 = open("myfifo1",O_WRONLY);
	int fd2 = open("myfifo2",O_RDONLY);
	if ( fd1 == -1 || fd2 == -1){
		perror("file opening");
		exit(0);
	}

	int w = write(fd1,buf1,sizeof(buf1));
	if (w == -1){ perror("write"); exit(0);}


	char buf2[500];
	int r = read(fd2,buf2,sizeof(buf2));
	if (r == -1){ perror("read"); exit(0);}

	printf("The text from program 2 to program 1 is : %s\n",buf2);

}

/* OUTPUT

TERMINAL -1

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg21$ ./21a.out
mkfifo: File exists
Enter the text to be read
hello 
The text from program 2 to program 1 is : goodbye

TERMINAL -2

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg21$ ./21b.out
Enter the text to send
goodbye
The text from program 1 to program 2 is : hello

*/
