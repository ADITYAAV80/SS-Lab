/*
NAME: 10.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
DATE: 10 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main( int argc, char * argv[]){


	if (argc<=1){
		printf("Enter file name in CLI\n");
		exit(0);
	}

	int fd = open(argv[1], O_CREAT|O_RDWR, 0666);
	if (fd != -1){
		printf("File opened successfully with fd: %d\n",fd);
	}
	else{
		perror("File open error:");
	}
	char buf[10];
	printf("Enter text of 10 bytes : ");
	scanf("%s",buf);
	int w = write(fd,buf,10);
	if (w>=0){
		printf("%d bytes written\n",w);
	}
	else{
		perror("Write error:");
	}
	int offset = lseek(fd,10,SEEK_CUR);
	if (offset == (off_t)-1) {
       		perror("Error using lseek");
       		close(fd);
        	exit(EXIT_FAILURE);
   	} 
	else {
        	printf("lseek moved the file pointer to position: %d\n",offset);
    	}
	char buf2[10];
	printf("Enter second text of 10 bytes : ");
	scanf("%s",buf2);
	int ws = write(fd,buf2,10);
	if (ws>=0){
		printf("%d bytes written\n",ws);
	}
	else{
		perror("Write error:");
	}
	close(fd);
}

/* OUTPUT

1) Compile and run the file: 10.c
2) While executing mention file as a parameter: ./10.out [file_name]
3) After executing c file execute the following command: od -c [file_name]


aditya@laptop:~/SS-Lab/pg10$ ./10.out
Enter file name in CLI

aditya@laptop:~/SS-Lab/pg10$ ./10.out file.txt
File opened successfully with fd: 3
Enter text of 10 bytes : hello
10 bytes written
lseek moved the file pointer to position: 20
Enter second text of 10 bytes : world
10 bytes written

aditya@laptop:~/SS-Lab/pg10$ od -c file.txt
0000000   h   e   l   l   o  \0   1   O 277 177   h   e   l   l   o  \0
0000020  \0  \0  \0  \0   w   o   r   l   d  \0  \0  \0  \0  \0  \0  \0
0000040  \0  \0  \0
0000043

*/
