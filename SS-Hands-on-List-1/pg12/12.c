/*
NAME: 12.c
NAME: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
12. Write a program to find out the opening mode of a file. Use fcntl.
DATE: 11 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main( int argc, char * argv[]){

	if (argc!=2){
		printf("Please enter file name in CLI\n");
		exit(0);
	}
	int fd = open ( argv[1], O_CREAT | O_RDWR);
	if (fd != -1){
		printf("File created successfully with fd: %d\n",fd);
	}
	else{
		perror("Error:");
	}
	int x = fcntl(fd,F_GETFL);
	if ( x == 32768){
		printf("File opening mode : O_RDONLY\n");
	}
	else if ( x == 32769){
		printf("File opening mode : O_WRONLY\n");
	}
	else{
		printf("File opening mode : O_RDWR\n");
	}
}

/* OUTPUT


1) Compile and execute the program: 12.c
2) While executing specify file name as command line argument: ./12.out [file_name]
3) Change arguments to open function to see different outputs

aditya@laptop:~/SS-Lab/pg12$ ./12.out
Please enter file name in CLI

aditya@laptop:~/SS-Lab/pg12$ ./12.out file.txt
File created successfully with fd: 3
File opening mode : O_RDWR

*/
