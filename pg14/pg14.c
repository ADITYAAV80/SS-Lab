/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(int argc, char *argv[]){

	if(argc!=2){
		printf("Please enter argument\n");
		return -1;
	}
	struct stat fileinfo;
	if ( stat(argv[1],&fileinfo) >= 0){
		printf("Values assigned successfully\n");
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
