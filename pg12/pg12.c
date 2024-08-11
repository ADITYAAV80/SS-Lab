/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
12. Write a program to find out the opening mode of a file. Use fcntl.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main( int argc, char * argv[]){

	int fd = open ( argv[1], O_CREAT, 0666);
	if (fd != -1){
		printf("File created successfully with fd: %d\n",fd);
	}
	else{
		perror("error");
	}
	int x = fcntl(fd,F_GETFL);
	if ( x = 32768){
		printf("File opening mode : O_RDONLY\n");
	}
	else if ( x = 32769){
		printf("File opening mode : O_WRONLY\n");
	}
	else{
		printf("File opening mode : O_RDWR\n");
	}
} 
