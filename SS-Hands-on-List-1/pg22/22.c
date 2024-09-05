/*
NAME: 22.c
NAME: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
DATE: 22 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc,char *argv[]){

	if ( argc!=2){
		printf("Please enter file name");
		exit(0);
	}
	int fd = open(argv[1], O_CREAT | O_RDWR);
	if (fd!=-1){
		printf("The file is opened with fd:%d\n",fd);
	}
	else{
		perror("Error opening file");
	}
	if(!fork()){

		int fd_dup = dup(fd);
		char buffer[] = "Hi, I am a child process writing to a file\n";
		int w = write(fd_dup,buffer,sizeof(buffer));
		if (w <0){
			perror("Child process couldn't write to a file");
		}
		if(close(fd_dup)<0){
			perror("Error closing file");
		}
	}
	else{

		char buffer[] = "Hi, I am a parent process writing to a file\n";
		int w = write(fd,buffer,sizeof(buffer));
		if (w <0){
			perror("Parent process couldn't write to a file");
		}
		wait(0);
		if(close(fd)<0){
			perror("Error closing file");
		}
	}
	return 0;
}

/* OUTPUT

1) Compile and execute the file:22.c

aditya@laptop:~/SS-Lab/pg22$ ./22.out file.txt
The file is opened with fd:3

aditya@laptop:~/SS-Lab/pg22$ cat file.txt
Hi, I am a parent process writing to a file
Hi, I am a child process writing to a file

*/
