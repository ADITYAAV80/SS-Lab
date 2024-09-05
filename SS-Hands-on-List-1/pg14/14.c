/*
NAME: 14.c
AUTHOR: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
DATE: 11 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

	if(argc!=2){
		printf("Please enter argument\n");
		exit(0);
	}
	struct stat fileinfo;
	if ( lstat(argv[1],&fileinfo) >= 0){
		printf("Lstat values assigned successfully\n");
	}
	int mode = fileinfo.st_mode;
	if (S_ISREG(mode)){
		printf("Regular File\n");
	}
	else if(S_ISDIR(mode)){
      		printf("Directory\n");
   	}
   	else if(S_ISFIFO(mode)){
     		printf("FIFO Named pipe\n");
   	}
   	else if(S_ISLNK(mode)){
     		printf("Symbolic Link\n");
   	}
   	else if(S_ISBLK(mode)){
     		printf("Block Special File\n");
   	}
   	else if(S_ISCHR(mode)){
     		printf("Character special file\n");
   	}
}

/* OUTPUT


1) Compile and execute the file: 14.c
2) Provide argument to command line during excecution:./14.out [file/link/directory/pipe/special file(block & character)

aditya@laptop:~/SS-Lab/pg14$ ./14.out
Please enter argument

aditya@laptop:~/SS-Lab/pg14$ ./14.out fifotest 
Lstat values assigned successfully
FIFO Named pipe

aditya@laptop:~/SS-Lab/pg14$ ./14.out 14.c
Lstat values assigned successfully
Regular File

aditya@laptop:~/SS-Lab/pg14$ ./14.out test
Lstat values assigned successfully
Directory

aditya@laptop:~/SS-Lab/pg14$ ./14.out softlinktodemo
Lstat values assigned successfully
Symbolic Link

aditya@laptop:~/SS-Lab/pg14$ ./14.out hardlinktodemo 
Lstat values assigned successfully
Regular File

aditya@laptop:~/SS-Lab/pg14$ ./14.out /dev/nvme0
Lstat values assigned successfully
Character special file

aditya@laptop:~/SS-Lab/pg14$ ./14.out /dev/nvme0n1
Lstat values assigned successfully
Block Special File

*/
