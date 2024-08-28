/*
NAME: 4.c
NAME: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
DATE: 9 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

	if (argc!=2){
		printf("Please enter file name in CLI\n");
		exit(0);
	}
	int ret = open(argv[1], O_CREAT | O_RDWR  | O_EXCL, 0700);
	if (ret != -1){
		printf("File opened successfully\n");
	}
	else{
		perror("file open error:");
		exit(0);
	}
	int c = close(ret);
	if (c!=-1){
		printf("File closed\n");
	}
	else{
		perror("file close error");
	}
}

/* OUTPUT

aditya@laptop:~/SS-Lab/pg4$ ./4.out
Please enter file name in CLI
file open error:: Bad address


aditya@laptop:~/SS-Lab/pg4$ ./4.out file.txt
File opened successfully
File closed

*/
