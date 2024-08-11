/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char * argv[]){

	int fd = open( argv[1], O_CREAT, 0666);
	if (fd != -1){
		printf("File created successfully with fd : %d\n",fd);
	}
	else{
		perror("Error");
	}
	int fd_dup = dup(fd);
	int fd_dup2 = dup2(fd,1000);
	printf("fd of dup : %d\n",fd_dup);
	printf("fd of dup2 : %d\n",fd_dup2);

	int fd_fcntl = fcntl(fd,F_DUPFD);
	printf("fd of fcntl : %d\n",fd_fcntl);

}
