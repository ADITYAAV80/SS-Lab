/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main( int argc, char *argv[]){

	int fd = open(argv[1],O_CREAT| O_RDWR);
	if(fd!=-1){
		printf("File opened successfully\n");
	}
	else{
		perror("Error opening file");
	}
	struct flock l;
	l.l_type = F_RDLCK;
	l.l_whence = SEEK_SET;
	l.l_start = 0;
	l.l_len = 0;

	if (fcntl(fd,F_SETLKW,&l)==-1){
		printf("Read lock failed to acquire\n");
		perror("");
	}
	else{
		printf("Read lock successfully acquired\n");
	}

	printf("Press enter to release it\n");
	getchar();
	
	l.l_type= F_UNLCK;
	if (fcntl(fd,F_SETLKW,&l)==-1){
		printf("Read lock release fail\n");
		perror("");
	}
	else{
		printf("Read lock released successfully\n");
	}

	l.l_type= F_WRLCK;
	if (fcntl(fd,F_SETLKW,&l)==-1){
		printf("Write lock failed to acquire\n");
		perror("");
	}
	else{
		printf("Write lock successfully acquired\n");
	}
	
	printf("Press enter to release it\n");
	getchar();
	getchar();
	l.l_type= F_UNLCK;
	if (fcntl(fd,F_SETLKW,&l)==-1){
		printf("Write lock release fail\n");
		perror("");
	}
	else{
		printf("Write lock released successfully\n");
	}

}
